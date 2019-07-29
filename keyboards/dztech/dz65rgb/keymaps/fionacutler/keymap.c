#include QMK_KEYBOARD_H
#include <stdio.h>
#include <stdlib.h>
#define _LAYER0 0
#define _LAYER1 1
#define _GAMING 2
enum custom_keycodes {
    LARROW = SAFE_RANGE,
    RARROW,
    RANDOM,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
		[_LAYER0] = LAYOUT_65_ansi( /* Base */
			KC_ESC,       KC_1,     KC_2,     KC_3,  KC_4,  KC_5,  KC_6,    KC_7,  KC_8,    KC_9,     KC_0,     KC_MINS,  KC_EQL,  KC_BSPC,    KC_GRV,\
		    KC_TAB,        KC_Q,     KC_W,     KC_E,  KC_R,  KC_T,  KC_Y,    KC_U,  KC_I,    KC_O,     KC_P,     KC_LBRC,  KC_RBRC, KC_BSLASH, KC_DEL,\
			MO(1),       KC_A,     KC_S,     KC_D,  KC_F,  KC_G,  KC_H,    KC_J,  KC_K,    KC_L,     KC_SCLN,  KC_QUOT,           KC_ENT,    KC_PGUP,\
		    KC_LSFT,       KC_Z,     KC_X,     KC_C,  KC_V,  KC_B,  KC_N,    KC_M,  KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,           KC_UP,     KC_PGDN,\
		    KC_LCTRL,         KC_LGUI,  KC_LALT,              KC_SPC,                KC_RALT, MO(1),    KC_RCTL,    KC_LEFT,           KC_DOWN,   KC_RIGHT),
		[_LAYER1] = LAYOUT_65_ansi( /* FN */
			KC_F12,       KC_F1,    KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12,  KC_DEL,     KC_GRV,\
		    KC_CAPSLOCK,   RGB_TOG,  KC_UP, RGB_HUI,RGB_HUD, RGB_TOG, RGB_SAD, RGB_VAI, RGB_VAD, KC_TRNS, KC_PSCR, KC_SLCK,  KC_PAUS, RESET,       KC_DEL,\
			KC_TRNS,       KC_LEFT,  KC_DOWN, KC_RIGHT,KC_TRNS, KC_TRNS, RGB_SAI, RGB_MOD, RGB_HUI, RGB_HUD, KC_TRNS,  KC_TRNS,          EEP_RST,  KC_PGUP,\
		    KC_LSFT,       KC_TRNS,  LARROW, RARROW,KC_TRNS, KC_TRNS, RGB_SPI, RGB_SPD, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,          KC_VOLU,   KC_PGDN,\
		    KC_LCTRL,       KC_TRNS,  KC_TRNS,                  RANDOM,                   KC_TRNS, KC_TRNS, KC_TRNS,  KC_MPRV,          KC_VOLD,   KC_MNXT),
};

void rgb_matrix_indicators_user(void)
{
}

void matrix_init_user(void)
{
  //user initialization
  srand(13213);
}

void matrix_scan_user(void)
{
  //user matrix
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch(keycode) {
        case LARROW:
            if (record->event.pressed){
                SEND_STRING("<-");
            } else {
                //Released
            }
            break;
        case RARROW:
            if (record->event.pressed){
                SEND_STRING("=>");
            } else {
                //Released
            }
            break;
        case RANDOM:
            if (record->event.pressed) {
                int random_value = (rand() % 6) + 1;
                char snum[1];
                itoa(random_value, snum, 10);
                SEND_STRING(snum);
            } else {

            }
            break;
    }
	  return true;
}
