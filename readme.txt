xsr.py is a general tool for extracting data from .SR archives:
  python3 xsr.py [-o outdir] archive.sr
  
The other tools are used for converting roms in the PS2 version of the Namco 50th 
Anniversary Anthology to mame format. They are Linuxy, though I've used them with
cygwin on windows.

First extract the data from CLASSIC/NAMCO.SR to the "extracted" folder:
  python3 xsr.py -o extracted /media/cdrom/CLASSIC/NAMCO.SR
(or wherever you have the CLASSIC/NAMCO.SR file).

By the way, the NAMCO.SR file is included twice on my CD: once in the /CLASSIC/NAMCO.SR
file and once in the /NAMCO50.VOL file. If you want the latter copy, you get it with
  sh vol-to-sr.sh /media/cdrom/NAMCO50.VOL NAMCO.SR
and then extract the SR file with xsr.py.

Then run generate-old-mame.sh to make roms for old mame versions, generate-new-mame.sh for 
new ones and generate-mame2003.sh to make roms for mame2003-libretro.

How old is "old"? Well, at least older than 0.131u3. For as of version 0.131u3, 
mame started doing more accurate emulations of the Namco 5xxx chips, and so some of
the roms need dumps of these. But the Namco Anthology doesn't include these dumps,
so you need an older version of mame for the games where these are needed:
Dig Dug, Xevious, Pole Position 1 and 2, Bosconian and Galaga. 

Not all the games will work. A lot of the roms in the anthology have checksums that
don't match anything I could find online, so there was a lot of guesswork as to which
part of the extracted rom goes where in the zip file.

This is all hard to use and written for myself. Terribly documented, messy and inefficient code.