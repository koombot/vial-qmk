#Firmware Optimisation
LTO_ENABLE = no  # Disabled: suspected cause of intermittent USB disconnects on V-USB (atmega328p, no hardware USB)
BOOTMAGIC_ENABLE = no # Disable Bootmagic to reduce firmware size
TAP_DANCE_ENABLE = no # Disable Tap Dance to reduce firmware size
COMBO_ENABLE = no # Disable Combo to reduce firmware size
MOUSEKEY_ENABLE = no # Disable Mouse Key to reduce firmware size
CONSOLE_ENABLE = no # Disable Console to reduce firmware size

VIA_ENABLE = yes
VIAL_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes
QMK_SETTINGS = yes

TRI_LAYER_ENABLE = no # Unused: thumb keys not populated on 2u board; tri-layer handled via layer_state_set_user instead
CAPS_WORD_ENABLE = yes

BOOTLOADER = usbasploader







