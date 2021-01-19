#include QMK_KEYBOARD_H

enum layer_names {
  _QWERTY,
  _COLEMAK,
  _DVORAK,
  _LOWER,
  _RAISE,
  _MOUSE,
  _ADJUST,
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE
};

#define MOUSE  MO(_MOUSE)
#define ESC_UT LT(_UTIL, KC_ESC)
#define SPC_LO LT(_LOWER, KC_ENT)
#define SPC_RA LT(_RAISE, KC_SPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_arrow(
KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
KC_LCTL, KC_LALT, KC_LGUI,                   SPC_RA,  SPC_LO,           MOUSE,   KC_LBRC, KC_RBRC, XXXXXXX
),


/* Lower
* ,--------------------------------------------------------------------------.
* |   ~  |  !  |  @  |  #  |  $  |  %  |  ^  |  &  |  *  |  (  |  )  |  Del  |
* |------`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----`-------|
* | Del   | F1  | F2  | F3  | F4  | F5  | F6  |  _  |  +  |  {  |  }  |   |  |
* |-------`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----`------|
* |        | F7  | F8  | F9  | F10 | F11 | F12 |ISO ~|ISO ||     |     |     |
* |--------`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----|
* |      |      |       |             |             | Next |Vol- |Vol+ |Play |
* `--------------------------------------------------------------------------'
*/
[_LOWER] = LAYOUT_arrow(
KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_PIPE,
_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,S(KC_NUHS),S(KC_NUBS),_______, _______, _______,
_______, _______, _______,                   _______, _______,          KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
* ,--------------------------------------------------------------------------.
* |   `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  Del  |
* |------`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----`-------|
* | Del   | F1  | F2  | F3  | F4  | F5  | F6  |  -  |  =  |  [  |  ]  |   \  |
* |-------`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----`------|
* |        | F7  | F8  | F9  | F10 | F11 | F12 |ISO #|ISO /|     |     |     |
* |--------`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----|
* |      |      |       |             |             | Next |Vol- |Vol+ |Play |
* `--------------------------------------------------------------------------'
*/
[_RAISE] = LAYOUT_arrow(
KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, _______,
_______, _______, _______,                   _______, _______,          KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
),

/* Mouse
* ,--------------------------------------------------------------------------.
* |      |     | M U |     |     |     |     |     |     |L Clk|R Clk| W Up  |
* |------`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----`-------|
* |       | M L | M D | M R |     |     |     |     |     |     |     |W Dwn |
* |-------`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----`------|
* |        |     |     |     |     |     |     |     |     |     |     |     |
* |--------`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----|
* |      |      |       |             |             |      |     |     |     |
* `--------------------------------------------------------------------------'
*/
[_MOUSE] = LAYOUT_arrow(
XXXXXXX, XXXXXXX, KC_MS_U, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_BTN1, KC_BTN2, KC_WH_U,
XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_D,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Adjust
* ,--------------------------------------------------------------------------.
* |      |     |     |     |     |QWRTY|COLMK|DVRAK|     |     |     | RESET |
* |------`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----`-------|
* |       |     |     |     |     |     |     |     |     |     |     |      |
* |-------`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----`------|
* |        |     |     |     |     |     |     |     |     |     |     |     |
* |--------`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----`-----|
* |      |      |       |             |             |      |     |     |     |
* `--------------------------------------------------------------------------'
*/
[_ADJUST] = LAYOUT_arrow(
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QWERTY,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RESET,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX,          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)


};

void keyboard_post_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
    // set up rgb effects on only the third led (index 2)
    //rgblight_set_effect_range(2, 1);

    // set led effects to breathing mode in yellow
    //rgblight_sethsv_noeeprom(36,255,100);
    //rgblight_mode_noeeprom(RGBLIGHT_EFFECT_BREATHING + 2);

    // set other led's to off
    setrgb(0, 0, 0, (LED_TYPE *)&led[0]);
    setrgb(0, 0, 0, (LED_TYPE *)&led[1]);
    setrgb(0, 0, 0, (LED_TYPE *)&led[2]);
    rgblight_set();
  #endif
}

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  /* #ifdef RGBLIGHT_ENABLE
    if (layer_state_cmp(state, _ADJUST)) {
      setrgb(255, 70, 100, (LED_TYPE *)&led[0]);
      setrgb(70, 255, 200, (LED_TYPE *)&led[1]);
    } else if (layer_state_cmp(state, _LOWER)) {
      setrgb(0, 0, 0, (LED_TYPE *)&led[0]);
      setrgb(70, 255, 200, (LED_TYPE *)&led[1]);
    } else if (layer_state_cmp(state, _RAISE)) {
      setrgb(255, 70, 100, (LED_TYPE *)&led[0]);
      setrgb(0, 0, 0, (LED_TYPE *)&led[1]);
    } else if (layer_state_cmp(state, _MOUSE)) {
      setrgb(255, 145, 5, (LED_TYPE *)&led[0]);
      setrgb(255, 145, 5, (LED_TYPE *)&led[1]);
    } else {
      setrgb(0, 0, 0, (LED_TYPE *)&led[0]);
      setrgb(0, 0, 0, (LED_TYPE *)&led[1]);
    }

    rgblight_set();
  #endif */

  return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
  }
  return true;
}
