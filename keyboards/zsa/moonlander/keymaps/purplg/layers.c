#include "keysets.c"
#include "print.h"

enum layers {
    BASE = 0,
    ALT,
    MEDIA,
};

uint8_t media_rgb[] = {MOD_KEYCOLOR};

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
