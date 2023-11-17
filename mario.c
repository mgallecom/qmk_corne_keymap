/**
 * Big daemon animation with slow and fast typing mode
 * Thanks to Pixel Frog for the art: https://pixelfrog-assets.itch.io
 *
 * ROTATION:
 * OLED_ROTATION_0
 *
 * Copyright (c) Marek Piechut
 * MIT License
 */

#pragma once

#define ANIM_SCROLL true
#define ANIM_FRAME_WIDTH 32
#define ANIM_SIZE 288
#define ANIM_BOUNCE true

#include "animation-utils.c"

static void oled_render_anim(void) {
// 'Idle 01', 72x32px
static const char mario_turn_right [] PROGMEM = {
// 'mario_turn_right', 32x32px
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0x70, 0x38, 0xb8, 0x98, 0x90, 0x90,
0x10, 0x50, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0xb0, 0xe0, 0xdc, 0xbf, 0x39, 0xd0, 0xd2, 0xdf, 0x8f, 0x19, 0x9f, 0xb9,
0xbf, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x31, 0x7b, 0xfb, 0xf1, 0x60, 0x01, 0x03, 0x03, 0x05, 0xc4, 0x67, 0x1f,
0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x1e, 0x1c, 0x1c, 0x0c, 0x06, 0x01, 0x01, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'Idle 02', 72x32px
static const char mario_idle_right1 [] PROGMEM = {
// 'mario_idle_right1', 32x32px
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0x70, 0x30, 0xb8, 0x98, 0x98, 0x98, 0xb0, 0x20,
0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x8e, 0x9e, 0x98, 0x30, 0x7b, 0x6f, 0x67, 0x4c, 0x4f, 0x1c, 0x1c,
0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x0e, 0x1f, 0x13, 0x0d, 0x1e, 0x1e, 0x1e, 0x2d, 0x33, 0x0e, 0x0c, 0x30,
0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0c, 0x08, 0x08, 0x08, 0x04, 0x02, 0x04, 0x00, 0x0c, 0x0e,
0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'Idle 03', 72x32px
static const char mario_idle_right2 [] PROGMEM = {
// 'mario_idle_right2', 32x32px
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0x70, 0x30, 0xb8, 0x98, 0x98, 0x98, 0x30, 0x20,
0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x0e, 0x1e, 0x18, 0xb0, 0xbb, 0x6f, 0x67, 0x4c, 0x5f, 0x1c, 0x1c,
0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x07, 0x0f, 0x2f, 0x26, 0x19, 0x3c, 0x3c,
0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x07, 0x0c, 0x08, 0x08, 0x08, 0x04, 0x02, 0x04, 0x00, 0x0c, 0x0e, 0x07,
0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'Idle 04', 72x32px
static const char mario_turn_left [] PROGMEM = {
    // 'mario_turn_left', 32x32px
    0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0xb0, 0x90, 0x98, 0xb8, 0x38, 0x70, 0xe0, 0xc0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x98, 0xbf, 0xb9, 0x9f, 0x19, 0x8f, 0xdf, 0xd2, 0xd0, 0x39, 0xbf, 0xdc,
    0xe0, 0xb0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x01, 0x1b, 0x67, 0x87, 0x04, 0x05, 0x03, 0x03, 0x01, 0x60, 0xf1, 0xfb,
    0x7b, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x06, 0x0c, 0x1c, 0x1c, 0x1e, 0x0c,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'Idle 05', 72x32px
static const char mario_idle_left1 [] PROGMEM = {
    // 'mario_idle_left1', 32x32px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0xb0, 0x98, 0x98, 0x98, 0xb8, 0x30, 0x70, 0xe0, 0xc0,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x1c, 0x1c, 0x4f, 0x4c, 0x67, 0x6f, 0x7b, 0x30, 0x98, 0x9e,
    0x8e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x30, 0x0c, 0x0e, 0x33, 0x2d, 0x1e, 0x1e, 0x1e, 0x0d, 0x13,
    0x1f, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0e, 0x0c, 0x00, 0x04, 0x02, 0x04, 0x08, 0x08, 0x08, 0x0c,
    0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
// 'Idle 06', 72x32px
static const char mario_idle_left2 [] PROGMEM = {
    // 'mario_idle_left2', 32x32px
    0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0x30, 0x98, 0x98, 0x98, 0xb8, 0x30, 0x70, 0xe0, 0xc0,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x1c, 0x1c, 0x5f, 0x4c, 0x67, 0x6f, 0xbb, 0xb0, 0x18, 0x1e,
    0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x3c, 0x3c, 0x19, 0x26, 0x2f, 0x0f, 0x07, 0x07, 0x03, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x07, 0x0e, 0x0c, 0x00, 0x04, 0x02, 0x04, 0x08, 0x08, 0x08,
    0x0c, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

// 'Run 01', 72x32px
//    static const char crab_run_01 [] PROGMEM = {
//        // 'mario_turn_right', 32x32px
//        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xe0, 0x70, 0x38, 0xb8, 0x98, 0x90, 0x90,
//        0x10, 0x50, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//        0x00, 0x00, 0x00, 0x00, 0xb0, 0xe0, 0xdc, 0xbf, 0x39, 0xd0, 0xd2, 0xdf, 0x8f, 0x19, 0x9f, 0xb9,
//        0xbf, 0x98, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//        0x00, 0x00, 0x00, 0x00, 0x31, 0x7b, 0xfb, 0xf1, 0x60, 0x01, 0x03, 0x03, 0x05, 0xc4, 0x67, 0x1f,
//        0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x1e, 0x1c, 0x1c, 0x0c, 0x06, 0x01, 0x01, 0x00, 0x00,
//        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
//    };
// 'Run 02', 72x32px
    static const char mario_run_right1 [] PROGMEM = {
        // 'mario_run_right1', 32x32px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x60, 0x70, 0xb0, 0xb8, 0x98, 0x98, 0x98, 0xb0,
        0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x1e, 0x98, 0xb0, 0x3b, 0x6f, 0x67, 0x4c, 0x4f, 0x5c, 0x1f,
        0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x06, 0x06, 0x06, 0x0e, 0xcd, 0x43, 0x0f, 0x07, 0x86, 0x80, 0xb1, 0x37, 0x06, 0x04,
        0xd1, 0xe3, 0xe3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x00, 0x02, 0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00,
        0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
// 'Run 03', 72x32px
    static const char mario_run_right2 [] PROGMEM = {
        // 'mario_run_right2', 32x32px
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x60, 0x70, 0xb0, 0xb8, 0x98, 0x98, 0x98, 0xb0,
        0x20, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x1e, 0x98, 0xb0, 0x3b, 0x6f, 0x67, 0x4c, 0x4f, 0x5c, 0x1f,
        0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x06, 0x06, 0x06, 0x0e, 0x0d, 0x03, 0x0f, 0x07, 0x06, 0x00, 0x31, 0x37, 0x06, 0x04,
        0x31, 0x33, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0c, 0x08, 0x08, 0x08, 0x04, 0x02, 0x04, 0x00, 0x0c,
        0x0e, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
// 'Run 04', 72x32px
//    static const char crab_run_04 [] PROGMEM = {
//        // 'mario_turn_left', 32x32px
//        0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0xb0, 0x90, 0x98, 0xb8, 0x38, 0x70, 0xe0, 0xc0, 0x00, 0x00,
//        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//        0x00, 0x00, 0x00, 0x00, 0x98, 0xbf, 0xb9, 0x9f, 0x19, 0x8f, 0xdf, 0xd2, 0xd0, 0x39, 0xbf, 0xdc,
//        0xe0, 0xb0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//        0x00, 0x00, 0x00, 0x00, 0x01, 0x1b, 0x67, 0x87, 0x04, 0x05, 0x03, 0x03, 0x01, 0x60, 0xf1, 0xfb,
//        0x7b, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
//        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x06, 0x0c, 0x1c, 0x1c, 0x1e, 0x0c,
//        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
//    };
// 'Run 05', 72x32px
    static const char mario_run_left1 [] PROGMEM = {
        // 'mario_run_left1', 32x32px
        0x00, 0x00, 0x00, 0x00, 0x40, 0x40, 0x60, 0x30, 0x30, 0x30, 0x70, 0x60, 0xe0, 0xc0, 0x80, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x3f, 0xb9, 0x9f, 0x99, 0xcf, 0xdf, 0x76, 0x60, 0x31, 0x3c,
        0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0xc6, 0xc6, 0xa2, 0x08, 0x0c, 0x6e, 0x62, 0x00, 0x0c, 0x0e, 0x1f, 0x87, 0x9a,
        0x1c, 0x0c, 0x0c, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x03, 0x07, 0x07, 0x00, 0x02, 0x01, 0x01, 0x01, 0x02, 0x04, 0x04, 0x00, 0x0f,
        0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };
// 'Run 06', 72x32px
    static const char mario_run_left2 [] PROGMEM = {
        // 'mario_run_left2', 32x32px
        0x00, 0x00, 0x00, 0x00, 0x20, 0x20, 0xb0, 0x98, 0x98, 0x98, 0xb8, 0xb0, 0x70, 0x60, 0xc0, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x1f, 0x5c, 0x4f, 0x4c, 0x67, 0x6f, 0x3b, 0xb0, 0x98, 0x1e,
        0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x03, 0x33, 0x31, 0x04, 0x06, 0x37, 0x31, 0x00, 0x06, 0x07, 0x0f, 0x03, 0x0d,
        0x0e, 0x06, 0x06, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x03, 0x07, 0x0e, 0x0c, 0x00, 0x04, 0x02, 0x04, 0x08, 0x08, 0x08, 0x0c, 0x07,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
    };


    static const char* SLOW_TYPE_FRAMES [] = {
        mario_turn_right,
        mario_idle_right1,
        mario_idle_right2,
        mario_idle_right1,
        mario_idle_right2,
        mario_turn_left,
        mario_idle_left1,
        mario_idle_left2,
        mario_idle_left1,
        mario_idle_left2,
    };
    static const char* FAST_TYPE_FRAMES [] = {
        mario_turn_right,
        mario_run_right1,
        mario_run_right2,
        mario_run_right1,
        mario_run_right2,
        mario_turn_left,
        mario_run_left1,
        mario_run_left2,
        mario_run_left1,
        mario_run_left2,
    };

    oled_render_anim_frame(FAST_TYPE_FRAMES, SLOW_TYPE_FRAMES, 10);
}
