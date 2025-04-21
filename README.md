# Ergonomic Board v1.0

(6x5) sized dactyl-based split ergonomic keyboard generated from [Cosmos Keyboard Generator](https://ryanis.cool/cosmos/).

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
TBD

# Build Guide
TBD
