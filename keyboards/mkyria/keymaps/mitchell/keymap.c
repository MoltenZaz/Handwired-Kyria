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
//#include MKYRIA_H
#include QMK_KEYBOARD_H
#include "keymap_steno.h"
#include "quantum.h"
#include "raw_hid.h"

enum layers {
    _MTGAP = 0,
	// _HRMOD,
    _QWERTY,
	_QWERTY2,
    _GAMING,
    _MIR,
    // _HRMIR,
    _GMIR,
    _QMIR,
    _RARW,
	_NPAD2,
	_NPAD,
    _NAV,
    _NAV2,
    _SYM,
    _FKEY,
    _PLOVER,
    _SET,
};

// void matrix_init_user() {
  // steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
// }

enum custom_keycodes {
    KC_FNX = SAFE_RANGE,
	KC_MFX,
	TGNPAD,
};

// Aliases for readability
#define MTGAP    TO(_MTGAP)
#define GAMING   TO(_GAMING)
#define TGGAME   TG(_GAMING)
#define QWERTY   TO(_QWERTY)

#define LM_LCTL  LM(_QWERTY, MOD_LCTL)
#define LM_LGUI  LM(_QWERTY, MOD_LGUI)
#define LM_LALT  LM(_QWERTY, MOD_LALT)
#define LM_RALT  LM(_QWERTY2, MOD_LALT)
#define LM_RCTL  LM(_QWERTY2, MOD_LCTL)

#define LMM_LCTL  LM(_QMIR, MOD_LCTL)
#define LMM_LGUI  LM(_QMIR, MOD_LGUI)
#define LMM_LALT  LM(_QMIR, MOD_LALT)
#define LMM_RALT  LM(_QMIR, MOD_LALT)
#define LMM_RCTL  LM(_QMIR, MOD_LCTL)

#define MIR   	 LT(_MIR, KC_BSPC)
// #define HRMIR    MO(_HRMIR)
#define GMIR   	 MO(_GMIR)
#define QMIR   	 MO(_QMIR)

// #define HRMOD  	 TG(_HRMOD)
#define NPAD2    MO(_NPAD2)
#define TNPAD2   TG(_NPAD2)
#define NPAD   	 MO(_NPAD)
// #define TGNPAD   TG(_NPAD)
#define LTNPAD   LT(_NAV, KC_NO)
#define RARW   	 TG(_RARW)

#define NAVR     MO(_NAVR)
#define NAV      MO(_NAV)
#define NAV2     MO(_NAV2)
#define SYM      MO(_SYM)
#define FKEY     MO(_FKEY)
#define PLOVER   TG(_PLOVER)
#define SET      MO(_SET)

// Left-hand home row mods
#define HOME_Q 		LGUI_T(KC_Q)
#define HOME_Z 		LALT_T(KC_Z)
#define HOME_QUOTE  LSFT_T(KC_QUOTE)
#define HOME_COMMA  LCTL_T(KC_COMMA)

// Right-hand home row mods
// #define HOME_F RCTL_T(KC_F)
// #define HOME_G RSFT_T(KC_G)
// #define HOME_V RALT_T(KC_V)
// #define HOME_X RGUI_T(KC_X)

#define HM_ESC LSFT_T(KC_ESC)
#define HM_ENT RSFT_T(KC_ENT)

// #define BK_SFT   LSFT_T(KC_BSPC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_MTGAP] = LAYOUT(
     KC_TAB , KC_Y ,  KC_P  ,  KC_O  ,   KC_U , KC_J   ,                                     KC_K  ,  KC_D  ,  KC_L  ,  KC_C  ,  KC_W  , KC_DEL ,
     HM_ESC , KC_I ,  KC_N  ,  KC_E  ,   KC_A , KC_DOT ,                                     KC_M  ,  KC_H  ,  KC_T  ,  KC_S  ,  KC_R  , HM_ENT ,
     LM_LCTL, KC_Q ,  KC_Z  , KC_QUOT, KC_COMM, KC_SCLN, KC_ESC , NPAD2 , KC_F13 , KC_ENT ,  KC_B  ,  KC_F  ,  KC_G  ,  KC_V  ,  KC_X  , LM_RCTL,
                             LM_LGUI , LM_LALT, KC_FNX , KC_SPC ,   MIR ,   SYM  , KC_BSPC,   NAV  , LM_RALT, KC_APP
    ),

	// [_HRMOD] = LAYOUT(
     // _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, KC_ENT ,
     // KC_LSFT, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, KC_RSFT,
     // _______,   KC_Q ,  KC_Z  , KC_QUOT, KC_COMM, _______, KC_ESC , _______, _______, KC_DEL , _______,   KC_F ,   KC_G ,   KC_V ,   KC_X , _______,
                                // _______, _______, _______, _______,   MIR  , _______, _______, _______, _______, _______
    // ),

    [_QWERTY] = LAYOUT(
     _______,   KC_Q ,   KC_W ,  KC_E  ,   KC_R ,   KC_T ,                                       KC_Y ,   KC_U ,   KC_I ,   KC_O ,   KC_P , _______,
     HM_ESC ,   KC_A ,   KC_S ,  KC_D  ,   KC_F ,   KC_G ,                                       KC_H ,   KC_J ,   KC_K ,   KC_L , KC_SCLN, _______,
     KC_LCTL,   KC_Z ,   KC_X ,  KC_C  ,   KC_V ,   KC_B , KC_ESC , _______, _______, _______,   KC_N ,   KC_M , KC_COMM, KC_DOT , KC_SLSH, KC_RCTL,
                                KC_LGUI, KC_LALT, KC_LSFT, _______, QMIR   , _______, _______, _______, KC_RALT, _______
    ),
	
	[_QWERTY2] = LAYOUT(
     _______,   KC_Q ,   KC_W ,   KC_E ,   KC_R ,   KC_T ,                                       KC_Y ,   KC_U ,   KC_I ,   KC_O ,   KC_P , _______,
     HM_ESC ,   KC_A ,   KC_S ,   KC_D ,   KC_F ,   KC_G ,                                       KC_H ,   KC_J ,   KC_K ,   KC_L , KC_SCLN, _______,
     KC_LCTL,   KC_Z ,   KC_X ,   KC_C ,   KC_V ,   KC_B , KC_ESC , _______, _______, _______,   KC_N ,   KC_M , KC_COMM, KC_DOT , KC_SLSH, KC_RCTL,
                                KC_LGUI, LM_LALT, _______, _______, QMIR   , _______, _______, KC_RSFT, LM_RALT, _______
    ),
	
    [_GAMING] = LAYOUT(
     KC_TAB ,   KC_T ,   KC_Q ,   KC_W ,   KC_E ,   KC_R ,                                       KC_Y ,   KC_U ,   KC_I ,   KC_O ,   KC_P , _______,
     KC_LCTL, KC_LSFT,   KC_A ,   KC_S ,   KC_D ,   KC_F ,                                       KC_H ,   KC_J ,   KC_K ,   KC_L , KC_SCLN, _______,
       KC_G ,   KC_B ,   KC_Z ,   KC_X ,   KC_C ,   KC_V ,  KC_ESC , NPAD2 , _______, _______,   KC_N ,   KC_M , KC_COMM, KC_DOT , KC_SLSH, KC_RCTL,
                                  KC_APP, KC_LALT, _______, KC_SPC , GMIR  , _______, _______, _______, LM_RALT, _______
    ),
	
    [_MIR] = LAYOUT(
      KC_DEL ,  KC_W  ,  KC_C  ,  KC_L  ,  KC_D  ,  KC_K  ,                                      KC_NUM ,  KC_P7 ,  KC_P8 ,  KC_P9 , KC_PPLS, _______,
      HM_ENT ,  KC_R  ,  KC_S  ,  KC_T  ,  KC_H  ,  KC_M  ,                                      KC_PAST,  KC_P4 ,  KC_P5 ,  KC_P6 ,  KC_P0 , KC_PENT,
     LMM_RCTL,  KC_X  ,  KC_V  ,  KC_G  ,  KC_F  ,  KC_B  ,  _______,   FKEY , _______,   RARW , KC_PSLS,  KC_P1 ,  KC_P2 ,  KC_P3 , KC_PMNS, _______,
                                 KC_APP , LMM_RALT, KC_BSPC, _______, _______,  FKEY  , _______, KC_PDOT, _______, _______
    ),
	
	// [_HRMIR] = LAYOUT(
      // KC_DEL ,  KC_W  ,  KC_C  ,  KC_L  ,  KC_D  ,  KC_K  ,                                      KC_NUM ,  KC_P7 ,  KC_P8 ,  KC_P9 , KC_PPLS, _______,
      // KC_ENT ,  KC_R  ,  KC_S  ,  KC_T  ,  KC_H  ,  KC_M  ,                                      KC_PAST,  KC_P4 ,  KC_P5 ,  KC_P6 ,  KC_P0 , KC_PENT,
      // LMM_RCTL, HOME_X,  HOME_V,  HOME_G,  HOME_F,  KC_B  ,  _______,   FKEY , _______,   RARW , KC_PSLS,  KC_P1 ,  KC_P2 ,  KC_P3 , KC_PMNS, _______,
                                 // KC_APP , LMM_RALT, KC_BSPC, _______, _______,  FKEY  , _______, KC_PDOT, _______, _______
    // ),

    [_GMIR] = LAYOUT(
      KC_DEL ,  KC_P   ,  KC_O  , KC_I   ,  KC_U  ,  KC_Y  ,                                     KC_NUM ,  KC_P7 ,  KC_P8 ,  KC_P9 , KC_PPLS, _______,
      KC_ENT ,  KC_SCLN,  KC_L  , KC_K   ,  KC_J  ,  KC_H  ,                                     KC_PAST,  KC_P4 ,  KC_P5 ,  KC_P6 ,  KC_P0 , KC_PENT,
      KC_RCTL,  KC_COMM,  KC_DOT, KC_COMM,  KC_M  ,  KC_N  , _______,   FKEY , _______,   RARW , KC_PSLS,  KC_P1 ,  KC_P2 ,  KC_P3 , KC_PMNS, _______,
                                  KC_RGUI, KC_RALT, KC_BSPC, _______, _______,  FKEY  , _______, KC_PDOT, _______, _______
    ),
	
    [_QMIR] = LAYOUT(
      KC_DEL ,  KC_P   ,  KC_O  , KC_I   ,  KC_U  ,  KC_Y  ,                                     KC_NUM ,  KC_P7 ,  KC_P8 ,  KC_P9 , KC_PPLS, _______,
      KC_ENT ,  KC_SCLN,  KC_L  , KC_K   ,  KC_J  ,  KC_H  ,                                     KC_PAST,  KC_P4 ,  KC_P5 ,  KC_P6 ,  KC_P0 , KC_PENT,
      KC_RCTL,  KC_COMM,  KC_DOT, KC_COMM,  KC_M  ,  KC_N  , _______,   FKEY , _______,   RARW , KC_PSLS,  KC_P1 ,  KC_P2 ,  KC_P3 , KC_PMNS, _______,
                                  KC_APP , KC_RALT, KC_BSPC, _______, _______,  FKEY  , _______, KC_PDOT, _______, _______
    ),
	
	[_RARW] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______,  KC_UP ,  _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                     _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
	
	[_NPAD2] = LAYOUT(
      KC_DEL , KC_RBRC, KC_AMPR, KC_ASTR, KC_QUES, KC_BSPC,                                     _______, _______, _______, _______, _______, _______,
      HM_ENT , KC_PDOT, KC_DLR , KC_PERC, KC_CIRC, KC_RCBR,                                     _______, _______, _______, _______, _______, _______,
      _______, KC_LBRC, KC_EXLM,  KC_AT , KC_HASH, KC_LCBR,  MTGAP , _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, KC_BSPC, _______, XXXXXXX, _______, _______, _______, _______, _______
    ),
	
	[_NPAD] = LAYOUT(
      KC_BSPC, KC_PPLS,  KC_7  ,  KC_8  ,  KC_9  , KC_PDOT,                                     _______, _______, _______, _______, _______, _______,
      HM_ENT ,  KC_0  ,  KC_4  ,  KC_5  ,  KC_6  , KC_ASTR,                                     _______, _______, _______, _______, _______, _______,
      _______, KC_MINS,  KC_1  ,  KC_2  ,  KC_3  , KC_SLSH, TNPAD2 ,  NPAD2 , _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, TGNPAD , _______, KC_MFX , _______, _______, _______, _______, _______
    ),
	
	[_NAV] = LAYOUT(
      KC_BTN3, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R , KC_BTN1,                                     KC_BTN1, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R , KC_BTN3,
      HM_ESC , KC_LEFT, KC_DOWN,  KC_UP , KC_RIGHT, KC_VOLU,                                     KC_VOLU, KC_LEFT, KC_UP  , KC_DOWN, KC_RIGHT, HM_ENT ,
      KC_LCTL,   NAV2 , KC_MPRV, KC_MPLY, KC_MNXT , KC_VOLD, GAMING , KC_SLEP, _______, _______, KC_VOLD, KC_MPRV, KC_MPLY, KC_MNXT,   NAV2  , KC_RCTL,
                                 _______, _______ , KC_BSPC, _______, TGGAME , _______, _______, _______, _______, _______
    ),

	[_NAV2] = LAYOUT(
      _______,    _______, C(G(KC_7)), C(G(KC_8)), C(G(KC_9)), _______,                                     _______, C(G(KC_7)), C(G(KC_8)), C(G(KC_9)),    _______, _______,
      _______, C(G(KC_0)), C(G(KC_4)), C(G(KC_5)), C(G(KC_6)), _______,                                     _______, C(G(KC_4)), C(G(KC_5)), C(G(KC_6)), C(G(KC_0)), _______,
      _______,    _______, C(G(KC_1)), C(G(KC_2)), C(G(KC_3)), _______, QWERTY , PLOVER , _______, _______, _______, C(G(KC_1)), C(G(KC_2)), C(G(KC_3)),    _______, _______,
                                       _______,    _______,    _______, _______, _______, _______, _______, _______, _______,    _______
    ),

    [_SYM] = LAYOUT(
      KC_GRV , KC_EXLM,  KC_AT , KC_HASH, KC_DLR , KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_EQL , KC_TILD,
      SC_LSPO,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,                                      KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  , SC_RSPC,
      _______, KC_LPRN, KC_LBRC, KC_QUES, KC_SLSH, KC_LCBR, _______, _______,   FKEY , KC_SCRL, KC_RCBR, KC_BSLS, KC_PIPE, KC_RBRC, KC_RPRN, _______,
                                 _______, _______, _______, _______,   FKEY , _______, _______, _______, _______, _______
    ),
	
    [_FKEY] = LAYOUT(
      KC_DEL , KC_F10 ,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F13 ,                                     KC_PSCR, KC_F7 ,  KC_F8 ,  KC_F9 ,  KC_F10 , KC_DEL ,
      KC_LSFT, KC_F11 ,  KC_F4 ,  KC_F5 ,  KC_F6 , KC_HOME,                                     KC_PGUP, KC_F4 ,  KC_F5 ,  KC_F6 ,  KC_F11 , KC_RSFT,
      KC_LSFT, KC_F12 ,  KC_F1 ,  KC_F2 ,  KC_F3 , KC_END , KC_CAPS, _______, _______, PLOVER , KC_PGDN, KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F12 , KC_RSFT,
                                 KC_LCTL, KC_LGUI, KC_LALT, _______, XXXXXXX, _______, _______, KC_RALT, KC_RGUI, KC_RCTL
    ),
	
    [_PLOVER] = LAYOUT(
	  STN_N1 , STN_N2 , STN_N3 , STN_N4 , STN_N5 , STN_N6 ,  								    STN_N7 , STN_N8 , STN_N9 , STN_NA , STN_NB , STN_NC ,
	  XXXXXXX, STN_S1 , STN_TL , STN_PL , STN_HL , STN_ST1,                                     STN_ST3, STN_FR , STN_PR , STN_LR , STN_TR , STN_DR ,
	  XXXXXXX, STN_S2 , STN_KL , STN_WL , STN_RL , STN_ST2,  MTGAP ,  SET   ,    SET , XXXXXXX, STN_ST4, STN_RR , STN_BR , STN_GR , STN_SR , STN_ZR ,
								 XXXXXXX, XXXXXXX, XXXXXXX,  STN_A , STN_O  ,  STN_E , STN_U  , XXXXXXX, XXXXXXX, XXXXXXX
    ),
	
    [_SET] = LAYOUT(
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX,  DT_UP ,  NK_ON ,                                      NK_ON ,  DT_UP , XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DT_DOWN,  NK_OFF,                                      NK_OFF, DT_DOWN, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DT_PRNT, XXXXXXX,  MTGAP , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DT_PRNT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    )
// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

void raw_hid_receive(uint8_t *data, uint8_t length) {
    uint8_t *command_id = &(data[0]);
    switch (*command_id) {
        case 0:
          layer_on(_GAMING);
          break;
        case 1:
          layer_off(_GAMING);
          break;
		// case 2:
          // layer_on(_NPAD);
          // break;
		// case 3:
          // layer_off(_NPAD);
          // break;
		case 4:
          layer_on(_RARW);
          break;
		case 5:
          layer_off(_RARW);
          break;
		// case 6:
		  // layer_on(_NPMOD);
          // break;
		// case 7:
          // layer_off(_NPMOD);
          // break;
	}
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HM_ESC:
            // Immediately select the hold action when another key is pressed.
            return true;
		case HM_ENT:
            // Immediately select the hold action when another key is pressed.
            return true;
		case MIR:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // switch (keycode) {
    // case LT(_NAV, KC_NO):
      // if (record->tap.count && record->event.pressed) {
        // layer_invert(_NPAD);
        // return false;
      // }
  // }
  // return true;
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    static uint16_t fnx_layer_timer;
	static uint8_t x; 
	if(record->event.pressed){
		x = 1;
	}
    switch (keycode){
        case KC_FNX:                                    
            if(record->event.pressed){
                fnx_layer_timer = timer_read();
                layer_on(_NAV);
				x = 0;
            } else {
                layer_off(_NAV);
                if (timer_elapsed(fnx_layer_timer) < TAPPING_TERM) {  
                    if (x == 0) {
						layer_invert(_NPAD);
					}
                }
            }
        return false;
		case KC_MFX:                                    
            if(record->event.pressed){ 
                layer_off(_NPAD);
				if(IS_LAYER_ON(_GAMING)){
					layer_on(_GMIR);
				}
				else{
					layer_on(_MIR);
				}
            } else {
                if(IS_LAYER_ON(_GAMING)){
					layer_off(_GMIR);
				}
				else{
					layer_off(_MIR);
				}
            }
        return false;
		case TGNPAD:                                    
            if(record->event.pressed){ 
                layer_off(_NPAD);
                layer_on(_NAV);
            } else {
                layer_off(_NAV);
            }
        return false;
    }
    return true;
}
const key_override_t numpad0_override = ko_make_basic(MOD_MASK_SHIFT, KC_P0, KC_LCBR);
const key_override_t numpad1_override = ko_make_basic(MOD_MASK_SHIFT, KC_P1, KC_EXLM);
const key_override_t numpad2_override = ko_make_basic(MOD_MASK_SHIFT, KC_P2, KC_AT);
const key_override_t numpad3_override = ko_make_basic(MOD_MASK_SHIFT, KC_P3, KC_HASH);
const key_override_t numpad4_override = ko_make_basic(MOD_MASK_SHIFT, KC_P4, KC_DLR);
const key_override_t numpad5_override = ko_make_basic(MOD_MASK_SHIFT, KC_P5, KC_PERC);
const key_override_t numpad6_override = ko_make_basic(MOD_MASK_SHIFT, KC_P6, KC_CIRC);
const key_override_t numpad7_override = ko_make_basic(MOD_MASK_SHIFT, KC_P7, KC_AMPR);
const key_override_t numpad8_override = ko_make_basic(MOD_MASK_SHIFT, KC_P8, KC_ASTR);
const key_override_t numpad9_override = ko_make_basic(MOD_MASK_SHIFT, KC_P9, KC_RCBR);
const key_override_t numpad_min_override = ko_make_basic(MOD_MASK_SHIFT, KC_PMNS, KC_UNDS);
const key_override_t numpad_plus_override = ko_make_basic(MOD_MASK_SHIFT, KC_PPLS, KC_EQL);

const key_override_t left_square_bracket = ko_make_basic(MOD_MASK_SHIFT, SC_LAPO, KC_LBRC);
const key_override_t right_square_bracket = ko_make_basic(MOD_MASK_SHIFT, SC_RAPC, KC_RBRC);

const key_override_t m3_m2 = ko_make_basic(MOD_MASK_SHIFT, KC_BTN3, KC_BTN2);

// const key_override_t delete_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_BSPC, KC_DEL, 1<<_MIR | 1<<_DMIR | 1<<_GMIR | 1<<_SYML | 1<<_SLMIR);

// const key_override_t win_num1 = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT, G(KC_1));
// const key_override_t win_num2 = ko_make_basic(MOD_MASK_SHIFT, KC_DOWN, G(KC_2));
// const key_override_t win_num3 = ko_make_basic(MOD_MASK_SHIFT, KC_UP, G(KC_3));
// const key_override_t win_num4 = ko_make_basic(MOD_MASK_SHIFT, KC_RIGHT, G(KC_4));
// const key_override_t win_num5 = ko_make_basic(MOD_MASK_SHIFT, KC_VOLU, G(KC_5));
// const key_override_t win_num6 = ko_make_basic(MOD_MASK_SHIFT, KC_BTN1, G(KC_6));
// const key_override_t win_num7 = ko_make_basic(MOD_MASK_SHIFT, KC_MS_R, G(KC_7));
// const key_override_t win_num8 = ko_make_basic(MOD_MASK_SHIFT, KC_MS_U, G(KC_8));
// const key_override_t win_num9 = ko_make_basic(MOD_MASK_SHIFT, KC_MS_D, G(KC_9));
// const key_override_t win_num0 = ko_make_basic(MOD_MASK_SHIFT, KC_MS_L, G(KC_0));

// const key_override_t sleft = ko_make_basic(MOD_MASK_ALT, KC_LEFT, S(KC_LEFT));
// const key_override_t sdown = ko_make_basic(MOD_MASK_ALT, KC_DOWN, S(KC_DOWN));
// const key_override_t sup = ko_make_basic(MOD_MASK_ALT, KC_UP, S(KC_UP));
// const key_override_t sright = ko_make_basic(MOD_MASK_ALT, KC_RIGHT, S(KC_RIGHT));

const key_override_t mprv = ko_make_basic(MOD_MASK_CTRL, KC_MPRV, KC_MAIL);
const key_override_t mply = ko_make_basic(MOD_MASK_CTRL, KC_MPLY, KC_MSEL);
const key_override_t mnxt = ko_make_basic(MOD_MASK_CTRL, KC_MNXT, KC_MYCM);

const key_override_t smprv = ko_make_basic(MOD_MASK_SHIFT, KC_MPRV, KC_MAIL);
const key_override_t smply = ko_make_basic(MOD_MASK_SHIFT, KC_MPLY, KC_MSEL);
const key_override_t smnxt = ko_make_basic(MOD_MASK_SHIFT, KC_MNXT, KC_MYCM);

const key_override_t vol_pgup = ko_make_basic(MOD_MASK_CTRL, KC_VOLU, KC_PGUP);
const key_override_t vol_pgdn = ko_make_basic(MOD_MASK_CTRL, KC_VOLD, KC_PGDN);

const key_override_t svol_pgup = ko_make_basic(MOD_MASK_SHIFT, KC_VOLU, KC_PGUP);
const key_override_t svol_pgdn = ko_make_basic(MOD_MASK_SHIFT, KC_VOLD, KC_PGDN);

const key_override_t msu_whu = ko_make_basic(MOD_MASK_SHIFT, KC_MS_U, KC_WH_U);
const key_override_t msd_whd = ko_make_basic(MOD_MASK_SHIFT, KC_MS_D, KC_WH_D);
const key_override_t msl_bck = ko_make_basic(MOD_MASK_SHIFT, KC_MS_L, KC_BTN4);
const key_override_t msr_fwd = ko_make_basic(MOD_MASK_SHIFT, KC_MS_R, KC_BTN5);
const key_override_t amsu_whu = ko_make_basic(MOD_MASK_ALT, KC_MS_U, KC_WH_U);
const key_override_t amsd_whd = ko_make_basic(MOD_MASK_ALT, KC_MS_D, KC_WH_D);
const key_override_t amsl_bck = ko_make_basic(MOD_MASK_ALT, KC_MS_L, KC_BTN4);
const key_override_t amsr_fwd = ko_make_basic(MOD_MASK_ALT, KC_MS_R, KC_BTN5);

const key_override_t m1_mute = ko_make_basic(MOD_MASK_SHIFT, KC_BTN1, KC_MUTE);

// const key_override_t pgdn_end = ko_make_with_layers(MOD_MASK_SHIFT, KC_PGDN, KC_END, 1<<_SYML);
// const key_override_t pgup_home = ko_make_with_layers(MOD_MASK_SHIFT, KC_PGUP, KC_HOME, 1<<_SYML);
// const key_override_t ques_pipe = ko_make_with_layers(MOD_MASK_SHIFT, KC_QUES, KC_PIPE, 1<<_SYML);
const key_override_t slsh_bsls = ko_make_with_layers(MOD_MASK_SHIFT, KC_SLSH, KC_BSLS, 1<<_NPAD);
const key_override_t tild_grv = ko_make_with_layers(MOD_MASK_SHIFT, KC_TILD, KC_GRV, 1<<_NPAD);
const key_override_t zero_plus = ko_make_with_layers(MOD_MASK_SHIFT, KC_0, KC_PDOT, 1<<_NPAD);
const key_override_t nine_ques = ko_make_with_layers(MOD_MASK_SHIFT, KC_9, KC_QUES, 1<<_NPAD);
const key_override_t astr_pipe = ko_make_with_layers(MOD_MASK_SHIFT, KC_ASTR, KC_PIPE, 1<<_NPAD);

const key_override_t home_up = ko_make_with_layers(MOD_MASK_SHIFT, KC_HOME, KC_PGUP, 1<<_FKEY);
const key_override_t end_down = ko_make_with_layers(MOD_MASK_SHIFT, KC_END, KC_PGDN, 1<<_FKEY);
const key_override_t up_home = ko_make_with_layers(MOD_MASK_SHIFT, KC_PGUP, KC_HOME, 1<<_FKEY);
const key_override_t down_end = ko_make_with_layers(MOD_MASK_SHIFT, KC_PGDN, KC_END, 1<<_FKEY);

// const key_override_t capsl = ko_make_basic(MOD_MASK_SHIFT, SC_LSPO, KC_CAPS);
// const key_override_t capsr = ko_make_basic(MOD_MASK_SHIFT, SC_RSPC, KC_CAPS);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &numpad0_override,
    &numpad1_override,
    &numpad2_override,
    &numpad3_override,
    &numpad4_override,
    &numpad5_override,
    &numpad6_override,
    &numpad7_override,
    &numpad8_override,
    &numpad9_override,
    &numpad_min_override,
    &numpad_plus_override,
	&left_square_bracket,
	&right_square_bracket,
	&m3_m2,
	// &delete_key_override,
	// &win_num1,
	// &win_num2,
	// &win_num3,
	// &win_num4,
	// &win_num5,
	// &win_num6,
	// &win_num7,
	// &win_num8,
	// &win_num9,
	// &win_num0,
	// &sleft,
	// &sdown,
	// &sup,
	// &sright,
	&mprv,
	&mply,
	&mnxt,
	&smprv,
	&smply,
	&smnxt,
	&vol_pgup,
	&vol_pgdn,
	&svol_pgup,
	&svol_pgdn,
	&msu_whu,
	&msd_whd,
	&msl_bck,
	&msr_fwd,
	&amsu_whu,
	&amsd_whd,
	&amsl_bck,
	&amsr_fwd,
	&m1_mute,
	// &pgdn_end,
	// &pgup_home,
	// &ques_pipe,
	&slsh_bsls,
	&tild_grv,
	&zero_plus,
	&nine_ques,
	&astr_pipe,
	&home_up,
	&end_down,
	&up_home,
	&down_end,
	// &capsl,
	// &capsr,
    NULL
};