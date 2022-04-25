#include QMK_KEYBOARD_H

enum custom_keycodes {
    SCR_1 = SAFE_RANGE, // Select Screen 1
    SCR_2,              // Select Screen 2
    SCR_3,              // Select Screen 3

};

const uint16_t PROGMEM term_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM tab_combo[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM esc_combo[] = {KC_S, KC_D, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(term_combo, LCTL(KC_GRV)),
    COMBO(esc_combo, KC_ESC),
    COMBO(tab_combo, KC_TAB),
};

enum layers {
    _BASE = 0, // Base QWERTY layout + thumbs
    _NUM,      // Numbers and arrows
    _SYM,      // Symbols
    _ADJ,      // Misc
    _DESK,     // Desktop navigation
};

#define LAYOUT_VA_ARGS(...) LAYOUT(__VA_ARGS__)

// =========================================================================================================================================
// BASE
// ======================= +-------+--------+--------+--------+--------+--------+     +-------+--------+--------+--------+--------+--------+
#define ___BASE_1___         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,   KC_EQL
#define ___BASE_2___         KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT
#define ___BASE_3___        CTL_GRV,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,   CTL_M, GUI_COM,  KC_DOT, KC_SLSH, KC_MINS
#define ___BASE_L_THUMBS___                           MO(_ADJ), SYM_BSP, GUI_ENT      
#define ___BASE_R_THUMBS___                                                            KC_LSFT, NUM_SPC, _______
// ======================= +-------+--------+--------+--------+--------+--------+     +-------+--------+--------+--------+--------+--------+

#define CTL_M    MT(MOD_LCTL, KC_M)
#define GUI_COM  MT(MOD_LGUI, KC_COMM)
#define NUM_SPC  LT(_NUM, KC_SPC)
#define SFT_DASH MT(MOD_LSFT, KC_MINS)
#define CTL_GRV  MT(MOD_LCTL, KC_GRV)
#define SYM_BSP  LT(_SYM, KC_BSPC)
#define GUI_ENT  MT(MOD_LGUI, KC_ENT)
// =========================================================================================================================================

// =========================================================================================================================================
// NUM
// ======================= +-------+--------+--------+--------+--------+--------+     +-------+--------+--------+--------+--------+--------+
#define ___NUM_1___         _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______
#define ___NUM_2___         _______, _______, _______, _______, _______, _______,      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, _______, KC_BSLS
#define ___NUM_3___         _______, _______, _______, _______, _______, _______,      _______, KC_PGDN, KC_PGUP, _______, _______, _______
#define ___NUM_L_THUMBS___                             _______,MO(_DESK),_______
#define ___NUM_R_THUMBS___                                                             _______, _______, _______
// ======================= +-------+--------+--------+--------+--------+--------+     +-------+--------+--------+--------+--------+--------+


// =========================================================================================================================================
// SYM
// ======================= +-------+--------+--------+--------+--------+--------+     +-------+--------+--------+--------+--------+--------+
#define ___SYM_1___         KC_TAB,  KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______
#define ___SYM_2___         _______,KC_QUOTE, KC_DQUO, KC_MINS, KC_UNDS, KC_PIPE,      _______, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, KC_PIPE
#define ___SYM_3___         _______, _______, _______, _______, _______, _______,      _______, KC_MINS, KC_UNDS, _______, _______, _______
#define ___SYM_L_THUMBS___                             _______, _______, _______
#define ___SYM_R_THUMBS___                                                             _______,MO(_DESK),_______
// ======================= +-------+--------+--------+--------+--------+--------+     +-------+--------+--------+--------+--------+--------+


// =========================================================================================================================================
// ADJUST
// ======================= +-------+--------+--------+--------+--------+--------+     +-------+--------+--------+--------+--------+--------+
#define ___ADJ_1___            LOCK,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, KC_F11
#define ___ADJ_2___         _______, _______, _______, _______, SCR_CAP, _______,      KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, _______, KC_F12
#define ___ADJ_3___           RESET, _______, _______,    COPY,   PASTE, _______,      _______, KC_MPLY, _______, _______, _______, _______
#define ___ADJ_L_THUMBS___                             _______, _______, _______
#define ___ADJ_R_THUMBS___                                                             _______, _______, _______
// ======================= +-------+--------+--------+--------+--------+--------+     +-------+--------+--------+--------+--------+--------+

#define SCR_CAP LSFT(LGUI(KC_5))
#define LOCK    LCTL(LGUI(KC_Q))
#define COPY    LGUI(KC_C)
#define PASTE   LGUI(KC_V)
// =========================================================================================================================================


// =========================================================================================================================================
// DESK
// ======================= +-------+--------+--------+--------+--------+--------+     +-------+--------+--------+--------+--------+--------+
#define ___DESK_1___        _______, _______,    MV_1,    MV_2,    MV_3, _______,     CYC_LYT,   SCR_1,   SCR_2,   SCR_3, _______, _______
#define ___DESK_2___        _______, ONE_SFT, ONE_ALT, ONE_GUI, ONE_CTL, _______,     DESK_LT, WIN_FOR, WIN_BAK, DESK_RT, _______, _______
#define ___DESK_3___        _______, _______, _______, _______, _______, _______,     _______,   TAB_R,   TAB_L, _______, _______, _______
#define ___DESK_L_THUMBS___                            _______, _______, _______
#define ___DESK_R_THUMBS___                                                            _______, _______, _______
// ======================= +-------+--------+--------+--------+--------+--------+     +-------+--------+--------+--------+--------+--------+

#define ONE_SFT OSM(MOD_LSFT)
#define ONE_ALT OSM(MOD_LALT)
#define ONE_GUI OSM(MOD_LGUI)
#define ONE_CTL OSM(MOD_LCTL)

#define DESK_LT LCTL(KC_LEFT)        // Move desktop to the left
#define DESK_RT LCTL(KC_RIGHT)       // Move desktop to the right
#define WIN_FOR LSFT(LALT(KC_J))     // Cycle window forward
#define WIN_BAK LSFT(LALT(KC_K))     // Cycle window backward
#define CYC_LYT LSFT(LALT(KC_SPC))   // Cycle layout
#define TAB_L   LGUI(LALT(KC_RIGHT)) // Tab to Left
#define TAB_R   LGUI(LALT(KC_LEFT))  // Tab to Right

#define MV_1   LCTL(LSFT(LALT(KC_W))) // Move Window to Screen 1
#define MV_2   LCTL(LSFT(LALT(KC_E))) // Move Window to Screen 2
#define MV_3   LCTL(LSFT(LALT(KC_R))) // Move Window to Screen 3

// =========================================================================================================================================

// =========================================================================================================================================
// 3 Thumb Layout
// =========================================================================================================================================
#define ___BASE_3THUMBS___  ___BASE_L_THUMBS___, ___BASE_R_THUMBS___,
#define ___NUM_3THUMBS___   ___NUM_L_THUMBS___,  ___NUM_R_THUMBS___,
#define ___SYM_3THUMBS___   ___SYM_L_THUMBS___,  ___SYM_R_THUMBS___,
#define ___ADJ_3THUMBS___   ___ADJ_L_THUMBS___,  ___ADJ_R_THUMBS___,
#define ___DESK_3THUMBS___  ___DESK_L_THUMBS___, ___DESK_R_THUMBS___,

// =========================================================================================================================================
// 4 Thumb Layout
// =========================================================================================================================================
#define ___BASE_4THUMBS___  _______, ___BASE_L_THUMBS___, ___BASE_R_THUMBS___, _______
#define ___NUM_4THUMBS___   _______, ___NUM_L_THUMBS___,  ___NUM_R_THUMBS___,  _______
#define ___SYM_4THUMBS___   _______, ___SYM_L_THUMBS___,  ___SYM_R_THUMBS___,  _______
#define ___ADJ_4THUMBS___   _______, ___ADJ_L_THUMBS___,  ___ADJ_R_THUMBS___,  _______
#define ___DESK_4THUMBS___  _______, ___DESK_L_THUMBS___, ___DESK_R_THUMBS___, _______

// =========================================================================================================================================
// 5 Thumb Layout
// =========================================================================================================================================
#define ___BASE_5THUMBS___  _______, _______, ___BASE_L_THUMBS___, ___BASE_R_THUMBS___, _______, _______
#define ___NUM_5THUMBS___   _______, _______, ___NUM_L_THUMBS___,  ___NUM_R_THUMBS___,  _______, _______
#define ___SYM_5THUMBS___   _______, _______, ___SYM_L_THUMBS___,  ___SYM_R_THUMBS___,  _______, _______
#define ___ADJ_5THUMBS___   _______, _______, ___ADJ_L_THUMBS___,  ___ADJ_R_THUMBS___,  _______, _______
#define ___DESK_5THUMBS___  _______, _______, ___DESK_L_THUMBS___, ___DESK_R_THUMBS___, _______, _______


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case SCR_1:
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT(SS_LALT("ww")));
        }
        break;
    case SCR_2:
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT(SS_LALT("ee")));
        }
        break;
    case SCR_3:
        if (record->event.pressed) {
            SEND_STRING(SS_LSFT(SS_LALT("rr")));
        }
        break;
    }
 
    return true;
};