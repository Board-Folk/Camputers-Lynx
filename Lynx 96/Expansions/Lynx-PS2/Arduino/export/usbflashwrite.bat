avrdude -c usbasp -p m328p -B 10 -U flash:w:lynxps2v0.hex:i 
avrdude -c usbasp -p m328p -B 10 -U lfuse:w:0xFF:m
avrdude -c usbasp -p m328p -B 10 -U hfuse:w:0xDA:m
avrdude -c usbasp -p m328p -B 10 -U efuse:w:0xFD:m
