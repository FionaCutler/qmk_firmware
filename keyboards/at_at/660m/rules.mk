# MCU name
MCU = STM32F072
BOARD = GENERIC_STM32_F072XB

# Build Options
#   comment out to disable the options.
#

#BOOTMAGIC_ENABLE = yes	# Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes	# Mouse keys
EXTRAKEY_ENABLE = yes	# Audio control and System control
CONSOLE_ENABLE = yes	# Console for debug
COMMAND_ENABLE = yes    # Commands for debug and configuration
#SLEEP_LED_ENABLE = yes  # Breathing sleep LED during USB suspend
NKRO_ENABLE = yes	    # USB Nkey Rollover
CUSTOM_MATRIX = no # Custom matrix file
# BACKLIGHT_ENABLE = yes
# RGBLIGHT_ENABLE = yes
NO_USB_STARTUP_CHECK = yes # Workaround for issue 6369

