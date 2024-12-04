import os
import zlib

try:
    os.mkdir('taito/extract')
except:
    pass

with open('taito/FILES.HDR', 'rb') as hdr:
    with open('taito/FILES.DAT', 'rb') as dat:
        hdr.seek(0x388)
        while True:
            filename = hdr.read(16)
            if len(filename) < 16:
                break
            filename = filename.split(b'\x00')[0].decode('ascii').split(';')[0]
            xxSeq = int.from_bytes(hdr.read(4), byteorder='little', signed=True)
            offset = int.from_bytes(hdr.read(4), byteorder='little', signed=False)*0x800
            size = int.from_bytes(hdr.read(4), byteorder='little', signed=False)
            if xxSeq == -1: 
                dat.seek(offset)
                data = dat.read(size)
                crc = zlib.crc32(data)
                print("%s\t%08x\t%08x" % (filename,size,crc))
                with open('taito/extract/'+filename,"wb") as out:
                    out.write(data)
                