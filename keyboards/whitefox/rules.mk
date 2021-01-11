# MCU name
MCU = MK20DX256

# Bootloader selection
BOOTLOADER = kiibohd

# Board: it should exist either in <chibios>/os/hal/boards/
#  or <this_dir>/boards
# - BOARD =
#   - PJRC_TEENSY_LC for Teensy LC
#   - PJRC_TEENSY_3 for Teensy 3.0
#   - PJRC_TEENSY_3_1 for Teensy 3.1 or 3.2
#   - MCHCK_K20 for Infinity KB
BOARD = IC_TEENSY_3_1

# Build Options
#   change yes to no to disable
#
<<<<<<< HEAD
BOOTMAGIC_ENABLE = yes	# Virtual DIP switch configuration
## (Note that for BOOTMAGIC on Teensy LC you have to use a custom .ld script.)
MOUSEKEY_ENABLE = yes	# Mouse keys
EXTRAKEY_ENABLE = yes	# Audio control and System control
#CONSOLE_ENABLE = yes	# Console for debug
COMMAND_ENABLE = yes    # Commands for debug and configuration
#SLEEP_LED_ENABLE = yes  # Breathing sleep LED during USB suspend
NKRO_ENABLE = yes	    # USB Nkey Rollover
CUSTOM_MATRIX = yes # Custom matrix file
BACKLIGHT_ENABLE = yes
=======
BOOTMAGIC_ENABLE = yes      # Virtual DIP switch configuration
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = yes        # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover
BACKLIGHT_ENABLE = yes      # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
BLUETOOTH_ENABLE = no       # Enable Bluetooth
AUDIO_ENABLE = no           # Audio output
BACKLIGHT_DRIVER = custom
>>>>>>> e941f048919bba052fd326eadc5acd2347e6756e
VISUALIZER_ENABLE = yes

LED_DRIVER = is31fl3731c
LED_WIDTH = 16
LED_HEIGHT = 5
<<<<<<< HEAD
=======

LAYOUTS = 65_ansi 65_ansi_blocker 65_ansi_blocker_split_bs 65_iso 65_iso_blocker 65_iso_blocker_split_bs

# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
>>>>>>> e941f048919bba052fd326eadc5acd2347e6756e
