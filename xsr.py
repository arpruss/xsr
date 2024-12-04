import sys
import re
import os
import zlib

outdir = '.'

exts = []

while sys.argv[1][0] == '-':
    if sys.argv[1]=='-x':
        exts.append(sys.argv[2])
        sys.argv = sys.argv[2:]
    elif sys.argv[1]=='-o':
        outdir = sys.argv[2]
        sys.argv = sys.argv[2:]
    else:
        print("Unknown option")
        sys.exit(3)

try:
    os.mkdir(outdir)
except:
    pass

with open(sys.argv[1], "rb") as f:
    def getline():
        z = b''
        while True:
            x = f.read(1)
            if x == b'\n':
                return z.decode()
            z += x
    header = getline()
    fileCount,_,headerSize = map(int,header.split())
    print('files:',fileCount)
    files = []
    for i in range(fileCount):
        offset,size,_,_,_,name = re.split(r'\s+', getline().strip(), maxsplit=5)
        offset = int(offset)
        size = int(size)
        if len(exts):
            for x in exts:
                if name.lower().endswith(x.lower()):
                    files.append((offset,size,name))
                    break
        else:
            files.append((offset,size,name))
    for offset,size,name in files:
        f.seek(headerSize+offset)
        data = f.read(size)
        if name.lower().endswith(".qz"):
            name = name[:-3]            
            data = zlib.decompress(data[4:])
        out = os.path.join(outdir, name)
        print(out,offset,size)
        with open(out,"wb") as g:
            g.write(data)
            