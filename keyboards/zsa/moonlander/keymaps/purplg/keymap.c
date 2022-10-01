#include QMK_KEYBOARD_H
#include "version.h"
#include "print.h"

#include "aliases.h"
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
    ALT,
    MEDIA,
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
    KC_GRAVE      , KC_1          , KC_2          , KC_3          , KC_4          , KC_5          , KC_6          ,                                 KC_5          , KC_6          , KC_7          , KC_8          , KC_9          , KC_0          , KC_MINUS      ,       
    KC_TAB        , KC_Q          , KC_W          , KC_E          , KC_R          , KC_T          , KC_Y          ,                                 KC_T          , KC_Y          , KC_U          , KC_I          , KC_O          , KC_P          , KC_BSLASH     ,      
    KC_LALT       , KC_A          , KC_S          , KC_D          , KC_F          , KC_G          , KC_H          ,                                 KC_G          , KC_H          , KC_J          , KC_K          , KC_L          , KC_SCOLON     , KC_QUOTE      ,
    KC_LSHIFT     , KC_Z          , KC_X          , KC_C          , KC_V          , KC_B          ,                                                                 KC_N          , KC_M          , KC_COMMA      , KC_DOT        , KC_SLASH      , KC_RSHIFT     ,      
    KC_LCTRL      , CAPS_WORD     , KC_EQUAL      , KC_LEFT       , KC_RIGHT      ,                      LT(ALT, KC_ESCAPE),             LT(MEDIA, KC_ESCAPE),                      KC_UP         , KC_DOWN       , KC_LBRACKET   , KC_RBRACKET   , MO(ALT)       ,          
//                ,               ,               ,               ,               ,               ,               ,               ,               ,               ,               ,               ,               ,               ,               ,               ,
                                                                                    KC_LGUI       , KC_SPACE      , KC_BSPACE     , KC_LALT       , KC_ESCAPE     , KC_ENTER
  ),

  [ALT] = LAYOUT_moonlander(
    KC_ESCAPE     , KC_F1         , KC_F2         , KC_F3         , KC_F4         , KC_F5         , KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_F6         , KC_F7         , KC_F8         , KC_F9         , KC_F10        , KC_F11        ,
    KC_TRANSPARENT, KC_EXLM       , KC_AT         , KC_LCBR       , KC_RCBR       , KC_PIPE       , KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_UP         , KC_7          , KC_8          , KC_9          , KC_ASTR       , KC_F12        ,
    KC_TRANSPARENT, KC_HASH       , KC_DLR        , KC_LPRN       , KC_RPRN       , KC_GRAVE      , KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_DOWN       , KC_4          , KC_5          , KC_6          , KC_KP_PLUS    , KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_CIRC       , KC_LBRACKET   , KC_RBRACKET   , KC_TILDE      ,                                                                 KC_AMPR       , KC_1          , KC_2          , KC_3          , KC_BSLASH     , KC_TRANSPARENT,
    KC_TRANSPARENT, KC_COMMA      , KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                 RGB_MOD       ,                                 RGB_TOG,                        KC_TRANSPARENT, KC_DOT,         KC_0,           KC_EQUAL,       KC_TRANSPARENT, 
//                ,               ,               ,               ,               ,               ,               ,               ,               ,               ,               ,               ,               ,               ,               ,               ,
                                                                                    RGB_VAD       , RGB_VAI       , TOG_LAYER_CLR , KC_TRANSPARENT, RGB_HUD       , RGB_HUI
  ),

  [MEDIA] = LAYOUT_moonlander(
    AU_TOG        , KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, RESET         ,          
    MU_TOG        , KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_UP      , KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PLAY_PAUSE , KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    MU_MOD        , KC_TRANSPARENT, KC_MS_LEFT    , KC_MS_DOWN    , KC_MS_RIGHT   , KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_PREV_TRACK , KC_NEXT_TRACK , KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_PLAY_PAUSE ,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN1    , KC_MS_BTN2    ,                 KC_TRANSPARENT,                                 KC_TRANSPARENT,                 KC_VOL_UP     , KC_VOL_DOWN   , KC_MUTE       , KC_TRANSPARENT, KC_TRANSPARENT, 
//                ,               ,               ,               ,               ,               ,               ,               ,               ,               ,               ,               ,               ,               ,               ,               ,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_WWW_BACK
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
        case ALT:
            rgb_set_alpha(MOD_KEYCOLOR);
            break;
        case MEDIA:
            rgb_matrix_set_color_all(0, 0, 0);
            rgb_set_media(MOD_KEYCOLOR);
            rgb_matrix_set_color(62, media_rgb[0], media_rgb[1], media_rgb[2]);
            break;
    }
}
