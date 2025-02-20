#include QMK_KEYBOARD_H
#include "version.h"

#include "colors.h"
#include "layers.c"

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT(
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   ,                            KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   ,                            KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
    KC_LALT, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   ,                            KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                                              KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
    KC_LCTL, CW_TOGG, KC_EQL , KC_LEFT, KC_RGHT,        LT(ALT, KC_ESCAPE),          LT(MEDIA, KC_ESCAPE),      KC_UP  , KC_DOWN, KC_RBRC, KC_RBRC, MO(ALT),
//         ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,
                                                 KC_LGUI, KC_SPC , KC_BSPC,          KC_LALT, KC_ESC , KC_ENT
  ),

  [ALT] = LAYOUT(
    KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_TRNS,                            KC_TRNS, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
    KC_TRNS, KC_EXLM, KC_AT  , KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,                            KC_TRNS, KC_UP  , KC_7   , KC_8   , KC_9   , KC_ASTR, KC_F12 ,
    KC_TRNS, KC_HASH, KC_DLR , KC_LPRN, KC_RPRN, KC_GRV , KC_TRNS,                            KC_TRNS, KC_DOWN, KC_4   , KC_5   , KC_6   , KC_PPLS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                                              KC_AMPR, KC_1   , KC_2   , KC_3   , KC_BSLS, KC_TRNS,
    KC_TRNS, KC_COMM, KC_TRNS, KC_TRNS, KC_TRNS,                 RGB_MOD  ,          RGB_TOG,                   KC_TRNS, KC_DOT , KC_0   , KC_EQL , KC_TRNS,
//         ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,
                                                 KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS
                                                   /* RGB_VAD       , RGB_VAI       , TOG_LAYER_CLR , KC_TRNS         , RGB_HUD       , RGB_HUI */
  ),

  [MEDIA] = LAYOUT(
    AU_TOGG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, QK_RBT ,
    MU_TOGG, KC_TRNS, KC_TRNS, MS_UP  , KC_TRNS, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_MPLY, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    MU_NEXT, KC_TRNS, MS_LEFT, MS_DOWN, MS_RGHT, KC_TRNS, KC_TRNS,                            KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, MS_BTN1, MS_BTN2,                   KC_TRNS,          KC_TRNS,                   KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,
//         ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,
                                                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
 ),
};
