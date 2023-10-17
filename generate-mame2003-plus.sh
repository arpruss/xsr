mkdir mame2003plus 2> /dev/null
python3 makezip.py -o mame2003plus extracted/PacMan.rom pacman.xml pacman.6j 0x1000 82s126.3m -1
python3 makezip.py -o mame2003plus extracted/MsPacMan.rom mspacmab.xml boot4 0x3000 boot6 0x5000 5e 0x6000 82s126.3m -1
python3 makezip.py -o mame2003plus extracted/Galaxian.rom galaxian.xml
python3 makezip.py -o mame2003plus extracted/Mappy.rom mappy.xml
python3 makezip.py -o mame2003plus extracted/RallyX.rom rallyx-plus.xml rallyxn.1e 0x1000 rallyxn.1k 0x3000 rx1-2.4n -1 rx1-3.7k -1 rx1-4.2m -1 im5623.2m -1
python3 makezip.py -o mame2003plus extracted/SkyKid.rom skykid.xml
python3 makezip-separate.py -o mame2003plus dspirit.xml extracted/DR*ROM extracted/*MCU*ROM
python3 makezip-separate.py -o mame2003plus galaga88.xml extracted/G8* extracted/*MC*
python3 makezip-separate.py -o mame2003plus pacmania.xml extracted/PM* extracted/*MC*
python3 makezip-separate.py -o mame2003 rthunder.c extracted/*
python3 makezip.py -o mame2003plus -a extracted/NS86MCU.ROM rthunder.c cus60-60a1.mcu 0 rt1-21.f3 -1 rt1-22.h3 -1 # missing sound samples?
python3 makezip.py -o mame2003plus -a extracted/RT-COLOR.ROM rthunder.c
python3 makezip.py -o mame2003plus -a extracted/RT-XMCU.ROM rthunder.c
# The following work with mame2003-retroarch ; they don't work with 0.131u3 as that needs real 5xxx.bin files.
# The 5Xxx.bin files included here are all zeroes, so they won't actually work, but old mame versions emulate the
# chips so that's OK.
python3 makezip.py -o mame2003plus extracted/DigDug.rom digdug.xml dd1a.6 0x5000 136007.109 -1 51xx.bin -1 53xx.bin -1
python3 makezip.py -o mame2003plus extracted/Bosconian.rom bosco.c bos3_6.bin 0x5000 prom.2r -1 prom.7h -1 prom.5c -1 bosco.spr 0xc120
zip mame2003plus/bosco.zip 5?xx.bin
python3 makezip.py -o mame2003plus extracted/PolePosition1.rom polepos1-plus.xml 136014.157 0xf000 136014.132 0xb000 136014.103 0x7001x2 136014.104 0x7000x2 136014.131 0x22000 136014.117 -1 136014.135 -1 136014.136 -1
zip mame2003plus/polepos1.zip 5?xx.bin
python3 makezip.py -s 0x100 -o mame2003plus extracted/PolePosition2.rom poleps2a.xml 136014.178 0x7001x2 136014.179 0x7000x2 136014.184 0xb001x2 136014.185 0xb000x2 136014.172 0xf000 131.11n 0x26000 014-110.rom 0x02e100 014-111.rom 0x030100  136014.135 -1  136014.136 -1 136014.117 -1 51xx.bin -1 52xx.bin -1 53xx.bin -1 54xx.bin -1
python3 makezip.py -o mame2003plus extracted/Galaga.rom galaga.xml 54xx.bin zero 51xx.bin zero prom-2.5c zero
