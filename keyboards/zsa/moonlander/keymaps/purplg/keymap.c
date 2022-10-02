#include QMK_KEYBOARD_H
#include "version.h"
#include "print.h"

#include "colors.h"

#define LENGTH(arr) sizeof(arr) / sizeof(uint16_t)

uint8_t media_rgb[] = {MOD_KEYCOLOR};

enum event {
    event_NONE  = 0,
    event_MEDIA = 1,
};

enum media_state {
    media_PAUSED  = 0,
    media_PLAYING = 1,
};

enum layers {
    BASE = 0,
    SYMB,
    MDIA,
};

/*
  00, 05, 10, 15, 20, 25, 29,         65, 61, 56, 51, 46, 41, 36,
  01, 06, 11, 16, 21, 26, 30,         66, 62, 57, 52, 47, 42, 37,
  02, 07, 12, 17, 22, 27, 31,         67, 63, 58, 53, 48, 43, 38,
  03, 08, 13, 18, 23, 28,                 64, 59, 54, 49, 44, 39,
  04, 09, 14, 19, 24,     35,         71,     60, 55, 50, 45, 40,
                        32,33,34, 70,69,68,
*/

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_moonlander(
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   ,                   KC_5   , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,       
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_Y   ,                   KC_T   , KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
    KC_LALT, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , KC_H   ,                   KC_G   , KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                                     KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,      
    KC_LCTL, CAPSWRD, KC_EQL , KC_LEFT, KC_RGHT,          LT(SYMB, KC_ESC), LT(MDIA, KC_ESC)         , KC_UP  , KC_DOWN, KC_LBRC, KC_RBRC, KC_RCTL,
//         ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,
                                                 KC_LGUI, KC_SPC , KC_BSPC, KC_LALT, KC_ESC , KC_ENT
  ),

  [SYMB] = LAYOUT_moonlander(
    KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , _______,                   _______, KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
    _______, KC_EXLM, KC_AT  , KC_LCBR, KC_RCBR, KC_PIPE, _______,                   _______, KC_UP  , KC_7   , KC_8   , KC_9   , KC_ASTR, KC_F12 ,
    _______, KC_HASH, KC_DLR , KC_LPRN, KC_RPRN, KC_GRV , _______,                   _______, KC_DOWN, KC_4   , KC_5   , KC_6   , KC_PPLS, _______, 
    _______, _______, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD,                                     KC_AMPR, KC_1   , KC_2   , KC_3   , KC_BSLS, _______,
    _______, KC_COMM, _______, _______, _______,              RGB_MOD,           RGB_TOG,              _______, KC_DOT , KC_0   , KC_EQL , _______, 
//         ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,
                                                 RGB_VAD, RGB_VAI, _______, _______, RGB_HUD, RGB_HUI
  ),

  [MDIA] = LAYOUT_moonlander(
    AU_TOG , _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, RESET  ,
    MU_TOG , KC_BTN1, KC_MS_U, KC_BTN2, _______, _______, _______,                   _______, KC_MPLY, _______, _______, _______, _______, _______, 
    MU_MOD , KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______,                   _______, KC_MPRV, KC_MNXT, _______, _______, _______, KC_MPLY,
    _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______, 
    _______, _______, _______, _______, _______,             _______,            _______,              KC_VOLU, KC_VOLD, KC_MUTE, _______, _______, 
//         ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,
                                                 _______, _______, _______, _______, _______, _______
 ),
};

const uint16_t PROGMEM left_keys[] = {
   0,  5, 10, 15, 20, 25, 29,
   1,  6, 11, 16, 21, 26, 30,
   2,  7, 12, 17, 22, 27, 31,
   3,  8, 13, 18, 23, 28,
   4,  9, 14, 19, 24,     35,
                        32,33,34,
};

const uint16_t PROGMEM right_keys[] = {
                                      65, 61, 56, 51, 46, 41, 36,
                                      66, 62, 57, 52, 47, 42, 37,
                                      67, 63, 58, 53, 48, 43, 38,
                                          64, 59, 54, 49, 44, 39,
                                      71,     60, 55, 50, 45, 40,
                                  70,69,68,
};

const uint16_t PROGMEM media_keys[] = {

                                          62,
                                          63, 58,




};

const uint16_t PROGMEM num_keys[] = {
       5, 10, 15, 20, 25,                 61, 56, 51, 46, 41,




};

const uint16_t PROGMEM alpha_keys[] = {

       6, 11, 16, 21, 26,                 62, 57, 52, 47, 42,
       7, 12, 17, 22, 27,                 63, 58, 53, 48, 43,
       8, 13, 18, 23, 28,                 64, 59, 54, 49, 44,

};

const uint16_t PROGMEM wasd_keys[] = {

          11,
       7, 12, 17,



};

const uint16_t PROGMEM mod_keys[] = {


   2,
   3,
   4,
                        32,       70,
};

const uint16_t PROGMEM layer_keys[] = {




                          35,         71,

};

const void rgb_set_keys(const uint16_t keys[], uint8_t num_keys, uint8_t red, uint8_t green, uint8_t blue) {
  for (int i = 0; i < num_keys; i++) {
    rgb_matrix_set_color(keys[i], red, green, blue);
  }
}

const void rgb_set_left(uint8_t red, uint8_t green, uint8_t blue) {
  rgb_set_keys(left_keys, LENGTH(left_keys), red, green, blue);
}

const void rgb_set_right(uint8_t red, uint8_t green, uint8_t blue) {
  rgb_set_keys(right_keys, LENGTH(right_keys), red, green, blue);
}

const void rgb_set_media(uint8_t red, uint8_t green, uint8_t blue) {
  rgb_set_keys(media_keys, LENGTH(media_keys), red, green, blue);
}

const void rgb_set_num(uint8_t red, uint8_t green, uint8_t blue) {
  rgb_set_keys(num_keys, LENGTH(num_keys), red, green, blue);
}

const void rgb_set_alpha(uint8_t red, uint8_t green, uint8_t blue) {
  rgb_set_keys(alpha_keys, LENGTH(alpha_keys), red, green, blue);
}

const void rgb_set_wasd(uint8_t red, uint8_t green, uint8_t blue) {
  rgb_set_keys(wasd_keys, LENGTH(wasd_keys), red, green, blue);
}

const void rgb_set_mod(uint8_t red, uint8_t green, uint8_t blue) {
  rgb_set_keys(mod_keys, LENGTH(mod_keys), red, green, blue);
}

const void rgb_set_layer(uint8_t red, uint8_t green, uint8_t blue) {
  rgb_set_keys(layer_keys, LENGTH(layer_keys), red, green, blue);
}

void keyboard_post_init_user(void) {
  debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

void set_media_state(uint8_t state) {
    switch (state) {
        case media_PAUSED:
            media_rgb[0] = 0xFF;
            media_rgb[1] = 0x00;
            media_rgb[2] = 0x00;
            break;
        case media_PLAYING:
            media_rgb[0] = 0x00;
            media_rgb[1] = 0xFF;
            media_rgb[2] = 0x00;
            break;
    }
}

void raw_hid_receive(uint8_t *data, uint8_t length) {
    uprintf("received hid data: ");
    for (int i = 0; i < length; i++) {
        uprintf("%u", data[i]);
    }
    uprintf("\n");
    switch (data[0]) {
        case event_NONE:
            break;

        case event_MEDIA:
            set_media_state(data[1]);
            break;

        default:
            uprintf("Unknown event: %u\n", data[0]);
    }
}

void rgb_matrix_indicators_user(void) {
    switch (get_highest_layer(layer_state)) {
        case BASE:
            rgb_matrix_set_color_all(0, 0, 0);
            rgb_set_num(NUM_KEYCOLOR);
            rgb_set_alpha(ALPHA_KEYCOLOR);
            rgb_set_wasd(WASD_KEYCOLOR);
            rgb_set_mod(MOD_KEYCOLOR);
            rgb_set_layer(LAYER_KEYCOLOR);
            break;
        case SYMB:
            rgb_set_alpha(MOD_KEYCOLOR);
            break;
        case MDIA:
            rgb_matrix_set_color_all(0, 0, 0);
            rgb_set_media(MOD_KEYCOLOR);
            rgb_matrix_set_color(62, media_rgb[0], media_rgb[1], media_rgb[2]);
            break;
    }
}
