#define LENGTH(arr) sizeof(arr) / sizeof(uint16_t)

/*
  00, 05, 10, 15, 20, 25, 29,         65, 61, 56, 51, 46, 41, 36,
  01, 06, 11, 16, 21, 26, 30,         66, 62, 57, 52, 47, 42, 37,
  02, 07, 12, 17, 22, 27, 31,         67, 63, 58, 53, 48, 43, 38,
  03, 08, 13, 18, 23, 28,                 64, 59, 54, 49, 44, 39,
  04, 09, 14, 19, 24,     35,         71,     60, 55, 50, 45, 40,
                        32,33,34, 70,69,68,
*/

static const uint16_t PROGMEM left_keys[] = {
   0,  5, 10, 15, 20, 25, 29,
   1,  6, 11, 16, 21, 26, 30,
   2,  7, 12, 17, 22, 27, 31,
   3,  8, 13, 18, 23, 28,
   4,  9, 14, 19, 24,     35,
                        32,33,34,
};

static const uint16_t PROGMEM right_keys[] = {
                                      65, 61, 56, 51, 46, 41, 36,
                                      66, 62, 57, 52, 47, 42, 37,
                                      67, 63, 58, 53, 48, 43, 38,
                                          64, 59, 54, 49, 44, 39,
                                      71,     60, 55, 50, 45, 40,
                                  70,69,68,
};

static const uint16_t PROGMEM media_keys[] = {

                                          62,
                                          63, 58,




};

static const uint16_t PROGMEM num_keys[] = {
       5, 10, 15, 20, 25,                 61, 56, 51, 46, 41,
};

static const uint16_t PROGMEM alpha_keys[] = {

       6, 11, 16, 21, 26,                 62, 57, 52, 47, 42,
       7, 12, 17, 22, 27,                 63, 58, 53, 48, 43,
       8, 13, 18, 23, 28,                 64, 59, 54, 49, 44,

};

static const uint16_t PROGMEM wasd_keys[] = {

          11,
       7, 12, 17,



};

static const uint16_t PROGMEM mod_keys[] = {


   2,
   3,
   4,
                        32,       70,
};

static const uint16_t PROGMEM layer_keys[] = {




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
