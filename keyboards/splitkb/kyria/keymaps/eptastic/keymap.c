/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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


#define _COLEMAK 0
#define _EXTEND 1
#define _FNUMSYM 2

enum custom_keycodes {
    _COLEMAK = SAFE_RANGE,
    _EXTEND,
    _FNUMSYM,
};





 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * Base Layer: COLEMAK 
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  `/~   |   Q  |   W  |   F  |   P  |   G  |                              |   J  |   L  |   U  |   Y  |   ;  |  | \   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |   A  |   R  |  S   |   T  |   D  |                              |   H  |   N  |   E  |   I  |   O  |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |CAPS_WRD|   Z  |   X  |   C  |   V  |   B  |      |      |  |      |Leader|   K  |   M  | ,  < | . >  | /  ? |  N/A   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | RE1  |  MEH |      | Space| Bksp |  | Hyper|Enter | MO 2 | N/A  | RE2  |
 *                        |      |      | Esc  |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */


    [_COLEMAK] = LAYOUT(
    KC_GRV, KC_Q, KC_W, KC_F, KC_P, KC_G,                                     KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSLS, 
    
    KC_TAB, LGUI_T(KC_A), LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_D,     KC_H, RCTL_T(KC_N), RSFT_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O), KC_QUOT, 

    CAPS_WORD, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO, KC_NO,      KC_NO, KC_LEAD, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO, 

                          KC_NO, MEH(KC_NO), KC_ESC, KC_SPC, LT(1,KC_BSPC), HYPR(KC_NO), KC_ENT, MO)(2), KC_NO, KC_NO),

    [_EXTEND] = LAYOUT(
            KC_GRV, KC_ESC, KC_WH_U, KC_WBAK, KC_WFWD, KC_MS_U, KC_PGUP, KC_HOME, KC_UP, KC_END, KC_DEL, KC_ESC, KC_NO, KC_LALT, KC_WH_D, KC_LSFT, KC_LCTL, KC_MS_D, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC, KC_APP, KC_TRNS, KC_UNDO, KC_CUT, KC_COPY, KC_PSTE, KC_FIND, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN3, KC_BTN2, KC_MS_L, KC_MS_R, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [_FNUMSYM] = LAYOUT(
            KC_F1, KC_F2, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PLUS, KC_P7, KC_P8, KC_P9, KC_F7, KC_F8, KC_F3, KC_F4, KC_CIRC, KC_LPRN, KC_RPRN, KC_NO, KC_UNDS, KC_P4, KC_P5, KC_P6, KC_F9, KC_F10, KC_F5, KC_F6, KC_NO, KC_LCBR, KC_RCBR, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_ASTR, KC_P1, KC_P2, KC_P3, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_TRNS) 

};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Page Up/Page Down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    else if (index == 1) {
        // Volume Ctrl
		if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
    return true;
}
#endif
