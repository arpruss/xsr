mkdir old-mame 2> /dev/null
python3 makezip.py -o old-mame extracted/PacMan.rom pacman.xml pacman.6j 0x1000 82s126.3m -1
python3 makezip.py -o old-mame extracted/MsPacMan.rom mspacmab.xml boot4 0x3000 boot6 0x5000 5e 0x6000 82s126.3m -1
python3 makezip.py -o old-mame extracted/Galaxian.rom galaxian.xml
python3 makezip.py -o old-mame extracted/Mappy.rom mappy.xml
python3 makezip.py -o old-mame extracted/RallyX.rom rallyx.xml rallyxn.1e 0x1000 rallyxn.1k 0x3000 rx1-2.4n -1 rx1-3.7k -1 rx1-4.2m -1
python3 makezip.py -o old-mame extracted/SkyKid.rom skykid.xml
python3 makezipfiles.py -o old-mame dspirit.xml extracted/DR*ROM extracted/*MCU*ROM
python3 makezip-separate.py -o old-mame galaga88.xml extracted/G8* extracted/*MC*
python3 makezip-separate.py -o old-mame pacmania.xml extracted/PM* extracted/*MC*
python3 makezip-separate.py -o old-mame rthunder.xml extracted/*
python3 makezip.py -o old-mame -a extracted/NS86MCU.ROM rthunder.xml cus60-60a1.mcu 0 rt1_21.f3 -1 rt2_22.h3 -1 # missing sound samples?
python3 makezip.py -o old-mame -a extracted/RT-COLOR.ROM rthunder.xml
python3 makezip.py -o old-mame -a extracted/RT-XMCU.ROM rthunder.xml
# the following work with mame2003-retroarch ; they don't work with 0.131u3 as that needs real 5xxx.bin files
python3 makezip.py -o old-mame extracted/DigDug.rom digdug.xml dd1a.6 0x5000 136007.109 -1 51xx.bin -1 53xx.bin -1
mv digdug.zip digdugb.zip 
python3 makezip.py -o old-mame extracted/Bosconian.rom bosco.c bos3_6.bin 0x5000 prom.2r -1 prom.7h -1 prom.5c -1 bosco.spr 0xc120
python3 makezip.py -o old-mame extracted/PolePosition1.rom polepos1.c 014-157.rom 0xf000 014-132.rom 0xb000 103.3e 0x7001x2 104.4e 0x7000x2 131.11n 0x22000 014-117.bpr -1
python3 makezip.py -o old-mame extracted/PolePosition2.rom poleps2a.c 178.3e 0x7000 179.4e 0x9000 184.3d 0xb000 185.4d 0xd000 172.7n 0xf000 131.11n 0x26000 014-110.rom 0x02e100 014-111.rom 0x030100 014-117.bpr -1
