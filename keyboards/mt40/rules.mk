# MCU name
MCU = atmega32a

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = bootloadHID

# build options
<<<<<<< HEAD
BOOTMAGIC_ENABLE ?= yes # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE ?= no   # Mouse keys(+4700)
EXTRAKEY_ENABLE ?= yes  # Audio control and System control(+450)
CONSOLE_ENABLE ?= no    # Console for debug(+400)
COMMAND_ENABLE ?= no    # Commands for debug and configuration
NKRO_ENABLE ?= no       # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ # nkro-doesnt-work
BACKLIGHT_ENABLE ?= yes # Enable keyboard backlight functionality
MIDI_ENABLE ?= no       # MIDI controls
AUDIO_ENABLE ?= no      # Audio output on port C6
UNICODE_ENABLE ?= no    # Unicode
BLUETOOTH_ENABLE ?= no  # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE ?= yes  # Enable WS2812 RGB underlight. 
=======
BOOTMAGIC_ENABLE = yes # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no   # Mouse keys
EXTRAKEY_ENABLE = yes  # Audio control and System control
CONSOLE_ENABLE = no    # Console for debug
COMMAND_ENABLE = no    # Commands for debug and configuration
NKRO_ENABLE = no       # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ # nkro-doesnt-work
BACKLIGHT_ENABLE = yes # Enable keyboard backlight functionality
MIDI_ENABLE = no       # MIDI controls
AUDIO_ENABLE = no      # Audio output on port C6
UNICODE_ENABLE = no    # Unicode
BLUETOOTH_ENABLE = no  # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE = yes  # Enable WS2812 RGB underlight. 
>>>>>>> e941f048919bba052fd326eadc5acd2347e6756e
WS2812_DRIVER = i2c
TAP_DANCE_ENABLE = no

LAYOUTS = planck_mit
LAYOUTS_HAS_RGB = no
