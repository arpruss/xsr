import sys
import re
import os

outdir = '.'

if sys.argv[1]=='-o':
    outdir = sys.argv[2]
    sys.argv = sys.argv[2:]

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
        files.append((offset,size,name))
    for offset,size,name in files:
        out = os.path.join(outdir, name)
        print(out,offset,size)
        f.seek(headerSize+offset)
        with open(out,"wb") as g:
            g.write(f.read(size))
            