import sys
import re
import zlib
import ast
import zipfile

roms = []
for n in sys.argv[2:]:
    with open(n,"rb") as rom:
        data = rom.read()
        roms.append((n,zlib.crc32(data),data))
        
with open(sys.argv[1],"r") as xml:
    def get(s,line):
        return re.search(s+r'=[\"\'](.*?)[\"\']', line).group(1)

    for line in xml:
        line = line.strip()
        if line.startswith('<game ') or line.startswith('<machine '):
            zipname = get('name',line)+'.zip'
            print(zipname)
            break
            
    with zipfile.ZipFile(zipname, "w") as z:
        for line in xml:
            line = line.strip()
            if line.startswith('<rom '):
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
            
            
                
