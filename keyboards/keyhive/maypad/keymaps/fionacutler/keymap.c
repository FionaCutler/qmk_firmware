/* Copyright 2019 codybender
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
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT_numpad_5x4(
		KC_J,  KC_W,     KC_M,    KC_B,
    	KC_C,                    KC_R,   KC_A,
    	LCTL(LALT(LSFT(KC_H))), LCTL(LALT(LSFT(KC_S))),   LCTL(LALT(LSFT(KC_L))),   LCTL(LALT(LSFT(KC_T))),
    	LCTL(LSFT(KC_Z)), LCTL(KC_N),   LCTL(KC_K),
    	         LCTL(KC_Z),            KC_F, LCTL(KC_S)
	),
};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {

}
