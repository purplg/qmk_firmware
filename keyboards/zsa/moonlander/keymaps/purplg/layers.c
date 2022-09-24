#include "keysets.c"

enum layers {
  BASE = 0, 
  ALT, 
  MEDIA, 
};

void base_layer(void) {
  rgb_matrix_set_color_all(0,0,0);
  rgb_set_num(NUM_KEYCOLOR);
  rgb_set_alpha(ALPHA_KEYCOLOR);
  rgb_set_wasd(WASD_KEYCOLOR);
  rgb_set_mod(MOD_KEYCOLOR);
  rgb_set_layer(LAYER_KEYCOLOR);
}

void alt_layer(void) {
  rgb_matrix_set_color_all(0,0,0);
  rgb_set_alpha(MOD_KEYCOLOR);
}

void media_layer(void) {
  rgb_matrix_set_color_all(0,0,0);
  rgb_set_media(MOD_KEYCOLOR);
}

void rgb_matrix_indicators_user(void) {
  switch (get_highest_layer(layer_state)) {
  case BASE:  base_layer();  break;
  case ALT:   alt_layer();   break;
  case MEDIA: media_layer(); break;
  }
}
