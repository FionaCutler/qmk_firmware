#include QMK_KEYBOARD_H
#define _QWERTY 0
#define _COLEMAK 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 4
#define _PLOVER 5

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  LOWER,
  RAISE,
  ALICE,
  TMO,
  PLOVER,
  EXT_PLV,
  LIFEALERT,
  SNOB,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	[_QWERTY] = LAYOUT(
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,    KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_ENT,
		KC_ESC, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,    KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,    KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
		KC_LCTL,  KC_LCTL, KC_LGUI, KC_LALT, LOWER, KC_SPC, KC_BSPC, RAISE,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT),
	[_COLEMAK] = LAYOUT(
		KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,   KC_G,    KC_J,   KC_L,   KC_U,    KC_Y,    KC_SCLN, KC_ENT,
		KC_ESC, KC_A,    KC_R,    KC_S,    KC_T,   KC_D,    KC_H,   KC_N,   KC_E,    KC_I,    KC_O, KC_QUOT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,    KC_K,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
		KC_LCTL,  KC_LCTL, KC_LGUI, KC_LALT, LOWER, KC_SPC, KC_BSPC, RAISE,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT),

	[_LOWER] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_ENT,
        KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),

	[_RAISE] = LAYOUT(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_ENT,
        KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
        _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY),

	[_ADJUST] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, RESET,
        _______, ALICE, _______,   SNOB, TMO,     _______, LIFEALERT, QWERTY,  COLEMAK, PLOVER, _______, EEPROM_RESET,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______),
  [_PLOVER] = LAYOUT(
        KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1,    KC_1   ,
        XXXXXXX, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
        XXXXXXX, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        EXT_PLV, XXXXXXX, XXXXXXX, XXXXXXX, KC_C,    KC_V,    KC_N,    KC_M,    XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX
  )
};


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ALICE:
      if (record->event.pressed) {
        SEND_STRING("Alice is a fucking trash keyboard with the all time worst set of compromises to ergonomics.\r\nWhile the Alice splits, it fails to address the row stagger problem (either by getting rid of it like Ergodoxes or reversing it on the left hand like the Topre ergo board) and fails to introduce any significant columnular stagger.\r\nI can forgive boards like the standard Microsoft ergo boards for this because they keep everything in place such that it could be used by someone expecting their computer to be used by several people without causing any interruption to anyone's muscle memory. But the Alice changes enough of the thumb use to spoil any general public usability gains. What's left is a half measure of a committment that goes far enough to make turning back difficult but not far enough to do any real good.\n");
      }
      break;
    case LIFEALERT:
     if(record->event.pressed){
       SEND_STRING("Fiona has fallen out of her chair and is not available right now, please leave a message after the tone. BEEP!\n");
     }
     break;
    case TMO:
      if (record->event.pressed) {
          SEND_STRING("HERE WE GO BOYS TMO50 layout is the greatest thing ever let me tell you sir. First of all class ic inspirations on the HHKB blocker style IT also has the ; and ' kjeys unless other competitors in the 40% space which I find completely unreplaceable in layers it also has extra keys for macros (read: artisans- I absolutely love the layout where you have numbers/!@#$\%^ that replace qwerty it means i can type for long periods of time wihtout twisting my hands at all whereas on a normal board you ahve to twist your wrists sometimes to type for me I just have to hold down left space and click asdf to get to numbers It's also just gorgeous IMO Ano quality is good, engraving is good, I like how he made it so you can buy a 40% sized board/layout but not need to buy 40% sized modifiers for your keyboard so you can use base kits and uh yeah that's it That's why TMO50 is my every day board I literally am typing on it right now and have used it every single day at work for the last 4 months 0 inftention to ever stop\n");
      }
      break;
    case SNOB:
        if(record->event.pressed){
            SEND_STRING("Ugh, must I always be surrounded by bird-brains and nincompoops? Sometimes it seems like none of the amateurs in this community can understand the subtle art of the human-computer interface. Let me paint this picture very slowly and deliberately for you. Lounging here retroflecting on my week; swirling a bit of Audry XO (neat, as God himself intended, haha) on my palate; loosening up and undoing one button at a time from my TOM FORD O'Connor in shark-skin (yes that's the same suit worn by James fucking Bond AKA Daniel Craig, thank you); there's a smokeless incense of clove and as I inhale deeply I can feel the troubles of my very difficult, mentally taxing job melt away. Are you beginning to see what kind of man I am? Can you take a gander what kind of HCI I use? No it is not some wannabe JLCPCB ergo trash board glued together by some flux-coughing neckbeard in his mom's basement.  I'm sure you've guessed by this point, but in case you're a bit slow let me give you another hint. It has stealthy flow like the wisps of incense snaking invisibly across my foyer. It has bold character like the high-class cognac still warming my throat. And just like my suit it's fucking expensive and you wish you could have one. That's right I'm talking about the TGR fucking Alice. \"But wait,\" you protest, oh ye of feeble mind,\n\"but I see a lot of Alice clones on mechmarket these days, what makes you so special?\" EVERYTHING. Hoho, but I digress, in this particular case (pun intended!) it's not a clone, nor simply the original, for even that is too quaint a trinket for me to yield even a crumb of my attention. This is an EXCLUSIVE tungsten carbide limited POWDER COATED edition sold exclusively in a private Vickery auction for literally 5 figures (sorry I can't tell you who ran it, of course I had to sign an NDA, but let me just say you know him if you are anyone at all in the upper echelons of the community) with a matching set of Burble Dweezil artisans. And by the way the switches are REAL Invyr Pandas I happily collected for under $5 a piece before the market was flooded with inferior knockoffs. As you can tell I am a man of suave and candor so imagine my horror at the shockingly ignorant DMs I received on Reddit tonight and how they simultaneously ruined my night and destroyed any hope I have for the redemption of this highly toxic group of lowlives we call \"enthusiasts\". One little fucking comment I made praising the Alice on an \"ergo\" thread and suddenly my inbox is flooded with \"Alice is a half measure,\" ugg, \"worst set of compromises to ergonomics,\" ugg, \"fails to introduce any significant columnular stagger,\" ugg ugg, you half-witted brutish cavemen. Then it came it, and turned my relaxing night upside down. The message that made me gag on my own bile and spill XO all over my crisp, fresh suit. \"ALiCe iS A fuCkIng trASsh keybboard,\" are you kidding me? Am I dealing with a bunch of children here? I'm absolutely done with you plebs, I won't socialize with a bunch of poor hipsters who can't even afford a full set of 60 keys. Goodbye and good riddance, I won't be abused by your toxic mob mentality one minute longer. DM me when you grow up and learn some basic class, or on second thought, don't, you couldn't afford my time.\n");
        }
    break;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_COLEMAK);
      }
      return false;
      break;
    case PLOVER:
      if (record->event.pressed) {
        layer_off(_RAISE);
        layer_off(_LOWER);
        layer_off(_ADJUST);
        layer_on(_PLOVER);
        if (!eeconfig_is_enabled()) {
            eeconfig_init();
        }
        keymap_config.raw = eeconfig_read_keymap();
        keymap_config.nkro = 1;
        eeconfig_update_keymap(keymap_config.raw);
      }
      return false;
      break;
    case EXT_PLV:
      if (record->event.pressed) {
        layer_off(_PLOVER);
      }
      return false;
      break;
  }
  return true;
}
