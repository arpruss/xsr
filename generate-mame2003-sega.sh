mkdir mame2003 2> /dev/null
#python3 makezip.py -o mame2003 SEGA/roms/ZAXXON.ROM zaxxon.xml
#python3 makezip.py -o mame2003 SEGA/roms/ZEKTOR.ROM zektor.xml
#python3 makezip.py -o mame2003 SEGA/roms/TACSCAN.ROM tacscan.xml
#python3 makezip.py -o mame2003 SEGA/roms/FUTURESPY.ROM futspy.xml
python3 makezip.py -s 0x1000 -o mame2003 SEGA/roms/Chars.rom altbeast.xml
python3 makezip.py -s 0x1000 -a -o mame2003 SEGA/roms/Program.rom altbeast.xml
python3 makezip.py -s 0x1000 -a -o mame2003 SEGA/roms/Sprites.rom altbeast.xml #11671 zero opr11672 zero opr11673 zero # no sound
python3 makezip.py -s 1 -a -o mame2003 SEGA/roms/ABEAST16.ELF altbeast.xml
