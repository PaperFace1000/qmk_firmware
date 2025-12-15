/* Copyright 2023 @ Keychron (https://www.keychron.com)
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
#include "keychron_common.h"
#include <print.h>

enum layers{
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
};

// keychron_common.hで定義されているSAFE_RANGEの後に追加のカスタムキーコードを定義
enum {
    EMACS_CTRL_K = SAFE_RANGE,
    WIN_SPACE,
    WIN_SPACE_JP,
    CUSTOM_KC_LBRC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_91_ansi(
        KC_MUTE,  KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,   RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,    KC_VOLU,  KC_INS,   KC_DEL,   KC_HOME,
        MC_1,     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        MC_2,     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        MC_3,     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_HOME,
        MC_4,     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        MC_5,     KC_LCTL,  KC_LOPT,  KC_LCMD,  MO(MAC_FN),         KC_SPC,                        KC_SPC,             KC_RCMD,  MO(MAC_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_91_ansi(
        RGB_TOG,  _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   _______,  _______,  RGB_TOG,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,   _______,  _______,  _______,  _______,  _______,  _______,    _______,  _______,            _______,
        _______,  _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,   _______,  _______,  _______,  _______,  _______,  _______,              _______,            _______,
        _______,  _______,            _______,  _______,  _______,  _______,   _______,  NK_TOGG,  _______,  _______,  _______,  _______,              _______,  _______,
        _______,  _______,  _______,  _______,  _______,            _______,                       _______,            _______,  _______,    _______,  _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_91_ansi(
        KC_MUTE,  KC_ESC,            KC_F1,    KC_F2,                   KC_F3,            KC_LWIN,  KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,     KC_F12,   KC_INS,   KC_DEL,   KC_HOME,
        MC_1,     KC_GRV,            KC_1,     KC_2,                    KC_3,             KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,    KC_EQL,   KC_BSPC,            KC_PGUP,
        MC_2,     KC_TAB,            KC_Q,     KC_W,                    KC_E,             KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,    KC_RBRC,  KC_BSLS,            KC_PGDN,
        MC_3,     MO(WIN_FN),        KC_A,     KC_S,                    KC_D,             KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,              KC_ENT,             KC_HOME,
        MC_4,     KC_LSFT,                     KC_Z,                    KC_X,             KC_C,     KC_V,      KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,              KC_RSFT,  KC_UP,
        MC_5,     KC_LCTL,           KC_LALT,  LCTL_T(KC_F13),          KC_LWIN,          KC_SPC,                        KC_SPC,        RCTL_T(KC_F14),  MO(WIN_FN), KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_91_ansi(
        _______,  _______,     _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,     _______,     _______,     _______,     _______,  _______,     _______,     _______,
        _______,  _______,     _______,  _______,  _______,  _______,    _______,  _______,  _______,  _______,     _______,     _______,     _______,     _______,  _______,                  _______,
        _______,  C(KC_TAB),   C(KC_Q),  C(KC_W),  KC_END,   C(KC_R),    C(KC_T),  C(KC_Y),  C(KC_U),  C(KC_I),     C(KC_O),     KC_UP,     C(KC_LBRC),  C(KC_RBRC),  C(KC_BSLS),         _______,
        _______,  _______,     KC_HOME,  C(KC_S),  KC_DEL,   KC_RGHT,    C(KC_G),  KC_BSPC,  C(KC_J),  C(KC_K),     C(KC_L),     KC_ESC,      KC_F10,                   C(KC_ENT),           _______,
        _______,  C(KC_LSFT),            C(KC_Z),  C(KC_X),  C(KC_C),    C(KC_V),  KC_LEFT,  KC_DOWN,  KC_ENT,      C(KC_DOT),   C(KC_COMM), C(KC_SLSH),               C(KC_RSFT),  _______,
        _______,  _______,     _______,  _______,  _______,              _______,                     C(KC_SPC),                 C(KC_SPC),   _______,     _______,     _______,     _______,  _______
    ),
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_WH_L, KC_WH_R) },
    [MAC_FN]   = { ENCODER_CCW_CW(RGB_VAD, RGB_VAI), ENCODER_CCW_CW(KC_WH_L, KC_WH_R)},
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_WH_L, KC_WH_R)},
    [WIN_FN]   = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_WH_L, KC_WH_R)},
};
#endif // ENCODER_MAP_ENABLE

// clang-format on

/* デバッグ用 */
void keyboard_post_init_user(void) {
  // 希望する動作に合わせて値をカスタマイズします
//   debug_enable=true;
//   debug_matrix=true;
  debug_keyboard=false;
  debug_mouse=false;
}

void housekeeping_task_user(void) {
    housekeeping_task_keychron();
}
