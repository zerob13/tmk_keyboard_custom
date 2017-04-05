#include "keymap_common.h"

/*
 * HHKB Layout
 */
const uint8_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 0: Default layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|
     * |-----------------------------------------------------------|
     * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Bspc |
     * |-----------------------------------------------------------|
     * |Ctrl  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return  |
     * |-----------------------------------------------------------|
     * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift |Fn |
     * |-----------------------------------------------------------|
     * |    |Alt |Gui |      Space             |Gui |Alt |    |    |
     * `-----------------------------------------------------------'
     */
    KEYMAP_HHKB(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,   MINS,EQL, BSLS, GRV, \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,   LBRC,RBRC,BSPC,      \
        LCTL,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN,QUOT,     ENT,       \
        LSFT,Z,   X,   C,   V,   B,   N,   M,   COMM,DOT, SLSH,     RSFT,FN0,       \
        NO,  LALT,LGUI,          SPC,                     RGUI,RALT,NO,NO),
    /* 1: dvorak layer
     * ,-----------------------------------------------------------.
     * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  [|  ]|  \|  `|
     * |-----------------------------------------------------------|
     * |Tab  |  '|  ,|  .|  P|  Y|  F|  G|  C|  R|  L|  /|  =|Bspc |
     * |-----------------------------------------------------------|
     * |Ctrl  |  A|  O|  E|  U|  I|  D|  H|  T|  N|  S|  -|Return  |
     * |-----------------------------------------------------------|
     * |Shift   |  ;|  Q|  J|  K|  X|  B|  M|  W|  V|  Z|Shift |Fn |
     * |-----------------------------------------------------------|
     * |    |Alt |Gui |      Space             |Gui |Alt |    |    |
     * `-----------------------------------------------------------'
     */
    KEYMAP_HHKB(
        ESC, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,LBRC,RBRC,BSLS,GRV,\
        TAB, QUOT,COMM,DOT, P,   Y,   F,   G,   C,   R,   L,SLSH,EQL,BSPC,\
        LCTL,A,   O,   E,   U,   I,   D,   H,   T,   N,   S,MINS,ENT,\
        LSFT,SCLN,   Q,   J,   K,   X,   B,   M,   W, V, Z,RSFT,FN0,\
        NO,  LALT,LGUI,          SPC,                     RGUI,RALT,NO,NO),
    /* 2: HHKB Fn layer
     * ,-----------------------------------------------------------.
     * |Pwr| F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|Ins|Del|
     * |-----------------------------------------------------------|
     * |Caps |   |   |   |   |   |   |   |Psc|Slk|Pus|Up |   |     |
     * |-----------------------------------------------------------|
     * |      |VoD|VoU|Mut|Ejc|   |  *|  /|Hom|PgU|Lef|Rig|Enter   |
     * |-----------------------------------------------------------|
     * |        |   |   |   |   |   |  +|  -|End|PgD|Dow|      |   |
     * |-----------------------------------------------------------|
     * |    |    |    |                        |    |    |    |    |
     * `-----------------------------------------------------------'
     */
    KEYMAP_HHKB(
        PWR, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10, F11, F12, INS, DEL,\
        CAPS,TRNS,TRNS,TRNS,MSEL,MPRV,MPLY,MNXT,PSCR,SLCK,PAUS,UP,  TRNS,TRNS,\
        RCTL,VOLD,VOLU,MUTE,EJCT,TRNS,PAST,PSLS,HOME,PGUP,LEFT,RGHT, PENT,\
        TRNS,TRNS,FN4,FN1,FN2,FN3,PPLS,PMNS,END, PGDN,DOWN,     TRNS,TRNS,\
        TRNS,TRNS,TRNS,          FN5,                    TRNS,TRNS,TRNS,TRNS),

};

enum macro_id {
    MAIL,
};
/*
 * Fn action definition
 */
const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_LAYER_MOMENTARY(2),
    [1] = ACTION_BACKLIGHT_TOGGLE(),
    [2] = ACTION_BACKLIGHT_DECREASE(),
    [3] = ACTION_BACKLIGHT_INCREASE(),
    [4] = ACTION_BACKLIGHT_STEP(),
    [5] = ACTION_MACRO(MAIL),
    //[6] = ACTION_LAYER_TOGGLE(1),
};

/*
 * Macro definition
 */
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch (id) {
        case MAIL:
            return (record->event.pressed ?
                    MACRO( I(0), T(I),D(LSFT), T(2), U(LSFT), T(Z), T(E), T(R), T(O), T(B), T(1), T(3), T(DOT), T(I), T(N), END ) :
                    MACRO_NONE );
    }
    return MACRO_NONE;
}
