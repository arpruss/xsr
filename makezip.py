import sys
import re
import zlib
import ast
import zipfile

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
        if line.startswith('<game '):
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
                print("%s 0x%x 0x%08x" % (name,size,crc))
                if size > len(data):
                    print("does not fit!")
                offset = None
                for i in range(0,len(data)-size+1):
                    c = zlib.crc32(data[i:i+size])
                    if ( crc & 0xFFFFFFFF ) == (c & 0xFFFFFFFF):
                        print("found at 0x%x" % i)
                        offset = i
                        break
                else:
                    for n,i in force:
                        if n == name:
                            print("forcing 0x%x" % i)
                            offset = i
                            break
                    else:
                        print("not found")
                
                if offset is not None:
                    z.writestr(name, data[offset:offset+size])
            
            
                
