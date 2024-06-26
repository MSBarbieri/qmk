#include QMK_KEYBOARD_H

#define LEADER_TIMEOUT 10

#define QUERTY_LAYER 2
#define DVORAK_LAYER 0
#define CANARY_LAYER 1

#define BASE_LAYER DVORAK_LAYER

#define SYMBOLS_LAYER 3
#define NUMBER_LAYER 4
#define NAV_LAYER 5
#define NUMROW_LAYER 6

#define FN_LAYER 7
#define SOUND_LAYER 8

#define SFT_ESC SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC ALT_T(KC_SPC)
#define SFT_ENT SFT_T(KC_ENT)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN1

#define KC_NONE

#define RAISE MO(INSERT_LAYER)
#define LOWER MO(NUMBER_LAYER)

// #include "features/custom_shift_keys.h"

// const custom_shift_key_t custom_shift_keys[] = {
//     {KC_COLN, KC_SLSH}, // Shift : is ;
//     {KC_SCLN, KC_QUES}, // Shift : is ;
// };

uint8_t NUM_CUSTOM_SHIFT_KEYS = sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

const uint16_t PROGMEM reset_combo[] = {MT(MOD_LGUI, KC_SPC), LT(SYMBOLS_LAYER, KC_BSPC), COMBO_END};

combo_t key_combos[] = {
    [RESET_LAYER] = COMBO_ACTION(reset_combo),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base (qwerty)
     * +-----------------------------------------+                             +-----------------------------------------+
     * | ESC  |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |      |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | TAB  |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |      |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | SHFT |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   /  |      |
     * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
     *               |  [   |   ]  |      |      |                             |      |     |      |      |
     *               +-------------+-------------+                             +-------------+-------------+
     *                                    |------+------|               |------+------|
     *                                    |      |      |               |      |      |
     *                                    +-------------+               +-------------+
     *                                           +-------------+ +-------------+
     *                                           |      |      | |      |      |
     *                                           |------+------| |------+------|
     *                                           |      |      | |      |      |
     *                                           +-------------+ +-------------+
     *
     *
     *
     * [ARRAY_EXAMPLE] = LAYOUT_manuform_let(
     *     _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
     *     _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
     *     _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
     *     _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______,
     *                                         _______, _______, _______,         _______, _______, _______
     * ),
     *
     * [ARRAY_EXAMPLE] = LAYOUT_manuform_let(_______, _______, _______, _______, _______, _______, /\** Split **\/ _______, _______, _______, _______, _______, _______,                   // high row
     *                                       _______, _______, _______, _______, _______, _______, /\** Split **\/ _______, _______, _______, _______, _______, _______,                   // home row
     *                                       _______, _______, _______, _______, _______, _______, /\** Split **\/ _______, _______, _______, _______, _______, _______,                   // lower row
     *                                       _______, _______, _______, _______, _______, _______, _______, /\** Split **\/ _______, _______, _______, _______, _______, _______, _______, // base row
     *                                       _______, _______, _______, /\** Split **\/ _______, _______, _______),                                                                        // thumb cluster
     */

    [CANARY_LAYER] = LAYOUT_manuform_let(KC_TAB, KC_W, KC_L, KC_Y, KC_P, KC_B, /** Split **/ KC_Z, KC_F, KC_O, KC_U, KC_QUOT, KC_SCLN,                                                                                      // high row
                                         KC_ESC, MT(MOD_LCTL, KC_C), MT(MOD_LSFT, KC_R), MT(MOD_LALT, KC_S), KC_T, KC_G, /** Split **/ KC_D, KC_H, MT(MOD_LALT, KC_T), MT(MOD_LSFT, KC_N), MT(MOD_LCTL, KC_S), KC_MINUS,    // home row
                                         KC_LSFT, KC_Q, KC_J, KC_V, KC_D, KC_K, /** Split **/ KC_X, KC_H, KC_SLSH, KC_COMM, KC_DOT, KC_RSFT,                                                                                // lower row
                                         KC_NO, KC_NO, KC_NO, KC_NO, MT(MOD_LGUI, KC_SPC), QK_LEAD, KC_NO, /** Split **/ KC_NO, LT(NUMROW_LAYER, KC_ENT), LT(SYMBOLS_LAYER, KC_BSPC), KC_NO, KC_NO, KC_NO, KC_NO,           // base row
                                         DF(CANARY_LAYER), DF(DVORAK_LAYER), DF(QUERTY_LAYER), /** Split **/ KC_GRAVE, KC_CAPS, KC_APP),                                                                                    // thumb cluster
    [DVORAK_LAYER] = LAYOUT_manuform_let(KC_TAB, KC_COLN, KC_COMM, KC_DOT, KC_P, KC_Y, /** Split **/ KC_F, KC_G, KC_C, KC_R, KC_L, KC_SCLN,                                                                                 // high row
                                         KC_ESC, MT(MOD_LCTL, KC_A), MT(MOD_LSFT, KC_O), MT(MOD_LALT, KC_E), KC_U, KC_I, /** Split **/ KC_D, KC_H, MT(MOD_LALT, KC_T), MT(MOD_LSFT, KC_N), MT(MOD_LCTL, KC_S), KC_MINUS,    // home row
                                         KC_LSFT, KC_QUOT, KC_Q, KC_J, KC_K, KC_X, /** Split **/ KC_B, KC_M, KC_W, KC_V, KC_Z, KC_RSFT,                                                                                     // lower row
                                         KC_NO, KC_NO, KC_NO, KC_NO, MT(MOD_LGUI, KC_SPC), QK_LEAD, KC_NO, /** Split **/ KC_NO, LT(NUMROW_LAYER, KC_ENT), LT(SYMBOLS_LAYER, KC_BSPC), KC_NO, KC_NO, KC_NO, KC_NO,           // thumb cluster
                                         DF(CANARY_LAYER), DF(DVORAK_LAYER), DF(QUERTY_LAYER), /** Split **/ KC_GRAVE, KC_CAPS, KC_APP),                                                                                    // thumb cluster
    [QUERTY_LAYER] = LAYOUT_manuform_let(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, /** Split **/ KC_Y, KC_U, KC_I, KC_O, KC_P, KC_SCLN,                                                                                         // high row
                                         KC_CAPS, MT(MOD_LCTL, KC_A), MT(MOD_LSFT, KC_S), MT(MOD_LALT, KC_D), KC_F, KC_G, /** Split **/ KC_H, KC_J, MT(MOD_LALT, KC_K), MT(MOD_LSFT, KC_L), MT(MOD_LCTL, KC_SCLN), KC_QUOT, // home row
                                         KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, /** Split **/ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,                                                                                // lower row
                                         KC_NO, KC_NO, KC_NO, KC_NO, MT(MOD_LGUI, KC_SPC), QK_LEAD, KC_NO, /** Split **/ KC_NO, LT(NUMROW_LAYER, KC_ENT), LT(SYMBOLS_LAYER, KC_BSPC), KC_NO, KC_NO, KC_NO, KC_NO,           // base row
                                         DF(CANARY_LAYER), DF(DVORAK_LAYER), DF(QUERTY_LAYER), /** Split **/ KC_GRAVE, KC_CAPS, KC_ESC),                                                                                    // thumb cluster

    [SYMBOLS_LAYER] = LAYOUT_manuform_let(_______, _______, KC_SLASH, LSFT(KC_LBRC), LSFT(KC_1), _______, /** Split **/ _______, LSFT(KC_8), LSFT(KC_RBRC), KC_BSLS, _______, _______,                                    // high row
                                          _______, KC_GRAVE, KC_EQUAL, LSFT(KC_9), LSFT(KC_7), _______, /** Split **/ _______, LSFT(KC_BSLS), LSFT(KC_0), LSFT(KC_EQUAL), LSFT(KC_GRAVE), _______,                        // home row
                                          _______, _______, LSFT(KC_4), KC_LBRC, LSFT(KC_3), _______, /** Split **/ _______, LSFT(KC_2), KC_RBRC, LSFT(KC_5), _______, _______,                                           // lower row
                                          _______, _______, _______, _______, _______, _______, _______, /** Split **/ _______, _______, _______, _______, _______, _______, _______,                                     // base row
                                          _______, _______, _______, /** Split **/ _______, _______, _______),                                                                                                            // thumb cluster
    [NAV_LAYER]     = LAYOUT_manuform_let(_______, _______, _______, _______, _______, _______, /** Split **/ _______, KC_HOME, KC_UP, KC_END, _______, _______,                                                          // high row
                                          _______, _______, _______, _______, _______, _______, /** Split **/ _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,                                                      // home row
                                          _______, _______, _______, _______, _______, _______, /** Split **/ _______, _______, _______, _______, _______, _______,                                                       // lower row
                                          _______, _______, _______, _______, _______, _______, _______, /** Split **/ _______, _______, _______, _______, _______, _______, _______,                                     // lower row
                                          _______, _______, _______, _______, _______, _______),                                                                                                                          // thumb cluster
    [NUMBER_LAYER]  = LAYOUT_manuform_let(_______, _______, _______, _______, _______, _______, /** Split **/ LSFT(KC_8), KC_7, KC_8, KC_9, LSFT(KC_EQUAL), _______,                                                      // high row
                                          _______, _______, _______, _______, _______, _______, /** Split **/ KC_EQUAL, KC_4, KC_5, KC_6, KC_0, _______,                                                                  // home row
                                          _______, _______, _______, _______, _______, _______, /** Split **/ KC_SLSH, KC_1, KC_2, KC_3, KC_MINUS, _______,                                                               // lower row
                                          _______, _______, _______, _______, _______, _______, _______, /** Split **/ _______, _______, _______, KC_0, _______, _______, _______,                                        // base row
                                          _______, _______, _______, _______, _______, _______),                                                                                                                          // thumb cluster
    [NUMROW_LAYER]  = LAYOUT_manuform_let(_______, _______, _______, _______, _______, _______, /** Split **/ _______, _______, _______, _______, _______, _______,                                                       // high row
                                          _______, MT(MOD_LCTL, KC_1), MT(MOD_LSFT, KC_2), MT(MOD_LALT, KC_3), KC_4, KC_5, /** Split **/ KC_6, KC_7, MT(MOD_LALT, KC_8), MT(MOD_LSFT, KC_9), MT(MOD_LCTL, KC_0), _______, // home row
                                          _______, _______, _______, _______, _______, _______, /** Split **/ _______, _______, _______, _______, _______, _______,                                                       // lower row
                                          _______, _______, _______, _______, _______, _______, _______, /** Split **/ _______, _______, _______, _______, _______, _______, _______,                                     // thumb cluster
                                          _______, _______, _______, /** Split **/ _______, _______, _______),

    [SOUND_LAYER] = LAYOUT_manuform_let(_______, _______, _______, _______, _______, _______, /** Split **/ _______, _______, _______, _______, _______, _______,                                                             // row high
                                        _______, _______, KC_AUDIO_MUTE, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, _______, /** Split **/ _______, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, _______, _______, // row home
                                        _______, _______, _______, _______, _______, _______, /** Split **/ _______, _______, _______, _______, _______, _______,                                                             // row lower
                                        _______, _______, _______, _______, _______, _______, _______, /** Split **/ _______, _______, _______, _______, _______, _______, _______,                                           // thumb cluster
                                        _______, _______, _______, /** Split **/ _______, _______, _______),
    [FN_LAYER]    = LAYOUT_manuform_let(_______, _______, _______, KC_F11, _______, _______, /** Split **/ _______, _______, KC_F12, _______, _______, _______,                     // row high
                                        _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, /** Split **/ KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______,                                      // row home
                                        _______, _______, _______, _______, _______, _______, /** Split **/ _______, _______, _______, _______, _______, _______,                   // row lower
                                        _______, _______, _______, _______, _______, _______, _______, /** Split **/ _______, _______, _______, _______, _______, _______, _______, // thumb cluster
                                        _______, _______, _______, /** Split **/ _______, _______, _______),
};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

void leader_start_user(void) {
    rgb_matrix_sethsv(HSV_WHITE);
}

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_E)) {
        layer_invert(NUMBER_LAYER);
    } else if (leader_sequence_one_key(KC_S)) {
        layer_invert(SOUND_LAYER);
    } else if (leader_sequence_one_key(KC_T) || leader_sequence_one_key(KC_DOWN)) {
        layer_invert(NAV_LAYER);
    } else if (leader_sequence_two_keys(KC_M, KC_R)) {
        SEND_STRING("hello world from hotkey!");
    } else {
        layer_clear();
    }
    // QK_CAPS_WORD_TOGGLE
    //  } else if (leader_sequence_two_keys(KC_D, KC_D)) {
    //      SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    //  } else if (leader_sequence_three_keys(KC_D, KC_D, KC_S)) {
    //  } else if (leader_sequence_two_keys(KC_A, KC_S)) {
    //      tap_code16(LGUI(KC_S));
    //  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case SYMBOLS_LAYER:
            rgb_matrix_sethsv(HSV_GREEN);
            break;
        case NUMBER_LAYER:
        case NUMROW_LAYER:
            rgb_matrix_sethsv(HSV_CYAN);
            break;
        case NAV_LAYER:
            rgb_matrix_sethsv(HSV_RED);
            break;
        case CANARY_LAYER:
            rgb_matrix_sethsv(HSV_BLUE);
            break;
        case DVORAK_LAYER:
            rgb_matrix_sethsv(HSV_PURPLE);
            break;
        default: //  for any other layers, or the default layer
            rgb_matrix_sethsv(HSV_WHITE);
            break;
    }
    return state;
}

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case RESET_LAYER:
            layer_clear();
            set_single_persistent_default_layer(BASE_LAYER);
            break;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_custom_shift_keys(keycode, record)) {
        return false;
    }
    // Your macros ...

    return true;
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
}
