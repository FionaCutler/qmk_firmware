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
BOOTLOADER = caterina

# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
BOOTMAGIC_ENABLE ?= no       # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE ?= yes       # Mouse keys(+4700)
EXTRAKEY_ENABLE ?= no       # Audio control and System control(+450)
CONSOLE_ENABLE ?= no         # Console for debug(+400)
COMMAND_ENABLE ?= yes        # Commands for debug and configuration
NKRO_ENABLE ?= no            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE ?= no      # Enable keyboard backlight functionality
MIDI_ENABLE ?= no            # MIDI controls
AUDIO_ENABLE ?= no           # Audio output on port C6
UNICODE_ENABLE ?= no         # Unicode
BLUETOOTH_ENABLE ?= no       # Enable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE ?= no       # Enable WS2812 RGB underlight. 
USE_I2C ?= no
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
<<<<<<< HEAD
SLEEP_LED_ENABLE ?= no    # Breathing sleep LED during USB suspend
=======
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = no            # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
MIDI_ENABLE = no            # MIDI support
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
AUDIO_ENABLE = no           # Audio output on port C6
FAUXCLICKY_ENABLE = no      # Use buzzer to emulate clicky switches
>>>>>>> e941f048919bba052fd326eadc5acd2347e6756e

CUSTOM_MATRIX = yes
SRC += matrix.c \
	   i2c.c \
	   split_util.c \
	   serial.c

DEFAULT_FOLDER = minidox/rev1
