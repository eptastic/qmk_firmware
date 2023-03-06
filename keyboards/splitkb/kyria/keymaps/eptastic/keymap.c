/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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

enum layers {
    COLEMAK = 0,
    EXTEND,
    FNUMSYM,
    LNUM,
    DOTA 
};

enum {
    TD_LBRC,
    TD_RBRC,
    TD_EQL_PLS,
};

// Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for square bracket, twice for curly bracket
  [TD_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
  [TD_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
  [TD_EQL_PLS] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_PLUS),
};




 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/*
 * Base Layer: COLEMAK 
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  `/~   |   Q  |   W  |   F  |   P  |   G  |                              |   J  |   L  |   U  |   Y  |   ;  |  | \   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |   A  |   R  |   S  |   T  |   D  |                              |   H  |   N  |   E  |   I  |   O  |  ' "   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  TO 2  |   Z  |   X  |   C  |   V  |   B  |PrtSc|CAPS_WRD  |Leader| NO   |   K  |   M  | ,  < | . >  | /  ? |  N/A   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | n/a  |      |  ALT |Space |Gui+ALT| |Enter | BKSP | MO 2 | N/A  | MUTE |
 *                        |      |      |      |      |      |  |      |(LT,1)|      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */


    [COLEMAK] = LAYOUT(
    QK_GESC, KC_Q, KC_W, KC_F, KC_P, KC_G,                                     KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSLS, 
    
    KC_TAB, LGUI_T(KC_A), LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_D,     KC_H, RCTL_T(KC_N), RSFT_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O), KC_QUOT, 

    TG(3), KC_Z, KC_X, KC_C, KC_V, KC_B, KC_PSCR, CW_TOGG,      TG(4), KC_NO, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO, 

                          KC_NO, KC_NO, KC_LALT, KC_SPC, LAG(KC_NO), KC_ENT, LT(1,KC_BSPC), MO(2), KC_NO, KC_MUTE

        ),

/*
 * Base Layer: EXTEND 
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  WH_U  |   NO  | NO  | WBAK | WFWD | MS_U |                              | PG_UP| HOME | NO   |  END |   DEL|  ESC   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  WH_D  | LGUI  |  ALT |  SH | CTR  | MS_D |                              | PG_D |  LEFT| DOWN | UP   | RIGHT|  APP   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |   -    |   Z  |   X  |   C  |   V  |  MS_L| MS_R | NO   |  |   NO |  RWD | FFRD | MB1  | MB2  |  MB3 |  NO  |   -    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |   -  |  -   |  -   |  -   |  -   |  |  -   |      |      |      |   -  |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [EXTEND] = LAYOUT(
            KC_WH_U, KC_NO, KC_NO, KC_WBAK, KC_WFWD, KC_MS_U,              KC_PGUP, KC_HOME, KC_NO, KC_END, KC_DEL, KC_ESC,
            
            KC_WH_D, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_MS_D,              KC_PGDN, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_APP, 
    
KC_TRNS, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_MS_L, KC_MS_R,KC_NO,    KC_NO, KC_MRWD, KC_MFFD, KC_BTN1, KC_BTN2, KC_BTN3, KC_NO, KC_TRNS, 
        
                            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_NO, KC_TRNS
        ),

/*
 * Base Layer: FNUMSYM 
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  F1    |   !  |   @  |   #  |   $  |   %  |                              |   ^  |   7  |   8  |   9  |   _  |  F10   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  F2    |   &  |   *  |  (   |   )  | _/-  |                              |  =/+ |   4  |   5  |   6  |   NO |  F11   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  F3    |   f4 |   f5 |  [/{ | ]/}  |  ~/`  | f6  | f7   |  |  f8  |   f9 |  0   |   1  |   2  |   3  | ENTER|  F12   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      | LGUI |  |      |      |      | N/A  |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *
 */
    [FNUMSYM] = LAYOUT(
            KC_F1, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERCENT, KC_CIRC, KC_7, KC_8, KC_9, KC_UNDS, KC_F10, 
            
            KC_F2, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_MINS, TD(TD_EQL_PLS), KC_4, KC_5, KC_6, KC_NO, KC_F11,
            
            KC_F3, KC_F4, KC_F5, TD(TD_LBRC), TD(TD_RBRC), KC_GRAVE, KC_F6, KC_F7, KC_F8, KC_F9, KC_0, KC_1, KC_2, KC_3, KC_ENT, KC_F12, 
            
            KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LGUI, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
            ),




    [LNUM] = LAYOUT(
            KC_NO, KC_NO, KC_7, KC_8, KC_9, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
            
            KC_NO, KC_NO, KC_4, KC_5, KC_6, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
            
        TG(3), KC_NO, KC_1, KC_2, KC_3, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
            
           KC_NO, KC_NO, KC_NO, KC_0, KC_ENT, KC_NO, LT(1,KC_BSPC), KC_NO, KC_NO, KC_NO
            ),



/*
 * Base Layer: DOTA
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |   1  |   2  |   3  |   4  |   5  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  TAB   |   q  |   w  |  e   |   r  |   t  |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  CTRL  |   a  |   x  |  c   |  d   |   f  |  g  | f9   |   | DOTA |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |  `   | ALT  |  f3  |  SPC |  f4  |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *
 */

 [DOTA] = LAYOUT(
            
    QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5,                                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
    
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 

    KC_LCTL, KC_A, KC_X, KC_C, KC_D, KC_F, KC_G, KC_F9,      TG(4), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 

    KC_GRAVE, KC_LALT, KC_F3, KC_SPC, KC_F4,     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
    )
     
 };



#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    
    if (index == 0) {  // First encoder
        // Page Up/Page Down
        if (clockwise) {
            tap_code(KC_DOWN);
        } else {
            tap_code(KC_UP);
        }
    }
    else if (index == 1) {
        // Volume Ctrl
		if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}
#endif
