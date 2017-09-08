Test connection with:

avrdude -p atmega32u4 -P INSERTCOMPORT -c avr109


Flash using:

avrdude -p atmega32u4 -P INSERTCOMPORT -c avr109 -U flash:w:lets_split_rev2_weboide.hex
