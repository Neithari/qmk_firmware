/*
Copyright 2021 Spencer Deven <splitlogicdesign@gmail.com>
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

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _SHIFT,
    _COLEMAK,
    _RAISE,
    _LOWER,
    _ADJUST
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
 * |------+------+------+------+------+------|______                    ______|------+------+------+------+------+-------|
 * |  Tab |   Q  |   W  |   E  |   R  |   T  |   {  |                  |   }  |   Z  |   U  |   I  |   O  |   P  |   Ü   |
 * |------+------+------+------+------+------|______|                  |______|------+------+------+------+------+-------|
 * | Caps |   A  |   S  |   D  |   F  |   G  |   +  |                  |   #  |   H  |   J  |   K  |   L  |   Ö  |   Ä   |
 * |------+------+------+------+------+------|______|/-----\    /-----\|______|------+------+------+------+------+-------|
 * |LShift|   Y  |   X  |   C  |   V  |   B  |BackSp(  RGB  )  (  Mute )  Del |   N  |   M  |   ,  |   .  |   -  |RShft/´|
 * |------+------+------+------+------+------|______|\-----/|  |\-----/|______|------+------+------+------+------|-------|
 * | Ctrl |  Win |   <  |  Alt | Lower|    Space    | Enter |  | Enter |    Space    | Raise| Left |  Up  | Down | Right |
 * `--------------------------------------------------------'  '---------------------------------------------------------´
 */

	[_QWERTY] = LAYOUT(
      KC_ESC,             KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
      KC_TAB,             KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,  ALGR(KC_7),                ALGR(KC_0),KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
      CW_TOGG,            KC_A,    KC_S,    KC_D,    KC_F,    KC_G,  KC_RBRC,                   KC_NUHS,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      LM(_SHIFT,MOD_LSFT),KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_BSPC, RGB_TOG, KC_MUTE, KC_DEL,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, MT(MOD_RSFT, KC_EQL),
      KC_LCTL,            KC_LGUI, KC_NUBS, KC_LALT, KC_LOWER,   KC_SPC,      KC_ENT,  KC_ENT,        KC_SPC,       KC_RAISE,KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT
    ),

/* Shift
 * .-----------------------------------------.                                .------------------------------------------.
 * |   °  |   1  |   2  |   3  |   4  |   5  |                                |   6  |   7  |   8  |   9  |   0  |   ß   |
 * |------+------+------+------+------+------|______                    ______|------+------+------+------+------+-------|
 * |  Tab |   Q  |   W  |   E  |   R  |   T  |   (  |                  |   )  |   Z  |   U  |   I  |   O  |   P  |   Ü   |
 * |------+------+------+------+------+------|______|                  |______|------+------+------+------+------+-------|
 * | Caps |   A  |   S  |   D  |   F  |   G  |   +  |                  |   #  |   H  |   J  |   K  |   L  |   Ö  |   Ä   |
 * |------+------+------+------+------+------|______|/-----\    /-----\|______|------+------+------+------+------+-------|
 * |LShift|   Y  |   X  |   C  |   V  |   B  |  Del (  RGB  )  (  Mute )  Del |   N  |   M  |   ,  |   .  |   -  |   ´   |
 * |------+------+------+------+------+------|______|\-----/|  |\-----/|______|------+------+------+------+------|-------|
 * | Ctrl |  Win |  Alt |   <  | Lower|    Space    | Enter |  | Enter |    Space    | Raise| Left | Down |  Up  | Right |
 * `--------------------------------------------------------'  '---------------------------------------------------------´
 */

	[_SHIFT] = LAYOUT(
      KC_GRV,  _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, KC_8,                   KC_9, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, KC_DEL,  _______, _______, _______, _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______,      _______,     _______, _______,        _______,   _______, _______, _______, _______, _______
      ),

/* RAISE
 * .-----------------------------------------.                                .------------------------------------------.
 * |   ^  |   -  |   -  |   -  |   -  |   -  |                                |   -  |   -  |   -  |   -  |   -  |   -   |
 * |------+------+------+------+------+------|______                    ______|------+------+------+------+------+-------|
 * |   -  |   -  |   -  |   -  |   -  |   -  |   <  |                  |   >  |   -  |   -  |  Up  |   -  |   -  |   -   |
 * |------+------+------+------+------+------|______|                  |______|------+------+------+------+------+-------|
 * | Caps |  PgD |  PgU | Home |  End |   -  |   -  |                  |   -  |   -  | Left | Down |Right |   -  |   -   |
 * |------+------+------+------+------+------|______|/-----\    /-----\|______|------+------+------+------+------+-------|
 * |   -  |   -  |   -  |   -  |   -  |   -  |   -  (   -   )  (   -   )   -  |   -  | F10  | F11  |  F5  |   -  |   -   |
 * |------+------+------+------+------+------|______|\-----/|  |\-----/|______|------+------+------+------+------|-------|
 * |   -  |   -  |   -  |   -  |   -  |      -      |   -   |  |   -   |      -      |   -  |   -  |   -  |   -  |   -   |
 * `--------------------------------------------------------'  '---------------------------------------------------------´
 */

	[_RAISE] = LAYOUT(
      KC_GRV,  _______, _______, _______, _______,  _______,                                       _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______,  _______, KC_NUBS,                   S(KC_NUBS),_______, _______, KC_UP,   _______, _______, _______,
      KC_CAPS, KC_PGDN, KC_PGUP, KC_HOME, KC_END,   _______, _______,                   _______,   _______, KC_LEFT, KC_DOWN, KC_RIGHT,_______, _______,
      _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,   _______, KC_F10,  KC_F11,  KC_F5,   _______, _______,
      _______, _______, _______, _______, KC_ADJUST,     _______,     _______, _______,       _______,      _______, _______, _______, _______, _______
      ),

/* LOWER
 * .-----------------------------------------.                                .------------------------------------------.
 * |   ^  |  F1  |  F2  |  F3  |  F4  |  F5  |                                |  F6  |  F7  |  F8  |  F9  | F10  |  F11  |
 * |------+------+------+------+------+------|______                    ______|------+------+------+------+------+-------|
 * |   -  |   /  |   7  |   8  |   9  |   -  |   [  |                  |   ]  |   /  |   7  |   8  |   9  |   -  |  F12  |
 * |------+------+------+------+------+------|______|                  |______|------+------+------+------+------+-------|
 * | Caps |   *  |   4  |   5  |   6  |   +  |  F15 |                  | F16  |   *  |   4  |   5  |   6  |   +  |  F13  |
 * |------+------+------+------+------+------|______|/-----\    /-----\|______|------+------+------+------+------+-------|
 * |   -  | UNDO |   1  |   2  |   3  |   .  |   -  (   -   )  (   -   )   -  | Num  |   1  |   2  |   3  |   .  |  F14  |
 * |------+------+------+------+------+------|______|\-----/|  |\-----/|______|------+------+------+------+------|-------|
 * |   -  |   -  |   0  |   ,  |   -  |      -      |   -  |   |   -   |     -       |   -  |   0  |   ,  | Enter|   =   |
 * `--------------------------------------------------------'  '---------------------------------------------------------´
 */

	[_LOWER] = LAYOUT(
      KC_GRV,  KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,                                           KC_F7,    KC_F8, KC_F9,   KC_F10,  KC_F11,
      _______, KC_P7,   KC_P7,  KC_P8,  KC_P9,  KC_PMNS, ALGR(KC_8),                ALGR(KC_9), KC_PSLS, KC_P7,    KC_P8, KC_P9,   KC_PMNS, KC_F12, 
      KC_CAPS, KC_P4,   KC_P4,  KC_P5,  KC_P6,  KC_PPLS, KC_F15,                    KC_F16,     KC_PAST, KC_P4,    KC_P5, KC_P6,   KC_PPLS, KC_F13, 
      _______, KC_UNDO, KC_P1,  KC_P2,  KC_P3,  KC_COMM, _______, _______,  _______,_______,    KC_NUM,  KC_P1,    KC_P2, KC_P3,   KC_DOT,  KC_F14, 
      _______, _______, KC_P0,  KC_PDOT,_______,     _______,     _______,  _______,       _______,      KC_ADJUST,KC_P0, KC_PDOT, KC_PENT, KC_PEQL
      ),

/* ADJUST
 * .-----------------------------------------.                                .------------------------------------------.
 * |   ^  |  F1  |  F2  |  F3  |  F4  |  F5  |                                |  F6  |  F7  |  F8  |  F9  | F10  |  F11  |
 * |------+------+------+------+------+------|______                    ______|------+------+------+------+------+-------|
 * |   -  |   -  |   -  |   -  |NK_ON |   -  |   -  |                  |   -  |   -  |EE_CLR|   -  |   -  |   -  |  F12  |
 * |------+------+------+------+------+------|______|                  |______|------+------+------+------+------+-------|
 * |   -  |   -  |   -  |   -  |NK_OFF|   -  |   -  |                  |   -  |   -  |RG_TOG|   -  |   -  |   -  |   -   |
 * |------+------+------+------+------+------|______|/-----\    /-----\|______|------+------+------+------+------+-------|
 * |   -  |   -  |   -  |   -  |   -  |   -  |   -  (   -   )  (   -   )   -  |   -  |RG_MOD|RG_SPI|RG_HUI|RG_SAI|RGB_VAI|
 * |------+------+------+------+------+------|______|\-----/|  |\-----/|______|------+------+------+------+------|-------|
 * |   -  |   -  |   -  |   -  |   -  |      -      |   -   |  |   -   |      -      |R_RMOD|RG_SPD|RG_HUD|RG_SAD|RGB_VAD|
 * `--------------------------------------------------------'  '---------------------------------------------------------´
 */

	[_ADJUST] = LAYOUT(
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                                       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
      _______, _______, _______, _______, NK_ON,   _______, _______,                   _______, _______, EE_CLR,  _______, _______, _______, KC_F12,
      _______, _______, _______, _______, NK_OFF,  _______, _______,                   _______, _______, RGB_TOG, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RGB_MOD, RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI,
      _______, _______, _______, _______, _______,      _______,     _______, _______,     _______,      RGB_RMOD,RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD
      )

};
#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _COLEMAK:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _SHIFT:
            oled_write_P(PSTR("Shift\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_90;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

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

#ifdef ENCODER_ENABLE
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_QWERTY] = { ENCODER_CCW_CW(LSA(KC_TAB), A(KC_TAB)), ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_LOWER] =  { ENCODER_CCW_CW(C(KC_LEFT), C(KC_RGHT)), ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN) },
    [_RAISE] =  { ENCODER_CCW_CW(C(KC_Z), C(KC_Y)),       ENCODER_CCW_CW(S(KC_F3), KC_F3) },
    [_ADJUST] = { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),       ENCODER_CCW_CW(RGB_SPD, RGB_SPI) },
};
#else
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
              rgblight_step();
        } else {
           rgblight_step_reverse();
        }
    }
    return false;
}

#endif
#endif
