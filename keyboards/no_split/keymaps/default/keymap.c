#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _LEFT 0
#define _RIGHT 1
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 8

#define FLIP   MO(_RIGHT)
#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Left Hand
 * ,-----------------------------------------.
 * | GrEsc|   Q  |   W  |   E  |   R  |   T  |
 * |------+------+------+------+------+------|
 * | Raise|   A  |   S  |   D  |   F  |   G  |
 * |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |
 * |------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Lower| Space| Flip |
 * `-----------------------------------------'
 */
[_LEFT] = LAYOUT_ortho_4x6(
  KC_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T, \
  RAISE,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, \
  KC_LCTL, KC_LGUI, KC_LALT, LOWER,   KC_SPC,  FLIP  \
),

/* "Right" Hand
 * ,-----------------------------------------.
 * | Bkspc|   P  |   O  |   I  |   U  |   Y  |
 * |------+------+------+------+------+------|
 * |   '  |   ;  |   L  |   K  |   J  |   H  |
 * |------+------+------+------+------+------|
 * | Shift|   /  |   .  |   ,  |   M  |   N  |
 * |------+------+------+------+------+------|
 * | Ctrl | GUI  | Alt  | Lower| Space| Flip |
 * `-----------------------------------------'
 */
[_RIGHT] = LAYOUT_ortho_4x6(
  KC_BSPC, KC_P,    KC_O,    KC_I,    KC_U,    KC_Y, \
  KC_QUOT, KC_SCLN, KC_L,    KC_K,    KC_J,    KC_H, \
  KC_RSFT, KC_SLSH, KC_DOT,  KC_COMM, KC_M,    KC_N, \
  KC_RCTL, KC_RGUI, KC_RALT, LOWER,   KC_SPC,  FLIP \
),

/* RAISE
 * ,-----------------------------------------.
 * |      | Home |  Up  | End  | PgUp | MPly |
 * |------+------+------+------+------+------|
 * | Raise| Left | Down | Right| PgDn | VOL+ |
 * |------+------+------+------+------+------|
 * |      |      |      |      | Mute | VOL- |
 * |------+------+------+------+------+------|
 * |      |      |      | Lower|      | Enter|
 * `-----------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x6( \
  XXXXXXX, KC_HOME, KC_UP,   KC_END,  KC_PGUP, KC_MPLY, \
  RAISE,   KC_LEFT, KC_DOWN, KC_RIGHT,KC_PGDN, KC_VOLU, \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, \
  _______, _______, _______, LOWER,   XXXXXXX, KC_ENT \
),

/* LOWER
 * ,-----------------------------------------.
 * |  Del |   1  |   2  |   3  |   4  |   5  |
 * |------+------+------+------+------+------|
 * | Raise|   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------+------|
 * |      |   -  |   =  |  [   |  ]   |  \   |
 * |------+------+------+------+------+------|
 * |      |      |      | Lower|      | Tab  |
 * `-----------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x6( \
  KC_DEL,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5, \
  RAISE,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0, \
  _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
  _______, _______, _______, LOWER,   XXXXXXX, KC_TAB \
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------.
 * |      |      |      |      |      |      |
 * |------+------+------+------+------+------|
 * | Raise|      |      |      |      |      |
 * |------+------+------+------+------+------|
 * |      |      |      |      |      |      |
 * |------+------+------+------+------+------|
 * | Reset|      |      | Lower|      |      |
 * `-----------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x6( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  RAISE,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  RESET,   XXXXXXX, XXXXXXX, LOWER,   XXXXXXX, XXXXXXX \
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
