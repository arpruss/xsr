import zlib
import sys
import ast

nibhi = False
niblo = False
splithi = False
splitlo = False

while sys.argv[1][0] == '-':
    if sys.argv[1][1:] == "nibhi":
        nibhi = True
    elif sys.argv[1][1:] == "niblo":
        niblo = True
    sys.argv = sys.argv[1:]
filename = sys.argv[1]
size = ast.literal_eval(sys.argv[2])
crc = int(sys.argv[3],16)

with open(filename, "rb") as f:
    data = f.read()
    if nibhi:
        data = bytearray((x >> 4 for x in data))
    elif niblo:
        data = bytearray((x & 0xF for x in data))
        
    for i in range(0,len(data)-size+1):
        c = zlib.crc32(data[i:i+size])
        if ( crc & 0xFFFFFFFF ) == (c & 0xFFFFFFFF):
            print("Found at 0x%x\n" % i)