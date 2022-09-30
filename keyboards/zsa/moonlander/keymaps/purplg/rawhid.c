enum event {
    event_NONE  = 0,
    event_MEDIA = 1,
    event_SWAY  = 2,
};

enum media_state {
    media_PAUSED  = 0,
    media_PLAYING = 1,
};

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

        case event_SWAY:
            break;

        default:
            uprintf("Unknown event: %u\n", data[0]);
    }
}
