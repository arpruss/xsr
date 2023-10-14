mkdir new-mame 2> /dev/null
python3 makezip.py -o new-mame extracted/PacMan.rom pacman.xml pacman.6j 0x1000 82s126.3m -1
python3 makezip.py -o new-mame extracted/MsPacMan.rom mspacmab.xml boot4 0x3000 boot6 0x5000 5e 0x6000 82s126.3m -1
python3 makezip.py -o new-mame extracted/Galaxian.rom galaxian.xml
python3 makezip.py -o new-mame extracted/Mappy.rom mappy.xml
python3 makezip.py -o new-mame extracted/RallyX.rom rallyx.xml rallyxn.1e 0x1000 rallyxn.1k 0x3000 rx1-2.4n -1 rx1-3.7k -1 rx1-4.2m -1
python3 makezip.py -o new-mame extracted/SkyKid.rom skykid.xml
python3 makezip-separate.py -o new-mame dspirit.xml extracted/DR*ROM extracted/*MCU*ROM
python3 makezip-separate.py -o new-mame galaga88.xml extracted/G8* extracted/*MC*
python3 makezip-separate.py -o new-mame pacmania.xml extracted/PM* extracted/*MC*
python3 makezip-separate.py -o new-mame rthunder.xml extracted/*
python3 makezip.py -o new-mame -a extracted/NS86MCU.ROM rthunder.xml cus60-60a1.mcu 0 rt1_21.f3 -1 rt2_22.h3 -1 # missing sound samples?
python3 makezip.py -o new-mame -a extracted/RT-COLOR.ROM rthunder.xml
python3 makezip.py -o new-mame -a extracted/RT-XMCU.ROM rthunder.xml
