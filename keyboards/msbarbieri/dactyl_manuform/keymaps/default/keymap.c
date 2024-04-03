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

#define SFT_ESC  SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC  ALT_T(KC_SPC)
#define SFT_ENT  SFT_T(KC_ENT)

#define KC_ML KC_MS_LEFT
#define KC_MR KC_MS_RIGHT
#define KC_MU KC_MS_UP
#define KC_MD KC_MS_DOWN
#define KC_MB1 KC_MS_BTN1
#define KC_MB2 KC_MS_BTN1

#define KC_NONE


#define RAISE MO(INSERT_LAYER)
#define LOWER MO(NUMBER_LAYER)


const uint16_t PROGMEM reset_combo[] = { MT(MOD_LGUI, KC_SPC), KC_BSPC, COMBO_END};

enum combo_events {
  RESET_LAYER,
};

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
     */


    [CANARY_LAYER] = LAYOUT_manuform_let(
        KC_TAB,  KC_W,    KC_L,    KC_Y,    KC_P,    KC_B,                                KC_Z,    KC_F,     KC_O,    KC_U, KC_QUOT, KC_SLSH,//KC_BSLS,
        KC_ESC,  MT(MOD_LCTL, KC_C),  MT(MOD_LSFT,  KC_R),  MT(MOD_LALT,  KC_S),    KC_T,    KC_G,                                KC_D,    KC_H,     MT(MOD_LALT, KC_T),   MT(MOD_LSFT, KC_N), MT(MOD_LCTL, KC_S), KC_MINUS,
        KC_LSFT, KC_Q,    KC_J,    KC_V,    KC_D,    KC_K,                                KC_X,    KC_H,  KC_SLSH, KC_COMM,  KC_DOT, KC_RSFT,
        KC_NO,   KC_NO, KC_NO,   KC_NO, MT(MOD_LGUI, KC_SPC), LT(SYMBOLS_LAYER, KC_SCLN),  KC_NO,           KC_NO,  LT(NUMROW_LAYER,KC_ENT),  KC_BSPC, KC_NO,  KC_NO, KC_NO, KC_NO,
                        DF(CANARY_LAYER), DF(DVORAK_LAYER),    DF(QUERTY_LAYER),           KC_GRAVE,  KC_CAPS,  KC_APP
    ),

    [DVORAK_LAYER] = LAYOUT_manuform_let(
        KC_TAB,  LSFT(KC_SCLN),    KC_COMM,    KC_DOT,    KC_P,    KC_Y,                                KC_F,    KC_G,     KC_C,    KC_R, KC_L, KC_SLSH,//KC_BSLS,
        KC_ESC,  MT(MOD_LCTL, KC_A),  MT(MOD_LSFT,  KC_O),  MT(MOD_LALT,  KC_E),    KC_U,    KC_I,                                KC_D,    KC_H,     MT(MOD_LALT, KC_T),   MT(MOD_LSFT, KC_N), MT(MOD_LCTL, KC_S), KC_MINUS,
        KC_LSFT, KC_QUOT,    KC_Q,    KC_J,    KC_K,    KC_X,                                KC_B,    KC_M,  KC_W, KC_V,  KC_Z, KC_RSFT,
        KC_NO,   KC_NO, KC_NO,   KC_NO,MT(MOD_LGUI, KC_SPC), LT(SYMBOLS_LAYER, KC_SCLN),  KC_NO,           KC_NO,  LT(NUMROW_LAYER,KC_ENT),  KC_BSPC, KC_NO,  KC_NO, KC_NO, KC_NO,
                        DF(CANARY_LAYER), DF(DVORAK_LAYER),    DF(QUERTY_LAYER),           KC_GRAVE,  KC_CAPS,  KC_APP
    ),

    [QUERTY_LAYER] = LAYOUT_manuform_let(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                KC_Y,    KC_U,     KC_I,    KC_O, KC_P, KC_LBRC,//KC_BSLS,
        KC_ESC,  MT(MOD_LCTL, KC_A),  MT(MOD_LSFT,  KC_S),  MT(MOD_LALT,  KC_D),    KC_F,    KC_G,                                KC_H,    KC_J,     MT(MOD_LALT, KC_K),   MT(MOD_LSFT, KC_L), MT(MOD_LCTL, KC_SCLN), KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,    KC_M,  KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_NO,   KC_NO, KC_NO,   KC_NO,MT(MOD_LGUI, KC_SPC), LT(SYMBOLS_LAYER, KC_SCLN),  KC_NO,           KC_NO,  LT(NUMROW_LAYER,KC_ENT),  KC_BSPC, KC_NO,  KC_NO, KC_NO, KC_NO,
                        DF(CANARY_LAYER), DF(DVORAK_LAYER),    DF(QUERTY_LAYER),           KC_GRAVE,  KC_CAPS,  KC_APP
    ),


    [SYMBOLS_LAYER] = LAYOUT_manuform_let(
        _______, _______,KC_SLASH, LSFT(KC_LBRC), LSFT(KC_1), _______,                            _______, LSFT(KC_8), LSFT(KC_RBRC),KC_BSLS, _______, _______,
        _______, KC_GRAVE, KC_EQUAL, LSFT(KC_9), LSFT(KC_7), _______,                           _______, LSFT(KC_BSLS), LSFT(KC_0), LSFT(KC_EQUAL), LSFT(KC_GRAVE), _______,

        _______, _______, LSFT(KC_4), KC_LBRC, LSFT(KC_3), _______,                           _______, LSFT(KC_2), KC_RBRC, LSFT(KC_5), _______, _______,
        _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,         _______, _______, _______
    ),

    [NUMBER_LAYER] = LAYOUT_manuform_let(
        _______, _______, _______, _______, _______, _______,                           LSFT(KC_8), KC_7, KC_8, KC_9,  LSFT(KC_EQUAL), _______,
        _______, _______, _______, _______, _______, _______,                           KC_EQUAL, KC_4, KC_5, KC_6, KC_0, _______,
        _______, _______, _______, _______, _______, _______,                           KC_SLSH, KC_1, KC_2, KC_3, KC_MINUS, _______,
        _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, KC_0, _______, _______, _______,
                                            _______, _______, _______,         _______, _______, _______
    ),

    [NAV_LAYER] = LAYOUT_manuform_let(
        _______, _______, _______, _______, _______, _______,                           _______, KC_HOME, KC_UP,   KC_END,  _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,         _______, _______, _______
    ),

    [NUMROW_LAYER] = LAYOUT_manuform_let(
        _______, KC_1, KC_2, KC_3, KC_4, KC_5,                                                         KC_6, KC_7, KC_8, KC_9, KC_0, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______, _______, _______,
                                            _______, _______, _______,         _______, _______, _______
    ),

};

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

void leader_end_user(void) {

    if (leader_sequence_one_key(KC_D) ||leader_sequence_one_key(LSFT(KC_9))) {
        layer_invert(SYMBOLS_LAYER);
    } else if (leader_sequence_one_key(KC_S)) {
        layer_invert(NUMBER_LAYER);
    } else if (leader_sequence_one_key(KC_K) ||leader_sequence_one_key(KC_DOWN)) {
        layer_invert(NAV_LAYER);
    } else if (leader_sequence_one_key(KC_ENT)) {
        layer_clear();
    }

    // } else if (leader_sequence_two_keys(KC_D, KC_D)) {
    //     SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
    // } else if (leader_sequence_three_keys(KC_D, KC_D, KC_S)) {
    // } else if (leader_sequence_two_keys(KC_A, KC_S)) {
    //     tap_code16(LGUI(KC_S));
    // }
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
  switch(combo_index) {
    case RESET_LAYER:
        layer_clear();
        set_single_persistent_default_layer(BASE_LAYER);
      break;
  }
}

void keyboard_post_init_user(void) {
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
}
