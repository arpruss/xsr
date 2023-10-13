import sys
import re
import zlib
import ast
import zipfile

add = False

if sys.argv[1] == '-a':
    add = True
    sys.argv = sys.argv[1:]

force = []
for i in range(3,len(sys.argv),2):
    force.append((sys.argv[i],ast.literal_eval(sys.argv[i+1])))

with open(sys.argv[1],"rb") as rom:
    data = rom.read()
    
with open(sys.argv[2],"r") as xml:
    def get(s,line):
        return re.search(s+r'=[\"\'](.*?)[\"\']', line).group(1)

    for line in xml:
        line = line.strip()
        if line.startswith('<game ') or line.startswith('<machine '):
            zipname = get('name',line)+'.zip'
            print(zipname)
            break
            
    with zipfile.ZipFile(zipname, "w" if not add else "a") as z:
        for line in xml:
            line = line.strip()
            if line.startswith('<rom '):
                name = get('name',line)
                crc = int(get('crc',line),16)
                size = int(get('size',line))
                if size > len(data):
                    print("does not fit!")
                forcing = False
                for i in range(0,len(data)-size+1):
                    c = zlib.crc32(data[i:i+size])
                    if ( crc & 0xFFFFFFFF ) == (c & 0xFFFFFFFF):
                        offset = i
                        break
                else:
                    for n,i in force:
                        if n == name:
                            offset = i
                            forcing = True
                            break
                    else:
                        print("not found: %s 0x%x 0x%08x" % (name, size, crc))
                        continue
                
                if offset < 0:
                    z.writestr(name, b'\0'*size)
                    print("zeroed %s 0x%x 0x%08x" % (name,size,crc))
                else:
                    print("0x%06x %s 0x%x 0x%08x%s" % (offset,name,size,crc, " force" if forcing else ""))
                    z.writestr(name, data[offset:offset+size])
            
            
                
