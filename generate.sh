python makezip.py extracted/PacMan.rom pacman.xml pacman.6j 0x1000 82s126.3m -1
python makezip.py extracted/MsPacMan.rom mspacmab.xml boot4 0x3000 boot6 0x5000 5e 0x6000 82s126.3m -1
python3 makezip.py extracted/Galaxian.rom galaxian.xml
python3 makezip.py extracted/Mappy.rom mappy.xml
python3 makezip.py extracted/RallyX.rom rallyx.xml rallyxn.1e 0x1000 rallyxn.1k 0x3000 rx1-2.4n -1 rx1-3.7k -1 rx1-4.2m -1
python3 makezip.py extracted/SkyKid.rom skykid.xml
python3 makezipfiles.py dspirit.xml extracted/DR*ROM extracted/*MCU*ROM
python3 makezip-separate.py galaga88.xml extracted/G8* extracted/*MC*
python3 makezip-separate.py pacmania.xml extracted/PM* extracted/*MC*
