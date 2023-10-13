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
    if sys.argv[i+1].endswith('x2'):
        spacing = 2
        sys.argv[i+1] = sys.argv[i+1][:-2]
    else:
        spacing = 1
    force.append((sys.argv[i],ast.literal_eval(sys.argv[i+1]),spacing))

with open(sys.argv[1],"rb") as rom:
    data = rom.read()
    
with open(sys.argv[2],"r") as xml:
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
            zipname = get('name',line)+'.zip'
            print(zipname)
            break
            
    with zipfile.ZipFile(zipname, "w" if not add else "a") as z:
        for line in xml:
            line = line.strip()
            xmlMode = False
            cMode = False
            xmlMode = line.startswith('<rom ')
            cMode = line.startswith('ROM_LOAD')
            if line.startswith('<rom ') or line.startswith('ROM_LOAD'):
                name = get('name',line)
                crc = int(get('crc',line),16)
                size = int(get('size',line))
                if size > len(data):
                    print("does not fit!")
                forcing = False
                spacing = 1
                for i in range(0,len(data)-size+1):
                    c = zlib.crc32(data[i:i+size])
                    if ( crc & 0xFFFFFFFF ) == (c & 0xFFFFFFFF):
                        offset = i
                        break
                else:
                    for i in range(0,len(data)-2*size+1):
                        c = zlib.crc32(data[i:i+2*size:2])
                        if ( crc & 0xFFFFFFFF ) == (c & 0xFFFFFFFF):
                            offset = i
                            spacing = 2
                            break
                    else:
                        for n,i,s in force:
                            if n == name:
                                offset = i
                                spacing = s
                                forcing = True
                                break
                        else:
                            print("not found: %s 0x%x 0x%08x" % (name, size, crc))
                            continue
                
                if offset < 0:
                    z.writestr(name, b'\0'*size)
                    print("zeroed %s 0x%x 0x%08x" % (name,size,crc))
                else:
                    print("0x%06x%s %s 0x%x 0x%08x%s" % (offset,"x2" if spacing==2 else "",name,size,crc, " force" if forcing else ""))
                    if spacing == 1:
                        z.writestr(name, data[offset:offset+size])
                    else:
                        z.writestr(name, data[offset:offset+2*size-1:2])
            
            
                
