
For Windows:
============

Compile with (under Bash for windows):

make lets_split/rev2:weboide


Open windows CMD or powershell:

cd "C:\Program Files (x86)\Arduino\hardware\tools\avr\bin"

Copy the .hex into the above folder.
Flash with (replace with the correct COM port):

./avrdude  -C ..\etc\avrdude.conf -v -p atmega32u4 -P YOURCOMPORT -c avr109 -U flash:w:lets_split_rev2_weboide.hex


For Linux:
==========



Test connection with:

avrdude -p atmega32u4 -P INSERTCOMPORT -c avr109


Flash using:

avrdude -p atmega32u4 -P INSERTCOMPORT -c avr109 -U flash:w:lets_split_rev2_weboide.hex
