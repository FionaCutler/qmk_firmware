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
#   comment out to disable the options.
#
<<<<<<< HEAD
BOOTMAGIC_ENABLE  = no	# Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE  = no	# Mouse keys(+4700)
EXTRAKEY_ENABLE  = no	# Audio control and System control(+450)
CONSOLE_ENABLE  = yes	# Console for debug(+400)
=======
BOOTMAGIC_ENABLE  = no	# Virtual DIP switch configuration
MOUSEKEY_ENABLE  = no	# Mouse keys
EXTRAKEY_ENABLE  = yes	# Audio control and System control
CONSOLE_ENABLE  = yes	# Console for debug
>>>>>>> e941f048919bba052fd326eadc5acd2347e6756e
COMMAND_ENABLE  = yes    # Commands for debug and configuration
SLEEP_LED_ENABLE  = no  # Breathing sleep LED during USB suspend
NKRO_ENABLE  = yes		# USB Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE  = no  # Custom backlighting code is used, so this should not be enabled
AUDIO_ENABLE  = no # This can be enabled if a speaker is connected to the expansion port. Not compatible with RGBLIGHT below
RGBLIGHT_ENABLE  = yes # This can be enabled if a ws2812 strip is connected to the expansion port.
