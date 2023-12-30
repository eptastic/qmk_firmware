/**
 * Copyright 2022 Charly Delay <charly@codesink.dev> (@0xcharly)
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

enum charybdis_keymap_layers {
    COLEMAK = 0,
    EXTEND,
    FNUMSYM,
    POINTER
};

enum {
  TD_LBRC,
  TD_RBRC,
  TD_LPRN
};

// Tap Dance Def
tap_dance_action_t tap_dance_actions[] = {
  // Tap once for square bracket, twice for curly
  [TD_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_LCBR),
  [TD_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_RBRC, KC_RCBR),
  [TD_LPRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN)
};

#define CHARYBDIS_AUTO_SNIPING_ON_LAYER POINTER
#ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
static uint16_t auto_pointer_layer_timer = 0;

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS 1000
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS

#    ifndef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#        define CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD 8
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD
#endif     // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [COLEMAK] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮      ╭──────────────────────────────────────────────────────╮
       QK_GESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,       KC_J,    KC_L,    KC_U,    KC_Y, KC_SCLN, KC_BSLS,
  // ├──────────────────────────────────────────────────────┤      ├──────────────────────────────────────────────────────┤
KC_TAB, LGUI_T(KC_A), LALT_T(KC_R),  LSFT_T(KC_S), LCTL_T(KC_T), KC_D,   KC_H,    RCTL_T(KC_N), RSFT_T(KC_E), RALT_T(KC_I), RGUI_T(KC_O), KC_QUOT,
  // ├──────────────────────────────────────────────────────┤      ├──────────────────────────────────────────────────────┤
       CW_TOGG,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_K,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, LT(3, KC_NO),
  // ╰──────────────────────────────────────────────────────┤      ├──────────────────────────────────────────────────────╯
                                  LT(2, KC_NO),  KC_SPC, KC_PSCR,   KC_ENT,  LT(1, KC_BSPC)
  //                            ╰───────────────────────────╯      ╰──────────────────╯
  ),

  [EXTEND] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, XXXXXXX,             KC_NO,    KC_HOME,    KC_NO,    KC_NO,   KC_END,   KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,    KC_NO,    KC_LEFT,    KC_DOWN,    KC_UP, KC_RIGHT, KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, EE_CLR,  QK_BOOT,    KC_NO,    KC_NO,    KC_NO,    KC_NO, KC_NO, KC_NO,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  XXXXXXX, XXXXXXX, _______,    XXXXXXX, _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [FNUMSYM] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERCENT,    KC_NO,  KC_7, KC_8, KC_9, KC_MINUS, KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_CIRC,   KC_AMPR, KC_ASTR, TD(TD_LPRN), KC_UNDS,    KC_EQL, KC_4, KC_5, KC_6, KC_PLUS, KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_LCBR, KC_RCBR, TD(TD_LBRC),  TD(TD_RBRC), KC_GRAVE,    KC_0, KC_1,  KC_2, KC_3, KC_ENT, KC_NO,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  _______, _______, XXXXXXX,    _______, XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [POINTER] = LAYOUT(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
       XXXXXXX, KC_NO, KC_NO, KC_NO, KC_WH_U, DPI_MOD, S_D_MOD,  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, SNIPING,   KC_BTN3, KC_BTN2, KC_BTN1, DRGSCRL,    KC_NO, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI, KC_NO,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
       XXXXXXX, KC_NO, KC_NO, KC_WH_D, SNIPING, KC_NO,    KC_NO, KC_NO,  KC_NO, KC_NO, KC_NO, KC_NO,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
                                  KC_WH_L, KC_WH_R, XXXXXXX,    _______, XXXXXXX
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
};
// clang-format on
#ifdef POINTING_DEVICE_ENABLE
#    ifdef CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE
report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
    if (abs(mouse_report.x) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD || abs(mouse_report.y) > CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_THRESHOLD) {
        if (auto_pointer_layer_timer == 0) {
            layer_on(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
            rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
            rgb_matrix_sethsv_noeeprom(HSV_GREEN);
#        endif // RGB_MATRIX_ENABLE
        }
        auto_pointer_layer_timer = timer_read();
    }
    return mouse_report;
}

void matrix_scan_user(void) {
    if (auto_pointer_layer_timer != 0 && TIMER_DIFF_16(timer_read(), auto_pointer_layer_timer) >= CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_TIMEOUT_MS) {
        auto_pointer_layer_timer = 0;
        layer_off(LAYER_POINTER);
#        ifdef RGB_MATRIX_ENABLE
        rgb_matrix_mode_noeeprom(RGB_MATRIX_DEFAULT_MODE);
#        endif // RGB_MATRIX_ENABLE
    }
}
#    endif // CHARYBDIS_AUTO_POINTER_LAYER_TRIGGER_ENABLE

#    ifdef CHARYBDIS_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    charybdis_set_pointer_sniping_enabled(layer_state_cmp(state, CHARYBDIS_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE
