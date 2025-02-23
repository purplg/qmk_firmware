/*
  Set any config.h overrides for your specific keymap here.
  See config.h options at https://docs.qmk.fm/#/config_options?id=the-configh-file
*/
#pragma once

#define ORYX_CONFIGURATOR
#define USB_SUSPEND_WAKEUP_DELAY 0
#define RAW_USAGE_PAGE 0xFF60
#define RAW_USAGE_ID 0x61
#define RAW_ENABLE yes
#define LAYER_STATE_8BIT
#define RGB_MATRIX_STARTUP_SPD 60
#define RGBLED_NUM 13
#define RGBLIGHT_LAYERS
