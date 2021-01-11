# Build Options
#   change yes to no to disable
#
<<<<<<< HEAD

BOOTMAGIC_ENABLE = no           # Virtual DIP switch configuration(+1000)
MOUSEKEY_ENABLE = no            # Mouse keys(+4700)
EXTRAKEY_ENABLE = yes           # Audio control and System control(+450)
CONSOLE_ENABLE = yes            # Console for debug(+400)
COMMAND_ENABLE = yes            # Commands for debug and configuration
NKRO_ENABLE = yes               # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
# BACKLIGHT_ENABLE = no           # Disable keyboard backlight functionality
MIDI_ENABLE = no                # MIDI controls
AUDIO_ENABLE = no               # Audio output on port C6
UNICODE_ENABLE = no             # Unicode
BLUETOOTH_ENABLE = no           # Disable Bluetooth with the Adafruit EZ-Key HID
RGBLIGHT_ENABLE = no          	# Disable RGB underlight
RGBLIGHT_CUSTOM_DRIVER = yes    # RGB code is implemented in lefkeyboards, not WS2812
SLEEP_LED_ENABLE = yes          # Breathing sleep LED during USB suspend
TAP_DANCE_ENABLE = no
=======
AUDIO_ENABLE = no              # Audio output
RGBLIGHT_ENABLE = no           # Enable keyboard RGB underglow
>>>>>>> e941f048919bba052fd326eadc5acd2347e6756e

ISSI_ENABLE = no               # If the I2C pullup resistors aren't install this must be disabled
WATCHDOG_ENABLE = no           # Resets keyboard if matrix_scan isn't run every 250ms


ifeq ($(strip $(ISSI_ENABLE)), yes)
    TMK_COMMON_DEFS += -DISSI_ENABLE
endif

ifeq ($(strip $(WATCHDOG_ENABLE)), yes)
    TMK_COMMON_DEFS += -DWATCHDOG_ENABLE
endif
