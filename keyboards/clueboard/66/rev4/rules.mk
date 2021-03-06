# MCU name
MCU = STM32F303

# Build Options
#   comment out to disable the options.
#
<<<<<<< HEAD
BOOTMAGIC_ENABLE = lite   # Virtual DIP switch configuration
=======
BOOTMAGIC_ENABLE = no   # Virtual DIP switch configuration
>>>>>>> upstream/master
MOUSEKEY_ENABLE = yes   # Mouse keys
EXTRAKEY_ENABLE = yes   # Audio control and System control
CONSOLE_ENABLE = yes    # Console for debug
COMMAND_ENABLE = yes     # Commands for debug and configuration
NKRO_ENABLE = yes       # USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
<<<<<<< HEAD
AUDIO_ENABLE = yes
RGBLIGHT_ENABLE = no    # Enable keyboard underlight functionality
BACKLIGHT_ENABLE = no
=======
AUDIO_ENABLE = no
BACKLIGHT_ENABLE = no   # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no    # Enable keyboard RGB underglow
>>>>>>> upstream/master
MIDI_ENABLE = no        # MIDI controls
UNICODE_ENABLE = no     # Unicode
BLUETOOTH_ENABLE = no   # Enable Bluetooth with the Adafruit EZ-Key HID

LAYOUTS = 66_ansi 66_iso
