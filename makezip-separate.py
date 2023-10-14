import sys
import re
import zlib
import ast
import zipfile
import os

if len(sys.argv)<3:
    print("python3 makezip-separate.py [-o outdir] [-a] game.xml|game.c inputfiles ...")
    print(" -a : adds to zip")
    sys.exit(1)

outdir = ""
add = False

while True:
    if sys.argv[1] == '-o':
        outdir = sys.argv[2]
        sys.argv = sys.argv[2:]
        continue
    if sys.argv[1] == '-a':
        add = True
        sys.argv = sys.argv[1:]
        continue
    break

roms = []
for n in sys.argv[2:]:
    with open(n,"rb") as rom:
        data = rom.read()
        roms.append((n,zlib.crc32(data),data))
        
with open(sys.argv[1],"r") as xml:
    def get(s,line):
        if xmlMode:
            return re.search(s+r'=[\"\'](.*?)[\"\']', line).group(1)
        else:
            if s == 'name' and line.startswith('ROM_START'):
                return re.search(r'\(\s*(.*?)\s*\)',line).group(1)
            lineData = re.search(r'\((.*)\)',line).group(1).split(',')
            lineData = tuple((x.strip() for x in lineData))
            if s == 'name':
                return lineData[0].replace('"','')
            elif s == 'size':
                return ast.literal_eval(lineData[2])
            elif s == 'crc':
                return re.search(r'CRC\s*\(([a-fA-F0-9]+)', lineData[3]).group(1)

    for line in xml:
        line = line.strip()
        xmlMode = line.startswith('<game ') or line.startswith('<machine ')
        cMode = line.startswith('ROM_START')
        if xmlMode or cMode:
            zipname = os.path.join(outdir,get('name',line)+'.zip')
            print(zipname)
            break
            
    with zipfile.ZipFile(zipname, "a" if add else "w") as z:
        for line in xml:
            line = line.strip()
            if line.startswith('<rom ') or line.startswith('ROM_LOAD'):
                name = get('name',line)
                crc = int(get('crc',line),16)
                size = int(get('size',line))
                forcing = False
                for n,c,data in roms:
                    if ( crc & 0xFFFFFFFF ) == (c & 0xFFFFFFFF):
                        print("%s -> %s" % (n,name))
                        z.writestr(name, data)
                        break
                else:
                    print("not found %s %08x" % (name,crc))
            
            
                
