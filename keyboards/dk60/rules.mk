# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = atmel-dfu

<<<<<<< HEAD
BOOTMAGIC_ENABLE = yes	# Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = no	# Mouse keys(+4700)
EXTRAKEY_ENABLE = yes	# Audio control and System control(+450)
# CONSOLE_ENABLE = yes	# Console for debug(+400)
# COMMAND_ENABLE = yes    # Commands for debug and configuration
KEYBOARD_LOCK_ENABLE = yes	# Allow locking of keyboard via magic key
NKRO_ENABLE = yes		# USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
RGBLIGHT_ENABLE = no   # Enable keyboard underlight functionality (+4870)
BACKLIGHT_ENABLE = no  # Enable keyboard backlight functionality (+1150)
MIDI_ENABLE = no 		# MIDI controls
AUDIO_ENABLE = no
UNICODE_ENABLE = yes 		# Unicode
BLUETOOTH_ENABLE = no # Enable Bluetooth with the Adafruit EZ-Key HID
SLEEP_LED_ENABLE = yes
=======
# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = full     # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = yes      # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
BLUETOOTH_ENABLE = no       # Enable Bluetooth
AUDIO_ENABLE = no           # Audio output
KEYBOARD_LOCK_ENABLE = yes
UNICODE_ENABLE = yes
>>>>>>> e941f048919bba052fd326eadc5acd2347e6756e
