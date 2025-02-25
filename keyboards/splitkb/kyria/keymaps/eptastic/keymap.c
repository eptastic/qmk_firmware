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
	GAMING
};

//  Tap Dance
enum {
    TD_LBRC,
    TD_RBRC,
    TD_EQL_PLS,
    TD_LPRN
};

// Macros
enum {
    M_USN = SAFE_RANGE
};

// Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for square bracket, twice for curly bracket
  [TD_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
  [TD_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
  // Tap once for equals, twice for plus (removed)
  [TD_EQL_PLS] = ACTION_TAP_DANCE_DOUBLE(KC_EQL, KC_PLUS),
  // Tap once for ( twice for ).
  [TD_LPRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN)
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
 * | CAPS   |   Z  |   X  |   C  |   V  |   B  |PrtSc |  NO  |  |CA-Dl |CS_Esc|   K  |   M  | ,  < | . >  | /  ? |  TG(3)   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |  enc |  ALT |  ESC |Space | M_USN| |Enter | BKSP | MO 2 | N/A  | MUTE |
 *                        |      |      |      |      |      |  |      |(LT,1)|      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */


    [COLEMAK] = LAYOUT(
    QK_GESC, KC_Q, KC_W, KC_F, KC_P, KC_G,                                     KC_J, KC_L, KC_U, KC_Y, KC_SCLN, KC_BSLS,

    KC_TAB, LGUI_T(KC_A), LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_D,     KC_H, RCTL_T(KC_N), RSFT_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O), KC_QUOT, 

    CW_TOGG, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_PSCR, KC_NO,      LCA(KC_DELETE), RCS(KC_ESC), KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, TG(3),

                          KC_NO, KC_NO, KC_ESC, KC_SPC, M_USN, KC_ENT, LT(1,KC_BSPC), MO(2), KC_NO, KC_MUTE

        ),

/*
 * Base Layer: EXTEND
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  WH_U  |   NO  | NO  | WBAK | WFWD | MS_U |                              | PG_UP| HOME | APP  |  END |   DEL|  MS_UP |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  WH_D  | LGUI  |  ALT |  SH | CTR  | MS_D |                              | PG_D |  LEFT| DOWN | UP   | RIGHT|  MS_D  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |   -    |   Z  |   X  |   C  |   V  |  NO  | MS_L | MS_R |  |   NO |  RWD | FFRD | MB1  | MB2  |  MB3 |  NO  |   NO   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |   -  |  -   |  -   |  -   |  -   |  |  -   |      |      |      |   -  |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [EXTEND] = LAYOUT(
            KC_WH_U, KC_NO, KC_NO, KC_WBAK, KC_WFWD, KC_MS_U,              KC_PGUP, KC_HOME, KC_APP, KC_END, KC_DEL, KC_MS_U,

            KC_WH_D, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_MS_D,              KC_PGDN, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_MS_D, 

KC_NO, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), KC_NO, KC_MS_L,KC_MS_R ,    KC_NO, KC_MRWD, KC_MFFD, KC_BTN1, KC_BTN2, KC_BTN3, KC_NO, KC_NO, 

                            KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
        ),

/*
 * Base Layer: FNUMSYM
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  F10   |   !  |   @  |   #  |   $  |   %  |                              |      |   7  |   8  |   9  |   -  |  F1    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  F11   |   ^  |   &  |   *  | (/)  |   _  |                              |   =  |   4  |   5  |   6  |   +  |  F2    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  F12   |   {  |   }  |  [/{ | ]/}  |  `   | f6   | f7   |  |  f8  |   f9 |  0   |   1  |   2  |   3  | ENTER|  F3    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | enc  | F4   |  F5  | SPC  | LGUI |  |      |      |      |      |  enc |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 *
 */
    [FNUMSYM] = LAYOUT(
  KC_F10, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERCENT,                             KC_NO, KC_7, KC_8, KC_9, KC_MINUS, KC_F1,

  KC_F11, KC_CIRC, KC_AMPR, KC_ASTR, TD(TD_LPRN), KC_UNDS,                          KC_EQL, KC_4, KC_5, KC_6, KC_PLUS, KC_F2,

  KC_F12, KC_LCBR, KC_RCBR, TD(TD_LBRC), TD(TD_RBRC), KC_GRAVE, KC_F6, KC_F7,      KC_F8, KC_F9, KC_0, KC_1, KC_2, KC_3, KC_ENT, KC_F3,

  KC_NO, KC_F4, KC_F5, KC_SPC, KC_LGUI,                                             KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
),


/*
 * GAMING
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  `/~   |   E  |   1  |   2  |   3  |   R   |                              |   NO  |   NO  |   NO  |   NO  |   NO  |NO |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  Tab   |   Q  |   A  |   W  |   S  |   K |                              |   NO  |   NO  |   NO  |  NO   |   NO  | NO|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  LSHIFT|   Z  |   X  |   D  |   C  |   B  |PrtSc |  NO  |  | NO | NO |   NO  |  NO  | NO  | NO  | NO  |  NO  | TG(3)
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |  enc |  NO |  J    |Space |  NO   |  | NO | NO | NO | N/A  | MUTE |
 *                        |      |      |      |      |      |  |    |    |    |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */


    [GAMING] = LAYOUT(
    QK_GESC, KC_E, KC_1, KC_2, KC_3, KC_R,                                     KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

    KC_TAB, KC_Q, KC_A, KC_W, KC_D, KC_K,                                         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,

    KC_LSFT, KC_Z, KC_X, KC_S, KC_C, KC_B, KC_PSCR, KC_NO,      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, TG(3),

                          KC_NO, KC_NO, KC_J, KC_SPC, KC_NO,   KC_NO, KC_NO, KC_NO, KC_NO, KC_MUTE

        )


};


bool process_record_user(uint16_t keycode, keyrecord_t *record){
    switch (keycode){
        case M_USN:
            if (record->event.pressed){
                // When keycode M_USN is pressed
                SEND_STRING("alex@connective.com.au");
            } else {
                // When keycode M_USN is released
            }
            break;
    }
    return true;
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
