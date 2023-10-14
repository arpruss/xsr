mkdir mame2003 2> /dev/null
python3 makezip.py -o mame2003 extracted/PacMan.rom pacman.xml pacman.6j 0x1000 82s126.3m -1
python3 makezip.py -o mame2003 extracted/MsPacMan.rom mspacmab.xml boot4 0x3000 boot6 0x5000 5e 0x6000 82s126.3m -1
python3 makezip.py -o mame2003 extracted/Galaxian.rom galaxian.xml
python3 makezip.py -o mame2003 extracted/Mappy.rom mappy.xml
python3 makezip.py -o mame2003 extracted/RallyX.rom rallyx.xml rallyxn.1e 0x1000 rallyxn.1k 0x3000 rx1-2.4n -1 rx1-3.7k -1 rx1-4.2m -1
python3 makezip.py -o mame2003 extracted/SkyKid.rom skykid.xml
python3 makezip-separate.py -o mame2003 dspirit.c extracted/DR*ROM extracted/*MCU*ROM
python3 makezip-separate.py -o mame2003 galaga88.xml extracted/G8* extracted/*MC*
python3 makezip-separate.py -o mame2003 pacmania.xml extracted/PM* extracted/*MC*
python3 makezip-separate.py -o mame2003 rthunder.c extracted/*
python3 makezip.py -o mame2003 -a extracted/NS86MCU.ROM rthunder.c cus60-60a1.mcu 0 rt1-21.f3 -1 rt1-22.h3 -1 # missing sound samples?
python3 makezip.py -o mame2003 -a extracted/RT-COLOR.ROM rthunder.c
python3 makezip.py -o mame2003 -a extracted/RT-XMCU.ROM rthunder.c
# The following work with mame2003-retroarch ; they don't work with 0.131u3 as that needs real 5xxx.bin files.
# The 5Xxx.bin files included here are all zeroes, so they won't actually work, but old mame versions emulate the
# chips so that's OK.
python3 makezip.py -o mame2003 extracted/DigDug.rom digdug.xml dd1a.6 0x5000 136007.109 -1 51xx.bin -1 53xx.bin -1
mv mame2003/digdug.zip mame2003/digdugb.zip 
python3 makezip.py -o mame2003 extracted/Bosconian.rom bosco.c bos3_6.bin 0x5000 prom.2r -1 prom.7h -1 prom.5c -1 bosco.spr 0xc120
python3 makezip.py -o mame2003 extracted/PolePosition1.rom polepos1.c 014-157.rom 0xf000 014-132.rom 0xb000 103.3e 0x7001x2 104.4e 0x7000x2 131.11n 0x22000 014-117.bpr -1
python3 makezip.py -o mame2003 extracted/PolePosition2.rom poleps2a.c 178.3e 0x7001x2 179.4e 0x7000x2 184.3d 0xb001x2 185.4d 0xb000x2 172.7n 0xf000 131.11n 0x26000 014-110.rom 0x02e100 014-111.rom 0x030100 014-117.bpr -1
python3 makezip.py -o mame2003 extracted/Galaga.rom galagab2.c 04e_g05.bin 0x4000 04d_g06.bin 0x5000 gallag.8 0x6000 5c.bin -1 2n.bin 0x9020 1c.bin 0x9120 1d.bin 0x9220 10h_g07.bin -1 prom-2.5c -1
