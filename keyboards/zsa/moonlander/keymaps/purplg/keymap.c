#include QMK_KEYBOARD_H
#include "version.h"
#include "raw_hid.h"

#include "aliases.h"
#include "colors.h"
#include "layers.c"
#include "rawhid.c"

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

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}
