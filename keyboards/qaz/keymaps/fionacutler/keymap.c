#include QMK_KEYBOARD_H

enum layers{
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST
};
enum combo_events {
  COMBO_BSPC,
  COMBO_ENT,
  COMBO_TAB,
  COMBO_ESC,
  COMBO_DEL
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_split_space(
    KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,    KC_I,   KC_O, KC_P,
    KC_A,  KC_S,  KC_D,  KC_F,   KC_G,   KC_H,  KC_J,   KC_K,  KC_L, KC_QUOTE,
    LSFT_T(KC_Z),   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M, KC_COMM, RSFT_T(KC_DOT),
    KC_LCTL, KC_LALT,  KC_BSPC, LT(_LOWER, KC_SPACE), LT(_RAISE,KC_ENT), KC_DEL, KC_RGUI, KC_RCTL
  ),

  [_LOWER] = LAYOUT_split_space(
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0,
    KC_TAB, KC_F1, KC_F2, KC_F3, KC_SCLN, KC_SCLN,KC_MINUS, KC_EQUAL, KC_LBRC, KC_RBRC,
    KC_LSFT, KC_LBRC, KC_LPRN, KC_UNDS, KC_COLON, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [_RAISE] = LAYOUT_split_space(
    KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
    KC_F12,KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
    KC_F11, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_RCBR,KC_SLASH, KC_QUES,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [_ADJUST] = LAYOUT_split_space(
    KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, EEP_RST,
    KC_TAB, KC_F1, KC_F2, KC_F3, KC_PERC, KC_CIRC, KC_LEFT, KC_DOWN, KC_UP, RESET,
    KC_LSFT, KC_LBRC, KC_LPRN, KC_UNDS, KC_RPRN, KC_RBRC, KC_RCBR, KC_SCLN, KC_RSFT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_bspc[] = {KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM combo_ent[] = {KC_L, KC_QUOT, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_E, KC_W, COMBO_END};
const uint16_t PROGMEM combo_del[] = {KC_MINS, KC_EQL, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_BSPC] = COMBO(combo_bspc,KC_BSPC),
  [COMBO_ENT] = COMBO(combo_ent,KC_ENT),
  [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
  [COMBO_ESC] = COMBO(combo_esc,KC_ESC),
  [COMBO_DEL] = COMBO(combo_del,KC_DEL),

};
#endif
