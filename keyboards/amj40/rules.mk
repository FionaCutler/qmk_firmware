# MCU name
MCU = atmega32u4

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = atmel-dfu

# Build Options
#   comment out to disable the options.
#
<<<<<<< HEAD
BOOTMAGIC_ENABLE ?= no  # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE  ?= no  # Mouse keys(+4700)
EXTRAKEY_ENABLE  ?= yes # Audio control and System control(+450)
CONSOLE_ENABLE   ?= yes # Console for debug(+400)
COMMAND_ENABLE   ?= yes # Commands for debug and configuration
NKRO_ENABLE      ?= yes # USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
RGBLIGHT_ENABLE  ?= yes # Enable keyboard underlight functionality (+4870)
BACKLIGHT_ENABLE ?= yes # Enable keyboard backlight functionality (+1150)
MIDI_ENABLE      ?= no  # MIDI controls
AUDIO_ENABLE     ?= no
UNICODE_ENABLE   ?= no  # Unicode
BLUETOOTH_ENABLE ?= no  # Enable Bluetooth with the Adafruit EZ-Key HID
=======
BOOTMAGIC_ENABLE = no  # Virtual DIP switch configuration
MOUSEKEY_ENABLE  = no  # Mouse keys
EXTRAKEY_ENABLE  = yes # Audio control and System control
CONSOLE_ENABLE   = yes # Console for debug
COMMAND_ENABLE   = yes # Commands for debug and configuration
NKRO_ENABLE      = yes # USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
RGBLIGHT_ENABLE  = yes # Enable keyboard underlight functionality
BACKLIGHT_ENABLE = yes # Enable keyboard backlight functionality
MIDI_ENABLE      = no  # MIDI controls
AUDIO_ENABLE     = no
UNICODE_ENABLE   = no  # Unicode
BLUETOOTH_ENABLE = no  # Enable Bluetooth with the Adafruit EZ-Key HID
>>>>>>> e941f048919bba052fd326eadc5acd2347e6756e
