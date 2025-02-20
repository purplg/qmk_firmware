#include QMK_KEYBOARD_H
#include "version.h"
#include "raw_hid.h"

#ifdef DEBUG
#include "print.h"
#endif

#include "colors.h"

#define LENGTH(arr) sizeof(arr) / sizeof(uint16_t)

#define WS_NUM_DISPLAYS 2
#define WS_NUM_WS 4

uint8_t hid_buffer[32] = {0};

typedef bool ws_state[WS_NUM_DISPLAYS * WS_NUM_WS];

uint8_t workspaces[WS_NUM_DISPLAYS * WS_NUM_WS] = {
    06, 11, 16, 21, 07, 12, 17, 22,
};

// clang-format off
bool workspace_state[WS_NUM_DISPLAYS * WS_NUM_WS] = {
    false, false, false, false,
    false, false, false, false,
};
// clang-format on

uint8_t media_rgb[] = {MOD_KEYCOLOR};

#define MAX_VOLUME 5
uint8_t current_volume = 0;

enum custom_keys {
    VOL_1 = SAFE_RANGE,
    VOL_2,
    VOL_3,
    VOL_4,
    VOL_5,
};

enum event {
    event_NONE      = 0,
    event_MEDIA     = 1,
    event_WORKSPACE = 2,
    event_VOLUME    = 3,
};

enum media_state {
    media_PAUSED  = 0,
    media_PLAYING = 1,
};

enum layers {
    L_QWRTY = 0,
    L_WRKMN,
    L_COLMK,
    L_SYMB,
    L_NUMB,
    L_MDIA,
};

/*
  00, 05, 10, 15, 20, 25, 29,         65, 61, 56, 51, 46, 41, 36,
  01, 06, 11, 16, 21, 26, 30,         66, 62, 57, 52, 47, 42, 37,
  02, 07, 12, 17, 22, 27, 31,         67, 63, 58, 53, 48, 43, 38,
  03, 08, 13, 18, 23, 28,                 64, 59, 54, 49, 44, 39,
  04, 09, 14, 19, 24,     35,         71,     60, 55, 50, 45, 40,
                        32,33,34, 70,69,68,
*/

// clang-format off

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [L_QWRTY] = LAYOUT(
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   ,                   KC_EQL , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_MINS,
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , MO(L_NUMB),                _______, KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
    KC_LALT, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   , MO(L_SYMB),             MO(L_MDIA), KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                                     KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
    KC_LCTL, _______, _______, KC_DOWN, KC_UP  ,          KC_ESC,                     KC_ESC         , KC_LEFT, KC_RGHT, KC_LBRC, KC_RBRC, _______,
//         ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,
                                                 KC_SPC, KC_LGUI , KC_BSPC,          KC_LALT, KC_ESC , KC_ENT
  ),

[L_WRKMN] = LAYOUT(
  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_6   ,                   KC_EQL , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
  KC_TAB , KC_Q   , KC_D   , KC_R   , KC_W   , KC_B   , MO(L_NUMB),                KC_MINS, KC_J   , KC_F   , KC_U   , KC_P   , KC_SCLN, KC_BSLS,
  KC_LALT, KC_A   , KC_S   , KC_H   , KC_T   , KC_G   , MO(L_SYMB),             MO(L_MDIA), KC_Y   , KC_N   , KC_E   , KC_O   , KC_I   , KC_QUOT,
  KC_LSFT, KC_Z   , KC_X   , KC_M   , KC_C   , KC_V   ,                                     KC_K   , KC_L   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
  KC_LCTL, _______, _______, KC_DOWN, KC_UP  ,          KC_ESC,                     KC_ESC         , KC_LEFT, KC_RGHT, KC_LBRC, KC_RBRC, _______,
//       ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,
                                               KC_SPC , KC_LGUI , KC_BSPC, KC_LALT, KC_RSFT, KC_ENT
),

[L_SYMB] = LAYOUT(
  KC_ESC , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6  ,                   KC_F5  , KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , KC_F11 ,
  _______, _______, _______, _______, _______, _______, _______,                   _______, KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, _______, KC_F12 ,
  _______, _______, _______, _______, _______, _______, _______,                   _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, KC_PGUP,
  _______, _______, _______, _______, _______, _______,                                     KC_MINS, KC_PLUS, KC_LCBR, KC_RCBR, _______, KC_PGDN,
  _______, _______, _______, _______, _______,              RGB_MOD,           RGB_TOG,              KC_EQL , _______, _______, _______, _______,
//       ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,
                                               RGB_VAD, RGB_VAI, KC_DEL, _______, RGB_HUD, KC_DEL
),

[L_MDIA] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, VOL_5  , _______, _______, QK_BOOT,
  _______, _______, KC_MS_U, _______, _______, _______, _______,                   KC_MPRV, KC_MPLY, KC_MNXT, VOL_4  , _______, _______, _______,
  _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, _______, _______,                   _______, _______, KC_BTN1, VOL_3  , KC_BTN2, _______, KC_MPLY,
  _______, _______, _______, _______, _______, _______,                                     _______, _______, VOL_2  , _______, _______, _______,
  _______, _______, _______, _______, _______,             _______,            _______,              _______, VOL_1  , _______, _______, _______,
//       ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,
                                       DF(L_QWRTY), DF(L_WRKMN), _______, _______, _______, _______
),
[L_NUMB] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,                   _______, KC_7   , KC_8   , KC_9   , KC_PLUS, _______, _______,
  _______, _______, _______, _______, _______, _______, _______,                   _______, KC_4   , KC_5   , KC_6   , KC_MINS, _______, _______,
  _______, _______, _______, _______, _______, _______,                                     KC_1   , KC_2   , KC_3   , KC_ASTR, _______, _______,
  _______, _______, _______, _______, _______,             _______,            _______,              KC_0   , KC_DOT , KC_SLSH, _______, _______,
//       ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,        ,
                                       DF(L_QWRTY), DF(L_WRKMN), _______, _______, _______, _______
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

                                      66, 62, 57,





};

const uint16_t PROGMEM num_keys[] = {
       5, 10, 15, 20, 25,                 61, 56, 51, 46, 41,




};

const uint16_t PROGMEM numpad_keys[] = {

                                          62, 57, 52,
                                          63, 58, 53,
                                          64, 59, 54,
                                              60,

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
                                  70,
};

const uint16_t PROGMEM layer_keys[] = {


                          31,         67,



};
// clang-format on

// Sorted lowest to highest
const uint16_t PROGMEM volume_keys[] = {55, 54, 53, 52, 51};

const void rgb_set_keys(const uint16_t keys[], uint8_t num_keys, uint8_t red, uint8_t green, uint8_t blue) {
    for (int i = 0; i < num_keys; i++) {
        rgb_matrix_set_color(keys[i], red, green, blue);
    }
}

const void rgb_set_media(uint8_t red, uint8_t green, uint8_t blue) {
    rgb_set_keys(media_keys, LENGTH(media_keys), red, green, blue);
    rgb_matrix_set_color(62, media_rgb[0], media_rgb[1], media_rgb[2]);
}

const void rgb_set_volume(uint8_t red, uint8_t green, uint8_t blue) {
    for (uint8_t i = 0; i < MAX_VOLUME; i++) {
        if (i < current_volume) {
            rgb_matrix_set_color(volume_keys[i], red, green, blue);
        } else {
            rgb_matrix_set_color(volume_keys[i], 0x00, 0x00, 0x00);
        }
    }
}

const void rgb_set_ws(uint8_t red, uint8_t green, uint8_t blue) {
    uint8_t key;
    bool    state;
    for (uint8_t ws = 0; ws < WS_NUM_WS * WS_NUM_DISPLAYS; ws++) {
        key   = workspaces[ws];
        state = workspace_state[ws];
        if (state) {
            rgb_matrix_set_color(key, red, green, blue);
        } else {
            rgb_matrix_set_color(key, ALPHA_KEYCOLOR);
        }
    }
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

void send_volume(uint8_t volume) {
    hid_buffer[0] = event_VOLUME; // Volume message
    hid_buffer[1] = volume;       // Volume value
    hid_buffer[2] = 5;            // Total number of steps
    raw_hid_send(hid_buffer, 32);
}

void keyboard_post_init_user(void) {
    // debug_enable = true;
    // debug_matrix=true;
    // debug_keyboard=true;
    // debug_mouse=true;
}

void raw_hid_receive(uint8_t *data, uint8_t length) {
#ifdef DEBUG
    uprintf("raw hid of len %d: ", length);
    for (int i = 0; i < length; i++) {
        uprintf("%u,", data[i]);
    }
    uprintf("\n");
#endif
    switch (data[0]) {
        case event_NONE:
            break;

        case event_MEDIA:
            set_media_state(data[1]);
            break;

        case event_WORKSPACE:
            uint8_t i = 1 << (WS_NUM_WS * WS_NUM_DISPLAYS - 1);
            for (uint8_t ws = 0; i >> ws > 0; ws++) {
                workspace_state[ws] = data[1] & i >> ws;
            }
            break;

        case event_VOLUME:
            if (data[1] > MAX_VOLUME) {
                current_volume = MAX_VOLUME;
            } else {
                current_volume = data[1];
            }
            break;

#ifdef DEBUG
        default:
            uprintf("Unknown event: %u\n", data[0]);
#endif
    }
}

bool rgb_matrix_indicators_user(void) {
    rgb_matrix_set_color_all(0, 0, 0);
    switch (get_highest_layer(layer_state)) {
        case L_QWRTY:
            rgb_set_keys(alpha_keys, LENGTH(alpha_keys), ALPHA_KEYCOLOR);
            rgb_set_ws(WASD_KEYCOLOR);
            rgb_set_keys(mod_keys, LENGTH(mod_keys), MOD_KEYCOLOR);
            rgb_set_keys(layer_keys, LENGTH(layer_keys), LAYER_KEYCOLOR);
          return true;
        case L_SYMB:
            rgb_set_keys(alpha_keys, LENGTH(alpha_keys), MOD_KEYCOLOR);
          return true;
        case L_NUMB:
            rgb_set_keys(numpad_keys, LENGTH(numpad_keys), ALPHA_KEYCOLOR);
            rgb_matrix_set_color(55, MOD_KEYCOLOR);
            return true;
        case L_MDIA:
            rgb_set_media(MOD_KEYCOLOR);
            rgb_set_volume(MOD_KEYCOLOR);
          return true;
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case VOL_1:
            if (record->event.pressed) {
                send_volume(1);
                return false;
            }
            break;
        case VOL_2:
            if (record->event.pressed) {
                send_volume(2);
                return false;
            }
            break;
        case VOL_3:
            if (record->event.pressed) {
                send_volume(3);
                return false;
            }
            break;
        case VOL_4:
            if (record->event.pressed) {
                send_volume(4);
                return false;
            }
            break;
        case VOL_5:
            if (record->event.pressed) {
                send_volume(5);
                return false;
            }
            break;
    }
    return true;
}
