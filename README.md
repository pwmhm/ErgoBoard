# Ergonomic Board v1.0

(6x5) sized dactyl-based split ergonomic keyboard generated from [Cosmos Keyboard Generator](https://ryanis.cool/cosmos/). This is a hardwired build so there is no pcb schematic available.

# Features
- Trackball as a mouse (Additionally used as scrolling media)
- Configurable joystick (Currently used as scrolling media)
- 3x3 and 1x5 customizable thumb cluster on left and right side respectively
- VIAL supported

# Installation

## Default Keymap
- make sure qmk is installed (see qmk page on guide)
- for default keymap: copy ergoboard directory to the keyboards section of the qmk parent directory
- run `qmk flash -kb ergoboard -km default -bl avrdude-split-right` (depending on the side change right to left) and put your left/right microcontroller in bootloader mode

## VIAL
- make sure qmk is installed
- clone vial-qmk repository and go inside it
- copy ergoboard into its keyboards/ section
- run `make ergoboard:vial`. If everything is ok there will be a resulting hex file called `ergoboard_vial.hex`
- run `qmk flash -bl avrdude-split-left` (depending on the side change right to left) and put your left/right microcontroller in bootloader mode

# BOM
Below are the bill of materials that were used to make this keyboard. The "Price Single" column shows the normal price of a particular item, and the suceeding column shows how much it was bought for.

| Item | Quantity | Price Single | Price Total (incl. discounts etc.) | 
| --- | --- | ----------- | -------- |
| 3D Printed Case | 2 Pcs | Place-dependant | 10 EUR
| Keycaps (XDA Style) | 74 Pcs | 4.39 EUR for 20pcs | 17.64 EUR |
| MX Switches | 74 Pcs | 2.09 EUR for 10pcs | 15.95 EUR |
| 1N4148 Diode | 74 Pcs | 3.29 EUR for 100pcs | 3.29 EUR | 
| Adafruit Mini Thumbsticks #5628 | 1 Pcs | 6.50 EUR | 11 EUR | 
| PMW3360 Sensor | 1 Pcs | 15.69 EUR | 15.69 EUR | 
| PMW3350 Breakout Board | 1 Pcs | >20 EUR for 5 Pcs | 5.85 EUR |
| 34mm Trackball | 1 Pcs | 8.76 EUR | 8.76 EUR |
| 3 x 6 x 2.5 mm Bearings | 3 Pcs | 4.19 EUR for 10pcs | 4.19 EUR | 
| 3 x 8 Dowel Pins | 3 Pcs | - | 0 EUR (used scraps around the house) | 
| Pro Micro | 2 Pcs | 1.50 EUR for 2 pcs | 3.00 EUR |
| PJ-320A TRRS Jack | 2 Pcs | 1.19 EUR for 10 pcs | 1.19 EUR |
| M3 Screw Inserts | 20 Pcs | 5.99 EUR for a set | 5.99 EUR| 
| M3 Screws | 20 Pcs | 6.99 EUR for a set | 6.99 EUR|
| Jumper Wires | As much as needed | 1.30 EUR for a set | 1.30 EUR
| Male Pin Headers | 25 pcs | 1.20 EUR for a set | 1.20 EUR|
| Dupont jumper wires | approx. 40 Pcs | 1.90 EUR for a set | 1.90 EUR|

The Male pin headers and dupont wires are optional, but they do make it easier when installing the mcu and allows you to change pins arbitrarily. Additionally, the trrs connector for the two keyboards are not included.

PMW3360 Breakout costs quite a lot of money to make, mainly because of the PCBA service. If you are able to do smd soldering, you can save quite some money on this. Also, it is worth noting that i got the price to 5.85 EUR by using their discount coupon for new users.

3D printed case can vary a lot. Retail prices online with this model shows upwards of 40 EUR for it. In my case, i decided to source it locally (aka colleagues) which means only the material cost were accounted for.

Since this is a hardwired build, please also note that this assumes you have good knowledge about soldering and already have soldering tools available.

# Troubleshooting

Common problem with pro-micro mcus is that they are sometimes unrecognizable when connected to a pc. This is the case with micro-usb pro-micro that i used. In this case, please check if connecting the pro-micro to a usb-c port instead of usb-a solves the problem.

# Build Guide
TBD
