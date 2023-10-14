import sys
import re
import zlib
import ast
import zipfile
import os

if len(sys.argv)<3:
    print("python3 makezip.py [-o outdir] [-a] game.rom game.xml|game.c [romname1 offset1 ...]")
    print(" -a   : adds to zip")
    print(" -s N : bytes to skip when scanning: should be a power of 2; larger is faster, but might miss things; default: 0x10")
    print(" romname1 offset1: if romname1 can't be found in game.rom, force it to be at offset1")
    print(" offsets are of the form: N[x2][h|l]")
    print(" where N is a number (e.g., 16 or 0x10)")
    print(" and x2 indicates that we grab the data interleaving every second byte")
    print(" and h (l) indicates that we get the high (low) nibbles only")
    sys.exit(1)
    
NIBBLE_LOW = 1
NIBBLE_HIGH = 2
FULL_BYTE = 0
MODES = (lambda x:x, lambda x:x&0xf, lambda x:x>>4)

outdir = ""
add = False
slow = False
skip = 0x10

while True:
    if sys.argv[1] == '-o':
        outdir = sys.argv[2]
        sys.argv = sys.argv[2:]
        continue
    if sys.argv[1] == '-a':
        add = True
        sys.argv = sys.argv[1:]
        continue
    if sys.argv[1] == '-s':
        skip = ast.literal_eval(sys.argv[2])
        sys.argv = sys.argv[2:]
        continue
    break
    
force = []
for i in range(3,len(sys.argv),2):
    nib = FULL_BYTE
    if sys.argv[i+1].endswith('l'):
        nib = NIBBLE_LOW
        sys.argv[i+1] = sys.argv[i+1][:-1]
    elif sys.argv[i+1].endswith('h'):
        nib = NIBBLE_HIGH
        sys.argv[i+1] = sys.argv[i+1][:-1]
    if sys.argv[i+1].endswith('x2') and sys.argv[i+1] != '0x2':
        spacing = 2
        sys.argv[i+1] = sys.argv[i+1][:-2]
    else:
        spacing = 1
    force.append((sys.argv[i],ast.literal_eval(sys.argv[i+1]),spacing,nib))

with open(sys.argv[1],"rb") as rom:
    data = rom.read()
    
with open(sys.argv[2],"r") as xml:
    xmlMode = False
    cMode = False
    
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
            
    with zipfile.ZipFile(zipname, "w" if not add else "a") as z:
        for line in xml:
            line = line.strip()
            if line.startswith('<rom ') or line.startswith('ROM_LOAD'):
                name = get('name',line)
                crc = int(get('crc',line),16)
                size = int(get('size',line))
                if size > len(data):
                    print("does not fit!")
                forcing = False
                spacing = 1
                offset = None
                for j in range(len(MODES)):
                    for i in range(0,len(data)-size+1,skip):
                        c = zlib.crc32(bytes(map(MODES[j],data[i:i+size])))
                        if ( crc & 0xFFFFFFFF ) == (c & 0xFFFFFFFF):
                            offset = i
                            mode = j
                            break
                    if offset is not None:
                        break
                else:
                    if skip <= 2:
                        r = range(0,len(data)-2*size+1,1)
                    else:
                        r = tuple(range(0,len(data)-2*size+1,skip))+tuple(range(1,len(data)-2*size+1,skip))
                    for i in r:
                        c = zlib.crc32(data[i:i+2*size:2])
                        if ( crc & 0xFFFFFFFF ) == (c & 0xFFFFFFFF):
                            offset = i
                            spacing = 2
                            mode = FULL_BYTE
                            break
                    else:
                        for n,i,s,m in force:
                            if n == name:
                                offset = i
                                spacing = s
                                mode = m
                                forcing = True
                                break
                        else:
                            print("not found: %s 0x%x 0x%08x" % (name, size, crc))
                            continue
                
                if offset < 0:
                    z.writestr(name, b'\0'*size)
                    print("zeroed %s 0x%x 0x%08x" % (name,size,crc))
                else:
                    print("0x%06x%s%s %s 0x%x 0x%08x%s" % (offset,"x2" if spacing==2 else "",
                        ("","l","h")[mode], name,size,crc, " force" if forcing else ""))
                    if spacing == 1:
                        z.writestr(name, bytes(map(MODES[mode], data[offset:offset+size])))
                    else:
                        z.writestr(name, bytes(map(MODES[mode], data[offset:offset+2*size-1:2])))
            
            
                
