/*
Copyright 2023 Spencer Deven <splitlogicdesign@gmail.com>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum zodiarkpi_layers {
      /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
      _QWERTY,
      _SHIFT,
      _RAISE,
      _LOWER,
      _ADJUST,
      _COLEMAK
};
  
enum custom_keycodes {
      KC_QWERTY = SAFE_RANGE,
      KC_COLEMAK,
      KC_LOWER,
      KC_RAISE,
      KC_ADJUST,
      KC_PRVWD,
      KC_NXTWD,
      KC_LSTRT,
      KC_LEND,
      KC_DLINE
};
  
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* QWERTZ
   * .-----------------------------------------.                                .------------------------------------------.
   * |  ESC |   1  |   2  |   3  |   4  |   5  |                                |   6  |   7  |   8  |   9  |   0  |   ß   |
   * |------+------+------+------+------+------|                                |------+------+------+------+------+-------|
   * |  Tab |   Q  |   W  |   E  |   R  |   T  |       /-----\    /-----\       |   Z  |   U  |   I  |   O  |   P  |   Ü   |
   * |------+------+------+------+------+------|------(  Mute )  (  RGB  )------|------+------+------+------+------+-------|
   * | Caps |   A  |   S  |   D  |   F  |   G  |   +  |\-----/|  |\-----/|   #  |   H  |   J  |   K  |   L  |   Ö  |   Ä   |
   * |------+------+------+------+------+------|------|-------|  |-------|------|------+------+------+------+------+-------|
   * |LShift|   Y  |   X  |   C  |   V  |   B  |BackSp|   {   |  |   }   |  Del |   N  |   M  |   ,  |   .  |   -  |RShft/´|
   * |------+------+------+------+------+------|------|-------|  |-------|------|------+------+------+------+------|-------|
   * | Ctrl |  Win |   <  |  Alt | Lower|    Space    | Enter |  | Enter |    Space    | Raise| Left |  Up  | Down | Right |
   * `--------------------------------------------------------'  '---------------------------------------------------------´
   */
  
      [_QWERTY] = LAYOUT(
        KC_ESC,             KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                         KC_6,   KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,             KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                         KC_Y,   KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
        CW_TOGG,            KC_A,    KC_S,    KC_D,    KC_F,    KC_G,  KC_RBRC, KC_MUTE,    RGB_TOG, KC_NUHS, KC_H,   KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        LM(_SHIFT,MOD_LSFT),KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_BSPC, ALGR(KC_0),ALGR(KC_7),KC_DEL, KC_N,   KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT(MOD_RSFT, KC_EQL),
        KC_LCTL,            KC_LGUI, KC_NUBS, KC_LALT, KC_LOWER,   KC_SPC,      KC_ENT,        KC_ENT,      KC_SPC,   KC_RAISE,KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
      ),
  
  /* Shift
   * .-----------------------------------------.                                .------------------------------------------.
   * |   °  |   1  |   2  |   3  |   4  |   5  |                                |   6  |   7  |   8  |   9  |   0  |   ß   |
   * |------+------+------+------+------+------|                                |------+------+------+------+------+-------|
   * |  Tab |   Q  |   W  |   E  |   R  |   T  |       /-----\    /-----\       |   Z  |   U  |   I  |   O  |   P  |   Ü   |
   * |------+------+------+------+------+------|------(   -   )  (   -   )------|------+------+------+------+------+-------|
   * | Caps |   A  |   S  |   D  |   F  |   G  |   +  |\-----/|  |\-----/|   #  |   H  |   J  |   K  |   L  |   Ö  |   Ä   |
   * |------+------+------+------+------+------|------|-------|  |-------|------|------+------+------+------+------+-------|
   * |LShift|   Y  |   X  |   C  |   V  |   B  |  Del |   (   |  |   )   |  Del |   N  |   M  |   ,  |   .  |   -  |   ´   |
   * |------+------+------+------+------+------|------|-------|  |-------|------|------+------+------+------+------|-------|
   * | Ctrl |  Win |  Alt |   <  | Lower|    Space    | Enter |  | Enter |    Space    | Raise| Left | Down |  Up  | Right |
   * `--------------------------------------------------------'  '---------------------------------------------------------´
   */
  
      [_SHIFT] = LAYOUT(
        KC_GRV,  _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, KC_DEL,     KC_8,    KC_9, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,      _______,     _______, _______,      _______,     _______, _______, _______, _______, _______
      ),
  
  /* RAISE
   * .-----------------------------------------.                                .------------------------------------------.
   * |   ^  |   -  |   -  |   -  |   -  |   -  |                                |   -  |   -  |   -  |   -  |   -  |   -   |
   * |------+------+------+------+------+------|                                |------+------+------+------+------+-------|
   * |   -  |   -  |   -  |   -  |   -  |   -  |       /-----\    /-----\       |   -  |   -  |  Up  |   -  |   -  |   -   |
   * |------+------+------+------+------+------|------(   -   )  (   -   )------|------+------+------+------+------+-------|
   * | Caps |  PgD |  PgU | Home |  End |   -  |   -  |\-----/|  |\-----/|   -  |   -  | Left | Down |Right |   -  |   -   |
   * |------+------+------+------+------+------|------|-------|  |-------|------|------+------+------+------+------+-------|
   * |   -  |   -  |   -  |   -  |   -  |   -  |   -  |   <   |  |   >   |   -  |   -  | F10  | F11  |  F5  |   -  |   -   |
   * |------+------+------+------+------+------|------|-------|  |-------|------|------+------+------+------+------|-------|
   * |   -  |   -  |   -  |   -  |   -  |      -      |   -   |  |   -   |      -      |   -  |   -  |   -  |   -  |   -   |
   * `--------------------------------------------------------'  '---------------------------------------------------------´
   */
  
      [_RAISE] = LAYOUT(
        KC_GRV,  _______, _______, _______, _______,  _______,                                       _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______,  _______,                                       _______, _______, KC_UP,   _______, _______, _______,
        KC_CAPS, KC_PGDN, KC_PGUP, KC_HOME, KC_END,   _______, _______, _______, _______, _______,   _______, KC_LEFT, KC_DOWN, KC_RIGHT,_______, _______,
        _______, _______, _______, _______, _______,  _______, _______,KC_NUBS,S(KC_NUBS),_______,   _______, KC_F10,  KC_F11,  KC_F5,   _______, _______,
        _______, _______, _______, _______, KC_ADJUST,     _______,     _______, _______,       _______,      _______, _______, _______, _______, _______
      ),
  
  /* LOWER
   * .-----------------------------------------.                                .------------------------------------------.
   * |   ^  |  F1  |  F2  |  F3  |  F4  |  F5  |                                |  F6  |  F7  |  F8  |  F9  | F10  |  F11  |
   * |------+------+------+------+------+------|                                |------+------+------+------+------+-------|
   * |   -  |   /  |   7  |   8  |   9  |   -  |       /-----\    /-----\       |   /  |   7  |   8  |   9  |   -  |  F12  |
   * |------+------+------+------+------+------|------(   -   )  (   -   )------|------+------+------+------+------+-------|
   * | Caps |   *  |   4  |   5  |   6  |   +  |  F15 |\-----/|  |\-----/| F16  |   *  |   4  |   5  |   6  |   +  |  F13  |
   * |------+------+------+------+------+------|------|-------|  |-------|------|------+------+------+------+------+-------|
   * |   -  | UNDO |   1  |   2  |   3  |   .  |   -  |   [   |  |   ]   |   -  | Num  |   1  |   2  |   3  |   .  |  F14  |
   * |------+------+------+------+------+------|------|-------|  |-------|------|------+------+------+------+------|-------|
   * |   -  |   -  |   0  |   ,  |   -  |      -      |   -   |  |   -   |     -       |   -  |   0  |   ,  | Enter|   =   |
   * `--------------------------------------------------------'  '---------------------------------------------------------´
   */
  
      [_LOWER] = LAYOUT(
        KC_GRV,  KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_F5,                                          KC_F6,   KC_F7,    KC_F8, KC_F9,   KC_F10,  KC_F11,
        _______, KC_P7,   KC_P7,  KC_P8,  KC_P9,  KC_PMNS,                                        KC_PSLS, KC_P7,    KC_P8, KC_P9,   KC_PMNS, KC_F12, 
        KC_CAPS, KC_P4,   KC_P4,  KC_P5,  KC_P6,  KC_PPLS, KC_F15,  _______,  _______,    KC_F16, KC_PAST, KC_P4,    KC_P5, KC_P6,   KC_PPLS, KC_F13, 
        _______, KC_UNDO, KC_P1,  KC_P2,  KC_P3,  KC_COMM, _______,ALGR(KC_8),ALGR(KC_9),_______, KC_NUM,  KC_P1,    KC_P2, KC_P3,   KC_DOT,  KC_F14, 
        _______, _______, KC_P0,  KC_PDOT,_______,     _______,     _______,  _______,       _______,      KC_ADJUST,KC_P0, KC_PDOT, KC_PENT, KC_PEQL
      ),
  
  /* ADJUST
   * .-----------------------------------------.                                .------------------------------------------.
   * |   ^  |  F1  |  F2  |  F3  |  F4  |  F5  |                                |  F6  |  F7  |  F8  |  F9  | F10  |  F11  |
   * |------+------+------+------+------+------|                                |------+------+------+------+------+-------|
   * |   -  |   -  |   -  |   -  |NK_ON |   -  |       /-----\    /-----\       |   -  |EE_CLR|   -  |   -  |   -  |  F12  |
   * |------+------+------+------+------+------|------(   -   )  (   -   )------|------+------+------+------+------+-------|
   * |   -  |   -  |   -  |   -  |NK_OFF|   -  |   -  |\-----/|  |\-----/|   -  |   -  |RG_TOG|   -  |   -  |   -  |   -   |
   * |------+------+------+------+------+------|______|-------|  |-------|______|------+------+------+------+------+-------|
   * |   -  |   -  |   -  |   -  |   -  |   -  |   -  |   -   |  |   -   |   -  |   -  |RG_MOD|RG_SPI|RG_HUI|RG_SAI|RGB_VAI|
   * |------+------+------+------+------+------|______|-------|  |-------|______|------+------+------+------+------|-------|
   * |   -  |   -  |   -  |   -  |   -  |      -      |   -   |  |   -   |      -      |R_RMOD|RG_SPD|RG_HUD|RG_SAD|RGB_VAD|
   * `--------------------------------------------------------'  '---------------------------------------------------------´
   */
  
      [_ADJUST] = LAYOUT(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
        _______, _______, _______, _______, NK_ON,   _______,                                     _______, EE_CLR,  _______, _______, _______, KC_F12,
        _______, _______, _______, _______, NK_OFF,  _______, _______, _______, _______, _______, _______, RGB_TOG, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MOD, RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI,
        _______, _______, _______, _______, _______,      _______,     _______, _______,     _______,      RGB_RMOD,RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD
      )
  };  

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
      switch (keycode) {
          case KC_QWERTY:
              if (record->event.pressed) {
                  set_single_persistent_default_layer(_QWERTY);
              }
              return false;
          case KC_COLEMAK:
              if (record->event.pressed) {
                  set_single_persistent_default_layer(_COLEMAK);
              }
              return false;
          case KC_LOWER:
              if (record->event.pressed) {
                  layer_on(_LOWER);
                  update_tri_layer(_LOWER, _RAISE, _ADJUST);
              } else {
                  layer_off(_LOWER);
                  update_tri_layer(_LOWER, _RAISE, _ADJUST);
              }
              return false;
          case KC_RAISE:
              if (record->event.pressed) {
                  layer_on(_RAISE);
                  update_tri_layer(_LOWER, _RAISE, _ADJUST);
              } else {
                  layer_off(_RAISE);
                  update_tri_layer(_LOWER, _RAISE, _ADJUST);
              }
              return false;
          case KC_ADJUST:
              if (record->event.pressed) {
                  layer_on(_ADJUST);
              } else {
                  layer_off(_ADJUST);
              }
              return false;
          case KC_PRVWD:
              if (record->event.pressed) {
                  if (keymap_config.swap_lctl_lgui) {
                      register_mods(mod_config(MOD_LALT));
                      register_code(KC_LEFT);
                  } else {
                      register_mods(mod_config(MOD_LCTL));
                      register_code(KC_LEFT);
                  }
              } else {
                  if (keymap_config.swap_lctl_lgui) {
                      unregister_mods(mod_config(MOD_LALT));
                      unregister_code(KC_LEFT);
                  } else {
                      unregister_mods(mod_config(MOD_LCTL));
                      unregister_code(KC_LEFT);
                  }
              }
              break;
          case KC_NXTWD:
               if (record->event.pressed) {
                  if (keymap_config.swap_lctl_lgui) {
                      register_mods(mod_config(MOD_LALT));
                      register_code(KC_RIGHT);
                  } else {
                      register_mods(mod_config(MOD_LCTL));
                      register_code(KC_RIGHT);
                  }
              } else {
                  if (keymap_config.swap_lctl_lgui) {
                      unregister_mods(mod_config(MOD_LALT));
                      unregister_code(KC_RIGHT);
                  } else {
                      unregister_mods(mod_config(MOD_LCTL));
                      unregister_code(KC_RIGHT);
                  }
              }
              break;
          case KC_LSTRT:
              if (record->event.pressed) {
                  if (keymap_config.swap_lctl_lgui) {
                       //CMD-arrow on Mac, but we have CTL and GUI swapped
                      register_mods(mod_config(MOD_LCTL));
                      register_code(KC_LEFT);
                  } else {
                      register_code(KC_HOME);
                  }
              } else {
                  if (keymap_config.swap_lctl_lgui) {
                      unregister_mods(mod_config(MOD_LCTL));
                      unregister_code(KC_LEFT);
                  } else {
                      unregister_code(KC_HOME);
                  }
              }
              break;
          case KC_LEND:
              if (record->event.pressed) {
                  if (keymap_config.swap_lctl_lgui) {
                      //CMD-arrow on Mac, but we have CTL and GUI swapped
                      register_mods(mod_config(MOD_LCTL));
                      register_code(KC_RIGHT);
                  } else {
                      register_code(KC_END);
                  }
              } else {
                  if (keymap_config.swap_lctl_lgui) {
                      unregister_mods(mod_config(MOD_LCTL));
                      unregister_code(KC_RIGHT);
                  } else {
                      unregister_code(KC_END);
                  }
              }
              break;
          case KC_DLINE:
              if (record->event.pressed) {
                  register_mods(mod_config(MOD_LCTL));
                  register_code(KC_BSPC);
              } else {
                  unregister_mods(mod_config(MOD_LCTL));
                  unregister_code(KC_BSPC);
              }
              break;
          case KC_COPY:
              if (record->event.pressed) {
                  register_mods(mod_config(MOD_LCTL));
                  register_code(KC_C);
              } else {
                  unregister_mods(mod_config(MOD_LCTL));
                  unregister_code(KC_C);
              }
              return false;
          case KC_PASTE:
              if (record->event.pressed) {
                  register_mods(mod_config(MOD_LCTL));
                  register_code(KC_V);
              } else {
                  unregister_mods(mod_config(MOD_LCTL));
                  unregister_code(KC_V);
              }
              return false;
          case KC_CUT:
              if (record->event.pressed) {
                  register_mods(mod_config(MOD_LCTL));
                  register_code(KC_X);
              } else {
                  unregister_mods(mod_config(MOD_LCTL));
                  unregister_code(KC_X);
              }
              return false;
              break;
          case KC_UNDO:
              if (record->event.pressed) {
                  register_mods(mod_config(MOD_LCTL));
                  register_code(KC_Y);
              } else {
                  unregister_mods(mod_config(MOD_LCTL));
                  unregister_code(KC_Y);
              }
              return false;
      }
      return true;
  }
