/*
This is the keymap for the keyboard

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2017 Art Ortenburger

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _WORKMAN 0
#define _SYMBOL 1
#define _NAV 2
#define _ADJUST 16


// Fillers to make layering more clear
#define _______  KC_TRNS
#define XXXXXXX KC_NO

#define LS__SPC MT(MOD_LSFT, KC_SPC)
#define LC_BSPC MT(MOD_LCTL, KC_BSPC)
#define ALT_ENT MT(MOD_LALT,KC_ENT)
#define CTRL__L LCTL(KC_LEFT)
#define CTRL__U LCTL(KC_UP)
#define CTRL__D LCTL(KC_DOWN)
#define CTRL__R LCTL(KC_RIGHT)
#define SYMBOL TT(_SYMBOL)
#define NAV TT(_NAV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  
  [_WORKMAN] = LAYOUT( \
    KC_BSLS, KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,                                                                   KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_UNDS, \
    KC_TAB,  KC_A,    KC_S,    KC_H,    KC_T,    KC_G,             KC_DEL,  KC_MEH,           KC_HYPR, KC_ESC,           KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_QUOT, \
    KC_GRV,  KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    SYMBOL,  LC_BSPC, ALT_ENT,          KC_LGUI, LS__SPC, NAV,     KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, KC_PLUS  \
  ),

  [_SYMBOL] = LAYOUT( \
    XXXXXXX, KC_F1,   KC_F2,   KC_F3,   KC_F4,   XXXXXXX,                                                                KC_LCBR, KC_1,    KC_2,    KC_3,    KC_RCBR, XXXXXXX, \
    XXXXXXX, KC_F5,   KC_F6,   KC_F7,   KC_F8,   XXXXXXX,           _______, _______,         _______, _______,          KC_LBRC, KC_4,    KC_5,    KC_6,    KC_RBRC, XXXXXXX, \
    XXXXXXX, KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX,  _______, _______, _______,         _______, _______, _______, XXXXXXX, KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX  \
  ),

  [_NAV] = LAYOUT( \
    XXXXXXX, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, XXXXXXX,                                                                 XXXXXXX, KC_HOME, KC_PGUP, KC_PGDN, KC_END,   XXXXXXX, \
    XXXXXXX, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R, KC_MUTE,           KC_BTN3, KC_MPLY,          _______, _______,          XXXXXXX, KC_LEFT, KC_UP,   KC_DOWN, KC_RIGHT, XXXXXXX, \
    XXXXXXX, KC_MPRV, KC_VOLU, KC_VOLD, KC_MNXT, XXXXXXX,  _______, KC_BTN1, KC_BTN2,          _______, _______, _______, XXXXXXX, CTRL__L, CTRL__U, CTRL__D, CTRL__R,  XXXXXXX \
  ),

  [_ADJUST] =  LAYOUT( \
    _______, RESET,   _______, _______, _______, _______,                                                                _______, _______, _______, _______, _______, KC_DEL,  \
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM,          _______, _______,          _______, _______,          AG_SWAP, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY  \
  )


};

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _SYMBOL, _NAV, _ADJUST);
}