#include QMK_KEYBOARD_H

// Keep the base layers first: DF() sets the default layer, and the
// Sym/Fn layers must sit above whichever base layer is active.
enum layers {
    _QWERTY,
    _WORKMAN,
    _SYM,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    // Layer 0: QWERTY
    // Thumbs: Esc (hold Alt), Shift, Tab (hold Ctrl) | Enter (hold Super), Space (hold Sym), Backspace (hold Fn)
    [_QWERTY] = LAYOUT_split_3x5_3(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,

        LALT_T(KC_ESC), KC_LSFT, LCTL_T(KC_TAB),        LGUI_T(KC_ENT), LT(_SYM, KC_SPC), LT(_FN, KC_BSPC)
    ),

    // Layer 1: Workman (same thumb keys as QWERTY)
    [_WORKMAN] = LAYOUT_split_3x5_3(
        KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,       KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN,
        KC_A,    KC_S,    KC_H,    KC_T,    KC_G,       KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,
        KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,       KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH,

        LALT_T(KC_ESC), KC_LSFT, LCTL_T(KC_TAB),        LGUI_T(KC_ENT), LT(_SYM, KC_SPC), LT(_FN, KC_BSPC)
    ),

    // Layer 2: Symbols, numbers and arrows
    // (legends assume a UK OS layout: Shift+2 = ", Shift+3 = £, Shift+' = @)
    [_SYM] = LAYOUT_split_3x5_3(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT,
        KC_NUBS, KC_MINS, KC_LPRN, KC_LBRC, KC_LCBR,    KC_RCBR, KC_RBRC, KC_RPRN, KC_EQL,  KC_NUHS,

        _______, _______, _______,                      _______, _______, _______
    ),

    // Layer 3: Function keys + base layer switch
    // S = switch to QWERTY, D = switch to Workman (persists until you switch again)
    [_FN] = LAYOUT_split_3x5_3(
        KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        KC_F1,   DF(_QWERTY), DF(_WORKMAN), XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F12,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,

        _______, _______, _______,                      _______, _______, _______
    )
};
