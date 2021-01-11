# MCU name
MCU = STM32F103

MCU_LDSCRIPT = jm60_bootloader
BOARD = JM60_BOARD

<<<<<<< HEAD
# Cortex version
# Teensy LC is cortex-m0; Teensy 3.x are cortex-m4
MCU  = cortex-m3

# ARM version, CORTEX-M0/M1 are 6, CORTEX-M3/M4/M7 are 7
# I.e. 6 for Teensy LC; 7 for Teensy 3.x
ARMV = 7

# Vector table for application
# 0x00000000-0x00001000 area is occupied by bootlaoder.*/
# The CORTEX_VTOR... is needed only for MCHCK/Infinity KB
#OPT_DEFS = -DCORTEX_VTOR_INIT=0x00001000
OPT_DEFS = 

=======
>>>>>>> upstream/master
# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = full     # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no       # Breathing sleep LED during USB suspend
# if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes           # USB Nkey Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
BLUETOOTH_ENABLE = no       # Enable Bluetooth
AUDIO_ENABLE = no           # Audio output

<<<<<<< HEAD
#LED_DRIVER = is31fl3731c
#LED_WIDTH = 16 
#LED_HEIGHT = 5
=======
# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE

<<<<<<< HEAD
# project specific files
SRC = matrix.c \
      led.c
>>>>>>> upstream/master
=======
LAYOUTS = 60_ansi
>>>>>>> e941f048919bba052fd326eadc5acd2347e6756e
