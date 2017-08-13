#include "satan.h"

// Used for SHIFT_ESC
#define MODS_CTRL_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))

#define _______ KC_TRNS
#define M_BRTH_TOG 20
#define M_BRTH_INC 21
#define M_BRTH_DEC 22
#define M_BRTH_DEF 23
#define M_RAND_B64 24

enum {
  TD_RWIN = 0
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap 0: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |
   * |-----------------------------------------------------------|
   * |FN2   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '| Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift     |
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |Alt |Gui |FN1 |Ctrl |
   * `-----------------------------------------------------------'
   */
[0] = KEYMAP_ANSI(
  KC_GESC,    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL, KC_BSPC, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC,KC_BSLS, \
  MO(2),   KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,KC_QUOT,         KC_ENT,  \
  KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT, KC_SLSH,         KC_RSFT, \
  KC_LCTL, KC_LGUI,KC_LALT,                KC_SPC,                                 KC_RALT, KC_RGUI, MO(1),  KC_RCTL),

  /* Keymap 1: Function Layer
   * ,-----------------------------------------------------------.
   * | ` | F1| F2| F3| F4| F5| F6| F7| F8| F9| F10| F11| F12| DEL|
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |BL-|BL+|BL   |
   * |-----------------------------------------------------------|
   * | CAPS |   |   |   |   |   |   |       |   |   |   |        |
   * |-----------------------------------------------------------|
   * |       |  |  |CALC|NOTEPAD|VOL-|VOL+|MUTE|MPRV|MNXT|   |        |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
[1] = KEYMAP_ANSI(
  KC_GRV,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_DEL,  \
  _______, KC_NO,  KC_NO,  KC_NO,  M(M_RAND_B64),  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO, KC_NO, KC_NO, \
  KC_CAPS, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,        _______, \
  _______, KC_NO,  M(1),  KC_CALC, M(0),   KC_VOLD,KC_VOLU,KC_MUTE,KC_MPRV,KC_MNXT,KC_WSCH,_______, \
  _______,_______,_______,                _______,                        _______, MO(3), MO(1),_______),

  /* Keymap _FL: Function Layer
   * ,-----------------------------------------------------------.
   * | `~| F1| F2| F3| F4| F5| F6| F7| F8| F9| F10| F11| F12| DEL|
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |BL-|BL+|BL   |
   * |-----------------------------------------------------------|
   * | CAPS |   |   |   |   |   |   |       |   |   |   |        |
   * |-----------------------------------------------------------|
   * |        | F1|F2 | F3|F4 | F5| F6| F7| F8|   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
[2] = KEYMAP_ANSI(
  _______,  M(0),   M(1),   M(2),  M(3),   M(4),   M(5),   M(6),      M(7),   M(8),      M(9),   M(10),   M(11),   _______,  \
  _______,KC_HOME, KC_UP,KC_END, KC_PGUP,KC_NO,KC_NO,KC_MS_BTN1,KC_MS_U,KC_MS_BTN3,KC_PSCR, KC_NO, KC_NO,  KC_NO, \
  MO(2),KC_LEFT,KC_DOWN,KC_RIGHT,KC_PGDN,KC_NO,KC_NO,KC_MS_L,KC_MS_D,KC_MS_R,KC_NO,KC_NO,        _______, \
  _______, KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,_______, \
  _______,_______,_______,                _______,                        _______, KC_NO, _______,_______),

  /* Keymap _FL: Function Layer
   * ,-----------------------------------------------------------.
   * | `~| F1| F2| F3| F4| F5| F6| F7| F8| F9| F10| F11| F12| DEL|
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |BL-|BL+|BL   |
   * |-----------------------------------------------------------|
   * | CAPS |   |   |   |   |   |   |       |   |   |   |        |
   * |-----------------------------------------------------------|
   * |        | F1|F2 | F3|F4 | F5| F6| F7| F8|   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
[3] = KEYMAP_ANSI(
  #ifdef RGBLIGHT_ENABLE
  // UNUSED (I HAVE NO RGB YET)
  _______,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  BL_DEC, BL_INC, KC_NO,  \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,_______,_______, KC_NO,  KC_NO,  KC_NO, \
  _______,_______,_______,_______,_______,_______,_______,_______,_______,BL_TOGG,_______,_______,        _______, \
  _______,RGB_TOG,RGB_MOD,RGB_HUI,RGB_HUD,RGB_SAI,RGB_SAD,RGB_VAI,RGB_VAD,_______,_______,_______, \
  _______,  MO(4),_______,                _______,                        _______, MO(3),_______,_______),
  #else
  _______, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  BL_DEC, BL_INC, KC_NO,  \
  _______, KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO,  KC_NO,  KC_NO, \
  _______, KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,BL_TOGG, KC_NO , KC_NO ,        _______, \
  _______, KC_NO , KC_NO , KC_NO , KC_NO , M(M_BRTH_TOG),M(M_BRTH_DEC),M(M_BRTH_INC),M(M_BRTH_DEF), KC_NO , KC_NO ,_______, \
  _______,  MO(4),_______,                _______,                        _______, MO(3),_______,_______),
  #endif

  /* Keymap _FL: Function Layer
   * ,-----------------------------------------------------------.
   * | `~| F1| F2| F3| F4| F5| F6| F7| F8| F9| F10| F11| F12| DEL|
   * |-----------------------------------------------------------|
   * |     |   |   |   |   |   |   |   |   |   |   |BL-|BL+|BL   |
   * |-----------------------------------------------------------|
   * | CAPS |   |   |   |   |   |   |       |   |   |   |        |
   * |-----------------------------------------------------------|
   * |        | F1|F2 | F3|F4 | F5| F6| F7| F8|   |   |          |
   * |-----------------------------------------------------------|
   * |    |    |    |                        |    |    |    |    |
   * `-----------------------------------------------------------'
   */
[4] = KEYMAP_ANSI(
  _______, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO, RESET,  \
  _______, KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO, KC_NO, KC_NO, \
  _______, KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,        _______, \
  _______, KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO , KC_NO ,_______, \
  _______, MO(4) ,_______,                _______,                        _______,_______,_______,_______),
};


const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {
    case 0: // this would trigger when you hit a key mapped as M(0)
      if (record->event.pressed) {
        return MACRO(D(LGUI), T(R), U(LGUI), W(255), T(N), T(O), T(T), T(E), T(P), T(A), T(D), T(ENTER), END);
      }
      break;

    case 1: // this would trigger when you hit a key mapped as M(0)
      if (record->event.pressed) {
        return MACRO(D(LGUI), T(R), U(LGUI), W(255), T(C), T(M), T(D), T(ENTER), END);
      }
      break;


    case M_BRTH_TOG:
        if (record->event.pressed)
        {
            breathing_toggle();
        }
        break;

    case M_BRTH_INC:
        if (record->event.pressed)
        {
            breathing_speed_inc(1);
        }
        break;

    case M_BRTH_DEC:
        if (record->event.pressed)
        {
            breathing_speed_dec(1);
        }
        break;

    case M_BRTH_DEF:
        if (record->event.pressed)
        {
            breathing_defaults();
        }
        break;

    case M_RAND_B64:
        if (record->event.pressed)
        {
            tap_random_base64();
            tap_random_base64();
            tap_random_base64();
            tap_random_base64();
            tap_random_base64();
            tap_random_base64();
            tap_random_base64();
            tap_random_base64();
            tap_random_base64();
        }
        break;
  }
  return MACRO_NONE;
};
