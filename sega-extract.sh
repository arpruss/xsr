mkdir SEGA/roms
for x in SEGA/??/*.SR ; do echo $x ; python xsr.py -o SEGA/roms -x .qz -x .bin -x .rom -x .68k $x ; done
