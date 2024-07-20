/* Copyright 2023 Brian Low
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keymap_us_international_linux.h"

enum layer_names {
	_BASE,
	_SYM,
	_NAV,
	_FUN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''--------------------------- '
 */

[_BASE] = LAYOUT(
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_GRV,
  KC_ESC,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSPC,
  KC_TAB,   KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V, KC_MUTE,      KC_MPLY, KC_K,    KC_H, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT,
                 KC_LGUI,KC_LALT,KC_LCTL,MO(_SYM), KC_SPC,        KC_ENT,  MO(_NAV), KC_RCTL, KC_RALT, KC_RGUI
),
/*
 * SYMBOL
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |     |       |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  ESC |   %  |   $  |      |      |                    |      |   ^  |   ~  |   '  |   "  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  <   |   {  |   [  |   (  |  \   |-------.    ,-------|      |   /  |   )  |   ]  |   }  |  >   |
 * |------+------+------+------+------+------| SAME  |    | SAME  |------+------+------+------+------+------|
 * |      |   !  |   @  |   #  |   &  |   |  |-------|    |-------|      |   *  |   -  |   =  |   +  |   ?  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_SYM] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
  XXXXXXX, KC_ESC,  US_PERC, US_DLR, XXXXXXX,  XXXXXXX,                    XXXXXXX, US_CIRC, US_TILD, US_QUOT,  US_LDQU, KC_GRV,
  XXXXXXX, US_LABK, US_LCBR, US_LBRC, US_LPRN, US_BSLS,                    XXXXXXX, US_SLSH, US_RPRN, US_RBRC,  US_RCBR, US_RABK,
  XXXXXXX, US_EXLM, US_AT,   US_HASH, US_AMPR, US_PIPE, KC_MUTE,  KC_MPLY, XXXXXXX, US_ASTR, US_MINS, US_EQL,   US_PLUS, US_QUES,
          KC_LGUI ,KC_LALT ,KC_LCTL, MO(_SYM),  KC_SPC,                      KC_ENT,  MO(_NAV), KC_RCTL, KC_RALT, KC_RGUI
),
/*
 * NAVIGATION
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |     |       |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | ESC  |   1  |   2  |  3   |      |                    |      | Home |  UP  |  END | PGUP |  INS |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   0  |   4  |  5   |  6   |      |-------.    ,-------|      | LEFT | DOWN |RIGHT | PGDN | FIND |
 * |------+------+------+------+------+------| SAME  |    | SAME  |------+------+------+------+------+------|
 * |      |      |   7  |   8  |  9   |      |-------|    |-------|       | BKSPC|  ENT |  DEL | PRINT| UNDO |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_NAV] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
  XXXXXXX, KC_ESC,  KC_1,    KC_2,    KC_3,    XXXXXXX,                    XXXXXXX, KC_HOME, KC_UP,   KC_END,   KC_PGUP, KC_INS,
  XXXXXXX, KC_0,    KC_4,    KC_5,    KC_6,    XXXXXXX,                    XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, KC_FIND,
  XXXXXXX, XXXXXXX, KC_7,    KC_8,    KC_9,    XXXXXXX, KC_MUTE,  KC_MPLY, XXXXXXX, KC_BSPC, KC_ENT,  KC_DEL,   KC_PSCR, KC_UNDO,
          KC_LGUI ,KC_LALT ,KC_LCTL, MO(_SYM),  KC_SPC,                      KC_ENT,  MO(_NAV), KC_RCTL, KC_RALT, KC_RGUI
),
/*
 * FUNCTION
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |     |       |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F1  |  F2  |  F3  |  F4  |      |                    |      | RWND |  P/PA| FWRD |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |-------.    ,-------|      | LowV | MUTE |  HiV |      |      |
 * |------+------+------+------+------+------| SAME  |    | SAME  |------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Space  /       \Enter \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_FUN] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
  XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,                    XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT,  XXXXXXX, XXXXXXX,
  XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,                    XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU,  XXXXXXX, XXXXXXX,
  XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, KC_MUTE,  KC_MPLY, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,
          KC_LGUI ,KC_LALT ,KC_LCTL, MO(_SYM),  KC_SPC,                      KC_ENT,  MO(_NAV), KC_RCTL, KC_RALT, KC_RGUI
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
   return update_tri_layer_state(state, _SYM, _NAV, _FUN);
}

#ifdef OLED_ENABLE

// QMK Logo Definition
static const char PROGMEM qmk_logo[] = {
    0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
    0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
    0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00

};

static void render_logo(void) {
    oled_write_P(qmk_logo, false);
}

static void render_status(void) {
    // Print current layer
    oled_write_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("BASE"), false);
            break;
        case _SYM:
            oled_write_P(PSTR("SYM"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("NAV"), false);
            break;
        case _FUN:
            oled_write_P(PSTR("FUN"), false);
            break;
        default:
            oled_write_P(PSTR("???"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();
    } else {
        render_logo();
    }
    return false;
}

#endif

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
  [_BASE] =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
  [_SYM]  =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
  [_NAV]  =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
  [_FUN]  =  { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) }
};
#endif
