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
#include "quantum.h"
// #include "raw_hid.h"

enum layers {
    _MTGAP = 0,
    _QWERTY,
	_QWERTY2,
    _MIR,
    _QMIR,
	_ARACTV,
	_ARROWL,
    _NAV,
    _NAV2,
	_NAV3,
    _SYM,
    _FKEY,
    _SET,
	_SET2,
};

// void matrix_init_user() {
  // steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
// }

enum custom_keycodes {
    // KC_FNX = SAFE_RANGE,
	// KC_MFX,
	// TGNPAD,
	// NPADG,
	// ESCPAD,
	squared = SAFE_RANGE,
	cubed,
	degree,
};

// Aliases for readability
#define MTGAP    TO(_MTGAP)
// #define GAMING   TO(_GAMING)
// #define TGGAME   TG(_GAMING)
#define QWERTY   TO(_QWERTY)

#define LM_LCTL  LM(_QWERTY, MOD_LCTL)
#define LM_LGUI  LM(_QWERTY, MOD_LGUI)
#define LM_LALT  LM(_QWERTY, MOD_LALT)
#define LM_RALT  LM(_QWERTY2, MOD_RALT)
#define LM_RCTL  LM(_QWERTY2, MOD_RCTL)
#define LM_RGUI  LM(_QWERTY, MOD_RGUI)

#define LMM_LCTL  LM(_QMIR, MOD_LCTL)
#define LMM_LGUI  LM(_QMIR, MOD_LGUI)
#define LMM_LALT  LM(_QMIR, MOD_LALT)
#define LMM_RALT  LM(_QMIR, MOD_RALT)
#define LMM_RCTL  LM(_QMIR, MOD_RCTL)
#define LMM_RGUI  LM(_QMIR, MOD_RGUI)

// #define LM_PCTL  LM(_PADUNDO, MOD_LCTL)
// #define LM_PGUI  LM(_PADUNDO, MOD_LGUI)
// #define LM_PALT  LM(_PADUNDO, MOD_LALT)

// #define MIR   	 LT(_MIR, KC_BSPC)
// #define MIR   	 OSL(_MIR)
#define MIR   	 TL_LOWR
// #define HRMIR    MO(_HRMIR)
// #define GMIR   	 MO(_GMIR)
#define QMIR   	 LT(_QMIR, KC_BSPC)

// #define HRMOD  	 TG(_HRMOD)
// #define NPAD2    MO(_NPAD2)
// #define TNPAD2   TG(_NPAD2)
// #define NPAD   	 MO(_NPAD)
// #define TGNPAD   TG(_NPAD)
// #define LTNPAD   LT(_NAV, KC_NO)
// #define RARW   	 TG(_RARW)

#define ARACTV   TG(_ARACTV)

// #define NAVR     MO(_NAVR)
#define NAV      MO(_NAV)
#define NAV2     MO(_NAV2)
#define NAV3     MO(_NAV3)
#define SYM      MO(_SYM)
// #define SYM      LT(_SYM, KC_NO)
#define FKEY     MO(_FKEY)
// #define PLOVER   TG(_PLOVER)
#define SET      MO(_SET)
#define SET2     MO(_SET2)

#define HM_ESC LSFT_T(KC_ESC)
#define HM_ENT RSFT_T(KC_ENT)

// #define BK_SFT   LSFT_T(KC_BSPC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_MTGAP] = LAYOUT(
     KC_TAB , KC_Y ,  KC_P  ,  KC_O  ,   KC_U , KC_J   ,                                     KC_K  ,  KC_D  ,  KC_L  ,  KC_C  ,  KC_W  , KC_DEL ,
     KC_LSFT, KC_I ,  KC_N  ,  KC_E  ,   KC_A , KC_DOT ,                                     KC_M  ,  KC_H  ,  KC_T  ,  KC_S  ,  KC_R  , KC_RSFT,
     LM_LCTL, KC_Q ,  KC_Z  , KC_QUOT, KC_COMM, KC_SCLN, KC_ESC ,  FKEY , KC_F13 , KC_ENT ,  KC_B  ,  KC_F  ,  KC_G  ,  KC_V  ,  KC_X  , LM_RCTL,
                              LM_LGUI, LM_LALT,   NAV  , KC_SPC ,  MIR ,   SYM  , KC_BSPC,  KC_ENT, LM_RALT, LM_RGUI
    ),

    [_QWERTY] = LAYOUT(
     _______,   KC_Q ,   KC_W ,  KC_E  ,   KC_R ,   KC_T ,                                       KC_Y ,   KC_U ,   KC_I ,   KC_O ,   KC_P , _______,
     HM_ENT ,   KC_A ,   KC_S ,  KC_D  ,   KC_F ,   KC_G ,                                       KC_H ,   KC_J ,   KC_K ,   KC_L , KC_SCLN, _______,
     KC_LCTL,   KC_Z ,   KC_X ,  KC_C  ,   KC_V ,   KC_B , KC_ESC , _______, _______, _______,   KC_N ,   KC_M , KC_COMM, KC_DOT , KC_SLSH, KC_RCTL,
                                KC_LGUI, KC_LALT, KC_LSFT, _______, QMIR   , _______, _______, _______, KC_RALT, _______
    ),
	
	[_QWERTY2] = LAYOUT(
     _______,   KC_Q ,   KC_W ,   KC_E ,   KC_R ,   KC_T ,                                       KC_Y ,   KC_U ,   KC_I ,   KC_O ,   KC_P , _______,
     HM_ENT ,   KC_A ,   KC_S ,   KC_D ,   KC_F ,   KC_G ,                                       KC_H ,   KC_J ,   KC_K ,   KC_L , KC_SCLN, _______,
     KC_LCTL,   KC_Z ,   KC_X ,   KC_C ,   KC_V ,   KC_B , KC_ESC , _______, _______, _______,   KC_N ,   KC_M , KC_COMM, KC_DOT , KC_SLSH, KC_RCTL,
                                KC_LGUI, LM_LALT, _______, _______, QMIR   , _______, _______, KC_RSFT, LM_RALT, _______
    ),
	
    [_MIR] = LAYOUT(
      KC_DEL ,  KC_W  ,  KC_C  ,  KC_L  ,  KC_D  ,  KC_K  ,                                      _______,   KC_7 ,   KC_8 ,   KC_9 , KC_PAST, _______,
      HM_ENT ,  KC_R  ,  KC_S  ,  KC_T  ,  KC_H  ,  KC_M  ,                                      KC_PPLS,   KC_4 ,   KC_5 ,   KC_6 ,   KC_0 , KC_ENT ,
     LMM_RCTL,  KC_X  ,  KC_V  ,  KC_G  ,  KC_F  ,  KC_B  ,  _______, _______, _______, _______, KC_PMNS,   KC_1 ,   KC_2 ,   KC_3 , KC_SLSH, _______,
                                LMM_RGUI, LMM_RALT, KC_BSPC, _______, _______, ARACTV , _______, KC_PDOT, _______, _______
    ),

	
    [_QMIR] = LAYOUT(
      KC_DEL ,  KC_P   ,  KC_O  , KC_I   ,  KC_U  ,  KC_Y  ,                                     KC_NUM ,  KC_P7 ,  KC_P8 ,  KC_P9 , KC_PAST, _______,
      KC_ENT ,  KC_SCLN,  KC_L  , KC_K   ,  KC_J  ,  KC_H  ,                                     KC_PPLS,  KC_P4 ,  KC_P5 ,  KC_P6 ,  KC_P0 , KC_ENT ,
      KC_RCTL,  KC_COMM,  KC_DOT, KC_COMM,  KC_M  ,  KC_N  , _______, _______, _______, _______, KC_PMNS,  KC_P1 ,  KC_P2 ,  KC_P3 , KC_PSLS, _______,
                                  KC_APP , KC_RALT, KC_BSPC, _______, _______,  FKEY  , _______, KC_PDOT, _______, _______
    ),

	[_ARACTV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
	
	[_ARROWL] = LAYOUT(
      _______, _______, _______, _______, _______ , _______,                                     _______, _______, _______, _______, _______, _______,
      _______, KC_LEFT, KC_DOWN,  KC_UP , KC_RIGHT, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______ , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______ , _______, _______, _______, _______, _______, _______, _______, _______
    ),
	
	// [_NPAD] = LAYOUT(
      // KC_TAB , KC_PAST,  KC_7  ,  KC_8  ,  KC_9  , KC_BSPC,                                     _______, _______, _______, _______, _______, _______,
      // HM_ENT ,  KC_0  ,  KC_4  ,  KC_5  ,  KC_6  , KC_PPLS,                                     _______, _______, _______, _______, _______, _______,
      // _______, KC_SLSH,  KC_1  ,  KC_2  ,  KC_3  , KC_SMNS, KC_CAPS,  _______, PLOVER , _______, _______, _______, _______, _______, _______, _______,
                                 // LM_LGUI, _______, _______, _______,   FKEY  , _______, _______, _______, _______, _______
    // ),
	
	
	[_NAV] = LAYOUT(
      NAV3   ,  KC_1  ,  KC_2  ,  KC_3  ,   KC_4  ,  KC_5  ,                                     _______, KC_AMPR, KC_ASTR, KC_LPRN, _______, _______,
      HM_ENT , KC_LEFT, KC_DOWN,  KC_UP , KC_RIGHT, KC_VOLU,                                     KC_GRV , KC_DLR , KC_PERC, KC_CIRC, KC_RPRN, _______,
      KC_LCTL,   NAV2 , KC_MPRV, KC_MPLY, KC_MNXT , KC_VOLD, _______, _______, _______, KC_SLEP, _______, KC_EXLM,  KC_AT , KC_HASH, _______, _______,
                                 _______, _______ , _______, _______, _______, _______, _______, _______, _______, _______
    ),

	[_NAV2] = LAYOUT(
      _______,    _______, C(G(KC_7)), C(G(KC_8)), C(G(KC_9)), _______,                                     _______, _______, _______, _______, _______, _______,
      _______, C(G(KC_0)), C(G(KC_4)), C(G(KC_5)), C(G(KC_6)), _______,                                     _______, _______, _______, _______, _______, _______,
      _______,    _______, C(G(KC_1)), C(G(KC_2)), C(G(KC_3)), _______, QWERTY , _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                       _______,    _______,    _______, _______, _______, _______, _______, _______, _______,    _______
    ),
	
	[_NAV3] = LAYOUT(
      _______,  KC_0  ,  KC_9  ,  KC_8  ,  KC_7  ,  KC_6  ,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, KC_BSPC,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, KC_TAB , _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    [_SYM] = LAYOUT(
      KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_LCBR, KC_RCBR,                                     _______, KC_F19 ,  KC_F20 ,  KC_F21 ,  KC_F22 , _______,
      _______, degree ,  KC_EQL, KC_MINS, KC_QUES,  KC_GRV,                                     KC_PGUP, KC_F16 ,  KC_F17 ,  KC_F18 ,  KC_F23 , _______,
      _______,  cubed , squared, KC_QUES, KC_SLSH, KC_LPRN, _______, _______,  FKEY  , _______, KC_PGDN, KC_F13 ,  KC_F14 ,  KC_F15 ,  KC_F24 , _______,
                                 _______, _______, _______, _______,   FKEY , _______, _______, _______, SC_RAPC, _______
    ),
	
    [_FKEY] = LAYOUT(
      _______, KC_F10 ,  KC_F7 ,  KC_F8 ,  KC_F9 , _______,                                     _______, KC_F19 ,  KC_F20 ,  KC_F21 ,  KC_F22 , _______,
      _______, KC_F11 ,  KC_F4 ,  KC_F5 ,  KC_F6 , KC_HOME,                                     KC_PGUP, KC_F16 ,  KC_F17 ,  KC_F18 ,  KC_F23 , _______,
      _______, KC_F12 ,  KC_F1 ,  KC_F2 ,  KC_F3 , KC_END ,  MTGAP , _______, _______, _______, KC_PGDN, KC_F13 ,  KC_F14 ,  KC_F15 ,  KC_F24 , _______,
                                 _______, _______, _______,   SET  , XXXXXXX, _______,   SET  , _______, _______, _______
    ),
	
	[_SET] = LAYOUT(
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  SET2  , XXXXXXX, XXXXXXX,  SET2  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
	
    [_SET2] = LAYOUT(
      QK_BOOT, XXXXXXX, XXXXXXX, QK_UNICODE_MODE_WINCOMPOSE,  DT_UP ,  NK_ON ,                                      NK_ON ,  DT_UP , QK_UNICODE_MODE_WINCOMPOSE, XXXXXXX, XXXXXXX, QK_BOOT,
      XXXXXXX, XXXXXXX, XXXXXXX, QK_UNICODE_MODE_LINUX     , DT_DOWN,  NK_OFF,                                      NK_OFF, DT_DOWN, QK_UNICODE_MODE_LINUX     , XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, QK_UNICODE_MODE_MACOS     , DT_PRNT, XXXXXXX,  MTGAP , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DT_PRNT, QK_UNICODE_MODE_MACOS     , XXXXXXX, XXXXXXX, XXXXXXX,
                                 XXXXXXX                   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
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

// void raw_hid_receive(uint8_t *data, uint8_t length) {
    // uint8_t *command_id = &(data[0]);
    // switch (*command_id) {
        // case 0:
          // layer_on(_GAMING);
		  // layer_off(_NPAD);
          // break;
        // case 1:
          // layer_off(_GAMING);
          // break;
		// // case 2:
          // // layer_on(_NPAD);
          // // break;
		// // case 3:
          // // layer_off(_NPAD);
          // // break;
		// case 4:
          // layer_on(_RARW);
          // break;
		// case 5:
          // layer_off(_RARW);
          // break;
		// // case 6:
		  // // layer_on(_NPMOD);
          // // break;
		// // case 7:
          // // layer_off(_NPMOD);
          // // break;
	// }
// }

// bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    // switch (keycode) {
        // case HM_ESC:
            // // Immediately select the hold action when another key is pressed.
            // return true;
		// case HM_ENT:
            // // Immediately select the hold action when another key is pressed.
            // return true;
		// case MIR:
            // // Immediately select the hold action when another key is pressed.
            // return true;
        // default:
            // // Do not select the hold action when another key is pressed.
            // return false;
    // }
// }

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
    // static uint16_t fnx_layer_timer;
	// static uint8_t x; 
	// if(record->event.pressed){
		// x = 1;
	// }
    switch (keycode){
        // case KC_FNX:                                    
            // if(record->event.pressed){
                // fnx_layer_timer = timer_read();
                // layer_on(_NAV);
				// x = 0;
            // } else {
                // layer_off(_NAV);
                // if (timer_elapsed(fnx_layer_timer) < TAPPING_TERM) {  
                    // if (x == 0) {
						// layer_invert(_NPAD);
					// }
                // }
            // }
        // return false;
		// case KC_MFX:                                    
            // if(record->event.pressed){
                // layer_off(_NPAD);
				// if(IS_LAYER_ON(_GAMING)){
					// layer_on(_GMIR);
				// }
				// else{
					// layer_on(_MIR);
				// }
            // } else {
                // if(IS_LAYER_ON(_GAMING)){
					// layer_off(_GMIR);
				// }
				// else{
					// layer_off(_MIR);
				// }
            // }
        // return false;
		// case TGNPAD:                                    
            // if(record->event.pressed){ 
                // layer_off(_NPAD);
                // layer_on(_NAV);
            // } else {
                // layer_off(_NAV);
            // }
        // return false;
		// case NPADG:                                    
            // if(record->event.pressed){ 
                // layer_on(_NPAD);
                // layer_on(_BLOCK);
            // } else {
                // layer_off(_NPAD);
                // layer_off(_BLOCK);
            // }
        // return false;
		// case ESCPAD:                                    
            // if(record->event.pressed){ 
                // register_code(KC_ESC);
                // layer_off(_NPAD);
            // } else {
                // unregister_code(KC_ESC);
            // }
        // return false;
		case squared:
			if(record->event.pressed){ 
				SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P7) SS_TAP(X_P8));
			}
			break;
		case cubed:
			if(record->event.pressed){ 
				SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P7) SS_TAP(X_P9));
			}
			break;
		case degree:
			if(record->event.pressed){ 
				SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P7) SS_TAP(X_P6));
			}
			break;
    }
    return true;
}
// const key_override_t numpad0_override = ko_make_basic(MOD_MASK_SHIFT, KC_P0, KC_LCBR);
// const key_override_t numpad1_override = ko_make_basic(MOD_MASK_SHIFT, KC_P1, KC_EXLM);
// const key_override_t numpad2_override = ko_make_basic(MOD_MASK_SHIFT, KC_P2, KC_AT);
// const key_override_t numpad3_override = ko_make_basic(MOD_MASK_SHIFT, KC_P3, KC_HASH);
// const key_override_t numpad4_override = ko_make_basic(MOD_MASK_SHIFT, KC_P4, KC_DLR);
// const key_override_t numpad5_override = ko_make_basic(MOD_MASK_SHIFT, KC_P5, KC_PERC);
// const key_override_t numpad6_override = ko_make_basic(MOD_MASK_SHIFT, KC_P6, KC_CIRC);
// const key_override_t numpad7_override = ko_make_basic(MOD_MASK_SHIFT, KC_P7, KC_AMPR);
// const key_override_t numpad8_override = ko_make_basic(MOD_MASK_SHIFT, KC_P8, KC_ASTR);
// const key_override_t numpad9_override = ko_make_basic(MOD_MASK_SHIFT, KC_P9, KC_RCBR);
// const key_override_t numpad_min_override = ko_make_basic(MOD_MASK_SHIFT, KC_PMNS, KC_UNDS);
// const key_override_t numpad_plus_override = ko_make_basic(MOD_MASK_SHIFT, KC_PPLS, KC_EQL);

// const key_override_t left_square_bracket = ko_make_basic(MOD_MASK_SHIFT, SC_LCPO, KC_LBRC);
// const key_override_t right_square_bracket = ko_make_basic(MOD_MASK_SHIFT, SC_RCPC, KC_RBRC);
// const key_override_t c_left_square_bracket = ko_make_basic(MOD_MASK_CTRL, SC_LCPO, KC_LBRC);
// const key_override_t c_right_square_bracket = ko_make_basic(MOD_MASK_CTRL, SC_RCPC, KC_RBRC);

// const key_override_t m3_m2 = ko_make_basic(MOD_MASK_SHIFT, KC_BTN3, KC_BTN2);



// const key_override_t mprv = ko_make_basic(MOD_MASK_CTRL, KC_MPRV, KC_MAIL);
// const key_override_t mply = ko_make_basic(MOD_MASK_CTRL, KC_MPLY, KC_MSEL);
// const key_override_t mnxt = ko_make_basic(MOD_MASK_CTRL, KC_MNXT, KC_MYCM);

// const key_override_t smprv = ko_make_basic(MOD_MASK_SHIFT, KC_MPRV, KC_MAIL);
// const key_override_t smply = ko_make_basic(MOD_MASK_SHIFT, KC_MPLY, KC_MSEL);
// const key_override_t smnxt = ko_make_basic(MOD_MASK_SHIFT, KC_MNXT, KC_MYCM);

// const key_override_t vol_pgup = ko_make_basic(MOD_MASK_CTRL, KC_VOLU, KC_PGUP);
// const key_override_t vol_pgdn = ko_make_basic(MOD_MASK_CTRL, KC_VOLD, KC_PGDN);

// const key_override_t svol_pgup = ko_make_basic(MOD_MASK_SHIFT, KC_VOLU, KC_PGUP);
// const key_override_t svol_pgdn = ko_make_basic(MOD_MASK_SHIFT, KC_VOLD, KC_PGDN);

// const key_override_t msu_whu = ko_make_basic(MOD_MASK_SHIFT, KC_MS_U, KC_WH_U);
// const key_override_t msd_whd = ko_make_basic(MOD_MASK_SHIFT, KC_MS_D, KC_WH_D);
// const key_override_t msl_bck = ko_make_basic(MOD_MASK_SHIFT, KC_MS_L, KC_BTN4);
// const key_override_t msr_fwd = ko_make_basic(MOD_MASK_SHIFT, KC_MS_R, KC_BTN5);
// const key_override_t amsu_whu = ko_make_basic(MOD_MASK_ALT, KC_MS_U, KC_WH_U);
// const key_override_t amsd_whd = ko_make_basic(MOD_MASK_ALT, KC_MS_D, KC_WH_D);
// const key_override_t amsl_bck = ko_make_basic(MOD_MASK_ALT, KC_MS_L, KC_BTN4);
// const key_override_t amsr_fwd = ko_make_basic(MOD_MASK_ALT, KC_MS_R, KC_BTN5);

// const key_override_t m1_mute = ko_make_basic(MOD_MASK_SHIFT, KC_BTN1, KC_MUTE);

// const key_override_t slsh_bsls = ko_make_with_layers(MOD_MASK_SHIFT, KC_SLSH, KC_BSLS, 1<<_NPAD);
// const key_override_t tild_grv = ko_make_with_layers(MOD_MASK_SHIFT, KC_TILD, KC_GRV, 1<<_NPAD);
// const key_override_t zero_plus = ko_make_with_layers(MOD_MASK_SHIFT, KC_0, KC_PDOT, 1<<_NPAD);
// const key_override_t nine_ques = ko_make_with_layers(MOD_MASK_SHIFT, KC_9, KC_QUES, 1<<_NPAD);
// const key_override_t astr_pipe = ko_make_with_layers(MOD_MASK_SHIFT, KC_ASTR, KC_PIPE, 1<<_NPAD);

// const key_override_t home_up = ko_make_with_layers(MOD_MASK_SHIFT, KC_HOME, KC_PGUP, 1<<_FKEY);
// const key_override_t end_down = ko_make_with_layers(MOD_MASK_SHIFT, KC_END, KC_PGDN, 1<<_FKEY);
// const key_override_t up_home = ko_make_with_layers(MOD_MASK_SHIFT, KC_PGUP, KC_HOME, 1<<_FKEY);
// const key_override_t down_end = ko_make_with_layers(MOD_MASK_SHIFT, KC_PGDN, KC_END, 1<<_FKEY);


// // This globally defines all key overrides to be used
// const key_override_t **key_overrides = (const key_override_t *[]){
    // &numpad0_override,
    // &numpad1_override,
    // &numpad2_override,
    // &numpad3_override,
    // &numpad4_override,
    // &numpad5_override,
    // &numpad6_override,
    // &numpad7_override,
    // &numpad8_override,
    // &numpad9_override,
    // &numpad_min_override,
    // &numpad_plus_override,
	// &left_square_bracket,
	// &right_square_bracket,
	// &c_left_square_bracket,
	// &c_right_square_bracket,
	// &m3_m2,
	// &mprv,
	// &mply,
	// &mnxt,
	// &smprv,
	// &smply,
	// &smnxt,
	// &vol_pgup,
	// &vol_pgdn,
	// &svol_pgup,
	// &svol_pgdn,
	// &msu_whu,
	// &msd_whd,
	// &msl_bck,
	// &msr_fwd,
	// &amsu_whu,
	// &amsd_whd,
	// &amsl_bck,
	// &amsr_fwd,
	// &m1_mute,
	// &slsh_bsls,
	// &tild_grv,
	// &zero_plus,
	// &nine_ques,
	// &astr_pipe,
	// &home_up,
	// &end_down,
	// &up_home,
	// &down_end,
    // NULL
// };