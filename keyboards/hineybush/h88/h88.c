/* Copyright 2019 Josh Hinnebusch
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "h88.h"

void matrix_init_kb(void) {
	// put your keyboard start-up code here
	// runs once when the firmware starts up
	setPinOutput(D5);
	setPinOutput(E6);
	matrix_init_user();
}

void matrix_scan_kb(void) {
	// put your looping keyboard code here
	// runs every cycle (a lot)

	matrix_scan_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
	// put your per-action keyboard code here
	// runs for every action, just before processing by the firmware

	return process_record_user(keycode, record);
}

void led_set_kb(uint8_t usb_led) {
	// put your keyboard LED indicator (ex: Caps Lock LED) toggling code here

	led_set_user(usb_led);
}

bool led_update_kb(led_t led_state) {
    if(led_update_user(led_state)) {
        writePin(D5, !led_state.caps_lock);
        writePin(E6, !led_state.scroll_lock);
    }
    return true;
}

<<<<<<< HEAD
void led_set_user(uint8_t usb_led) {

  if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
    setPinOutput(D5);
    writePinLow(D5);
  } else {
    setPinInput(D5);
    writePinLow(D5);
  }

  if (IS_LED_ON(usb_led, USB_LED_SCROLL_LOCK)) {
    setPinOutput(E6);
    writePinLow(E6);
  } else {
    setPinInput(E6);
    writePinLow(E6);
  }
=======
void eeconfig_init_kb(void) {  // EEPROM is getting reset!
  rgblight_enable(); // Enable RGB by default
  rgblight_sethsv(0, 255, 128);  // Set default HSV - red hue, full saturation, medium brightness
  rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL + 2); // set to RGB_RAINBOW_SWIRL by default
>>>>>>> e941f048919bba052fd326eadc5acd2347e6756e

  eeconfig_update_kb(0);
  eeconfig_init_user();
}
