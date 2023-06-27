# Handwired-Kyria
A handwired version of the kyria keyboard by splitkb.com

Needed parts:
- 3D printed case (mirror provided stls for right side)
- 50x keyboard switches of your choice (I used durock L7 67g)
- 50x 1N4148 diodes
- 2x 4 pin XS6 mini Aviation plug & socket (https://www.aliexpress.com/item/1005004089293971.html)
- 2x Waveshare RP2040-Zero Microcontrollers (https://core-electronics.com.au/rp2040-zero-a-pico-like-mcu-board-based-on-raspberry-pi-mcu-rp2040-mini-ver-1.html)
- wire for connecting switches to microcontrollers, I used stranded alarm wire (https://www.jaycar.com.au/4-core-alarm-cable-sold-per-metre/p/WB1590?pos=2&queryId=16eeb7069ed69f201332ceafd4c163ac)
- 4 core cable for connecting both halves, I used the same alarm wire mentioned previously
- Keycaps of your choice, I used blank pbt oem.
- 30x m2 6mm heatset inserts (https://www.aliexpress.com/item/1005005220632314.html)
- 30x m2 6mm countersunk screws (https://www.aliexpress.com/item/1005003986879500.html)

Optional but highly recommended:
- 50x hotswap sockets (https://www.aliexpress.com/item/1005004290562374.html)
- paracord for sleeving the cable
- magnetic usb c cable (https://www.aliexpress.com/item/1005005402419615.html)
- heatshrink
- rubber feet (https://www.aliexpress.com/item/1005003412490420.html)

Notes for building:
- if using hotswap sockets solder on the bottom for the switches under the microcontroller! the tolerance is tight!
- put electrical tape on the switches under the microcontoller
- the xs6 connector is used to wire the microcontrollers together, you need to wire GP0-GP0, GP1-GP1, 3.3v-3.3v, Ground-Ground. Make sure you are wiring it correctly and check with a multimeter, make sure that they aren't shorting to each other as it is quite a small connector.
- the cable and paracord that I used was very tight in the connector, to make it fit easier I used a pair of scissors to scrape the cable rubber sleeving and make it as thin as possible without removing the sleeving
- I found it difficult to solder the sx6 connector on the cable side because of its size, take your time and try to put heatshrink around each solder point to avoid accidental shorts
- it is better to use a more flexible wire so that it's easier to jam the microcontroller into it's slot, originally I used solid core wire and it was difficult to get the microcontroller in
- print the test prints to check tolerances and your print settings before printing the full case
- I used angled tip pliers to put the nut on the xs6 socket, I didn't want to make that section of the case any thinner because when I was testing with white filament it would have become transparent
- The reason that I used the xs6 connector is that trrs is not hotplug safe and the xs6 mini was the smallest suitable connector I could find and as a bonus it's a pretty cool connector

Firmware notes:
- I have included my qmk files, my keymap is probably more complicated than you want I recommend looking through my layout then either modifiying it to your liking or making your own
- I'm using EE_HANDS to determine the side of the split so when flashing select the uf2-split-left bootloader for left and uf2-split-right for right. For example to flash the keyboard I use the command "qmk flash -kb handwired/kyria_mt -km mitchell -bl uf2-split-left" and "qmk flash -kb handwired/kyria_mt -km mitchell -bl uf2-split-right" in qmk msys
