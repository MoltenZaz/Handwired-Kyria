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
    _DVORAK,
	_NPAD,
    _GAMING,
    _QWERTY,
    _MIR,
    _DMIR,
    _GMIR,
    _QMIR,
	_NPAD2,
    _NMOD,
    _RARW,
    _NAV,
    _NAV2,
    _SLMIR,
    _SYML,
    _SLMIR2,
    _SYM,
    _SMIR,
    _FKEY,
    _PLOVER,
    _SET,
};

// void matrix_init_user() {
  // steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
// }

// Aliases for readability
#define MTGAP    TO(_MTGAP)
#define DVORAK   TO(_DVORAK)
#define GAMING   TO(_GAMING)
#define QWERTY   TO(_QWERTY)

#define LM_LCTL  LM(_QWERTY, MOD_LCTL)
#define LM_LGUI  LM(_QWERTY, MOD_LGUI)
#define LM_LALT  LM(_QWERTY, MOD_LALT)
#define LM_RALT  LM(_QWERTY, MOD_LALT)
#define LM_RCTL  LM(_QWERTY, MOD_LCTL)

#define LMM_LCTL  LM(_QMIR, MOD_LCTL)
#define LMM_LGUI  LM(_QMIR, MOD_LGUI)
#define LMM_LALT  LM(_QMIR, MOD_LALT)
#define LMM_RALT  LM(_QMIR, MOD_LALT)
#define LMM_RCTL  LM(_QMIR, MOD_LCTL)

#define MIR   	 MO(_MIR)
#define DMIR   	 MO(_DMIR)
#define GMIR   	 MO(_GMIR)
#define QMIR   	 MO(_QMIR)

#define NPAD   	 TG(_NPAD)
#define NPAD2    MO(_NPAD2)
#define NMOD   	 TG(_NMOD)
#define RARW   	 TG(_RARW)

#define NAVR     MO(_NAVR)
#define NAV      MO(_NAV)
#define NAV2     MO(_NAV2)
#define SLMIR    MO(_SLMIR)
#define SYML     MO(_SYML)
#define SLMIR2   MO(_SLMIR2)
#define SYM      MO(_SYM)
#define SMIR     MO(_SMIR)
#define FKEY     MO(_FKEY)
#define PLOVER   TG(_PLOVER)
#define SET      MO(_SET)

#define BK_SFT   LSFT_T(KC_BSPC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_MTGAP] = LAYOUT(
     KC_TAB , KC_Y ,  KC_P   ,  KC_O  ,   KC_U ,   KC_J    ,                                         KC_K,    KC_D ,  KC_L ,   KC_C ,  KC_W, KC_ENT,
     SC_LSPO, KC_I ,  KC_N   ,  KC_E  ,   KC_A ,   KC_DOT  ,                                         KC_M,    KC_H ,  KC_T ,   KC_S ,  KC_R, SC_RSPC,
     LM_LCTL, KC_Q ,  KC_Z   ,  KC_QUOT,  KC_COMM, KC_SCLN , KC_ESC,  SLMIR ,     KC_F13  , KC_DEL , KC_B,    KC_F ,  KC_G ,   KC_V ,  KC_X, LM_RCTL,
                                LM_LGUI , LM_LALT,   NAV   , KC_SPC , MIR   ,       SYM   , KC_BSPC, NAV ,  LM_RALT, KC_APP
    ),

    [_DVORAK] = LAYOUT(
     _______, KC_QUOT, KC_COMM,  KC_DOT,   KC_P ,   KC_Y  ,                                      KC_F  ,   KC_G  ,  KC_C ,   KC_R ,  KC_L , _______,
     _______, KC_A   , KC_O   ,  KC_E  ,   KC_U ,   KC_I  ,                                      KC_D  ,   KC_H  ,  KC_T ,   KC_N ,  KC_S , _______,
     _______, KC_SCLN, KC_Q   ,  KC_J  ,   KC_K ,   KC_X  , _______, _______, _______, _______,  KC_B  ,   KC_M  ,  KC_W ,   KC_V ,  KC_Z , LM_RCTL,
                                _______, _______,  _______, _______, DMIR   , _______, _______, _______,  _______, _______
    ),

	[_NPAD] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______,  NPAD2 , _______, _______, _______, _______, _______, _______, _______
    ),
	
    [_QWERTY] = LAYOUT(
     _______, KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                     KC_Y,    KC_U ,   KC_I ,   KC_O ,  KC_P ,   _______,
     _______, KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                     KC_H,    KC_J ,   KC_K ,   KC_L ,  KC_SCLN, _______,
     KC_LCTL, KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , _______, _______, _______, _______, KC_N,    KC_M ,   KC_COMM, KC_DOT ,KC_SLSH, LM_RCTL,
                               KC_LGUI, KC_LALT, KC_LSFT, _______, QMIR   , _______, _______, KC_RSFT, KC_RALT, KC_APP
    ),
	
    [_GAMING] = LAYOUT(
     KC_TAB  , KC_T    , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,                                         KC_Y,    KC_U ,  KC_I , KC_O , KC_P , _______,
     KC_LCTL , KC_LSFT , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,                                         KC_H,    KC_J ,  KC_K , KC_L , KC_9 , KC_RSFT,
     KC_B    , KC_G    , KC_Z ,  KC_X   ,  KC_C  ,   KC_V , KC_ESC , SLMIR  ,     _______, _______, KC_N,    KC_M ,  KC_6 , KC_7 , KC_8 , KC_RCTL,
                                 KC_APP , KC_LALT,   NAV,   KC_SPC , GMIR   ,     KC_1   , KC_2   , KC_3,    KC_4 ,  KC_5
    ),
	

    [_MIR] = LAYOUT(
      KC_ENT ,  KC_W  ,  KC_C  ,  KC_L  ,  KC_D  ,  KC_K  ,                                      KC_NUM ,  KC_P7 ,  KC_P8 ,  KC_P9 , KC_PPLS, KC_PENT,
      SC_RSPC,  KC_R  ,  KC_S  ,  KC_T  ,  KC_H  ,  KC_M  ,                                      KC_PAST,  KC_P4 ,  KC_P5 ,  KC_P6 , KC_PPLS, KC_PENT,
      LMM_RCTL, KC_X  ,  KC_V  ,  KC_G  ,  KC_F  ,  KC_B  ,  GAMING ,   FKEY ,   NMOD ,   RARW , KC_PSLS,  KC_P1 ,  KC_P2 ,  KC_P3 , KC_PMNS, _______,
                                 KC_APP , LMM_RALT, KC_BSPC, _______, _______, _______, _______,  KC_P0 , KC_PDOT, _______
    ),

    [_DMIR] = LAYOUT(
      KC_ENT ,  KC_L  ,  KC_R  ,  KC_C  ,  KC_G  ,  KC_F   ,                                     KC_NUM ,  KC_P7 ,  KC_P8 ,  KC_P9 , KC_PPLS, KC_PENT,
      SC_RSPC,  KC_S  ,  KC_N  ,  KC_T  ,  KC_H  ,  KC_D   ,                                     KC_PAST,  KC_P4 ,  KC_P5 ,  KC_P6 , KC_PPLS, KC_PENT,
      LMM_RCTL, KC_Z  ,  KC_V  ,  KC_W  ,  KC_M  ,  KC_B   , GAMING ,   FKEY ,   NMOD ,   RARW , KC_PSLS,  KC_P1 ,  KC_P2 ,  KC_P3 , KC_PMNS, _______,
                                 KC_APP , LMM_RALT, KC_BSPC, _______, _______, _______, _______,  KC_P0 , KC_PDOT, _______
    ),

    [_GMIR] = LAYOUT(
      KC_ENT ,  KC_P   ,  KC_O  , KC_I   ,  KC_U  ,  KC_Y  ,                                     KC_NUM ,  KC_P7 ,  KC_P8 ,  KC_P9 , KC_PPLS, KC_PENT,
      KC_RSFT,  KC_SCLN,  KC_L  , KC_K   ,  KC_J  ,  KC_H  ,                                     KC_PAST,  KC_P4 ,  KC_P5 ,  KC_P6 , KC_PPLS, KC_PENT,
      KC_RCTL,  KC_COMM,  KC_DOT, KC_COMM,  KC_M  ,  KC_N  , GAMING ,   FKEY ,   NMOD ,   RARW , KC_PSLS,  KC_P1 ,  KC_P2 ,  KC_P3 , KC_PMNS, _______,
                                  KC_RGUI, KC_RALT, KC_BSPC, _______, _______, _______, _______, KC_P0  , KC_PDOT, _______
    ),
	
    [_QMIR] = LAYOUT(
      KC_ENT ,  KC_P   ,  KC_O  , KC_I   ,  KC_U  ,  KC_Y  ,                                     KC_NUM ,  KC_P7 ,  KC_P8 ,  KC_P9 , KC_PPLS, KC_PENT,
      KC_RSFT,  KC_SCLN,  KC_L  , KC_K   ,  KC_J  ,  KC_H  ,                                     KC_PAST,  KC_P4 ,  KC_P5 ,  KC_P6 , KC_PPLS, KC_PENT,
      KC_RCTL,  KC_COMM,  KC_DOT, KC_COMM,  KC_M  ,  KC_N  , GAMING ,   FKEY ,   NMOD ,   RARW , KC_PSLS,  KC_P1 ,  KC_P2 ,  KC_P3 , KC_PMNS, _______,
                                  KC_APP , KC_RALT, KC_BSPC, _______, _______, _______, _______, KC_P0  , KC_PDOT, _______
    ),
	
	[_NPAD2] = LAYOUT(
      _______, KC_ENT ,  KC_7  ,  KC_8  ,  KC_9  , KC_BSPC,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_0  ,  KC_4  ,  KC_5  ,  KC_6  , KC_DOT ,                                     _______, _______, _______, _______, _______, _______,
      _______,  KC_0  ,  KC_1  ,  KC_2  ,  KC_3  , _______,   NPAD , _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
	
    [_NMOD] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      KC_LSFT, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, KC_RSFT,
      KC_LCTL, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_RCTL,
                                 KC_LGUI, KC_LALT, _______, _______, _______, _______, _______, _______, KC_RALT, _______
    ),
	
	[_RARW] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______,  KC_UP ,  _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                     _______, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
	
	[_NAV] = LAYOUT(
      KC_BTN3, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R , KC_BTN1,                                     KC_BTN1, KC_MS_L, KC_MS_U, KC_MS_D, KC_MS_R , KC_BTN3,
      KC_LSFT, KC_LEFT, KC_DOWN,  KC_UP , KC_RIGHT, KC_VOLU,                                     KC_VOLU, KC_LEFT, KC_UP  , KC_DOWN, KC_RIGHT, KC_RSFT,
      KC_LCTL,   NAV2 , KC_MPRV, KC_MPLY, KC_MNXT , KC_VOLD,  NPAD  , KC_SLEP, _______, _______, KC_VOLD, KC_MPRV, KC_MPLY, KC_MNXT,   NAV2  , KC_RCTL,
                                 _______, _______ , _______, _______, _______, _______, _______, _______, _______, _______
    ),

	[_NAV2] = LAYOUT(
      PLOVER , G(KC_0), G(KC_9), G(KC_8), G(KC_7), G(KC_6),                                     G(KC_5), G(KC_4), G(KC_3), G(KC_2), G(KC_1), _______,
      _______, G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5),                                     G(KC_6), G(KC_7), G(KC_8), G(KC_9), G(KC_0), _______,
      _______, _______, _______, _______, _______, _______, QWERTY , DVORAK , _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
		
	[_SLMIR] = LAYOUT(
      KC_ENT , KC_BSLS, KC_AMPR, KC_ASTR, KC_PMNS, KC_LCBR,                                     _______, _______, _______, _______, _______, _______,
      SC_RCPC, KC_PPLS,  KC_DLR, KC_PERC, KC_CIRC, KC_RCBR,                                     _______, _______, _______, _______, _______, _______,
      _______, KC_PIPE, KC_EXLM,  KC_AT , KC_HASH, KC_EQL ,  MTGAP , _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 KC_PAUS, _______, KC_BSPC, _______,   SYML , _______, _______, _______, _______, _______
    ),
	
	[_SYML] = LAYOUT(
      KC_TAB , KC_SLSH,  KC_7  ,  KC_8  ,  KC_9  , KC_LBRC,                                     _______, _______, _______, _______, _______, _______,
      SC_LCPO,  KC_0  ,  KC_4  ,  KC_5  ,  KC_6  , KC_RBRC,                                     _______, _______, _______, _______, _______, _______,
      _______, KC_QUES,  KC_1  ,  KC_2  ,  KC_3  , KC_UNDS, KC_CAPS, SLMIR2 , _______, _______, _______, _______, _______, _______, _______, _______,
                                 KC_PSCR, _______, KC_BSPC, _______,   SYML , _______, _______, _______, _______, _______
    ),
	
	[_SLMIR2] = LAYOUT(
      KC_ENT , KC_BSLS, KC_AMPR, KC_ASTR, KC_PMNS, KC_LCBR,                                     _______, _______, _______, _______, _______, _______,
      SC_RCPC, KC_PPLS,  KC_DLR, KC_PERC, KC_CIRC, KC_RCBR,                                     _______, _______, _______, _______, _______, _______,
      _______, KC_PIPE, KC_EXLM,  KC_AT , KC_HASH, KC_EQL ,  MTGAP , _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 KC_PAUS, _______, KC_BSPC, _______,   SYML , _______, _______, _______, _______, _______
    ),
	
	[_SYM] = LAYOUT(
      KC_GRV , KC_EXLM,  KC_AT , KC_HASH, KC_DLR , KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_PMNS, KC_PPLS, KC_SCRL,
      SC_LAPO,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,                                      KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  , SC_RAPC,
      _______, KC_LBRC, KC_RBRC, KC_QUES, KC_SLSH, KC_UNDS,  MTGAP , _______,   FKEY , KC_INS , KC_EQL , KC_BSLS, KC_PIPE, KC_LCBR, KC_RCBR, _______,
                                 _______, _______, KC_LSFT, _______,  SMIR  , _______, _______, KC_RSFT, _______, KC_PAUS
    ),
	
    [_SMIR] = LAYOUT(
      KC_SCRL, KC_PPLS, KC_PMNS, KC_ASTR, KC_AMPR, KC_CIRC,                                     KC_PERC, KC_DLR , KC_HASH,  KC_AT , KC_EXLM, KC_GRV ,
      SC_RAPC,  KC_0  ,  KC_9  ,  KC_8  ,  KC_7  ,  KC_6  ,                                      KC_5  ,  KC_4  ,  KC_3  ,  KC_2  ,  KC_1  , SC_LAPO,
      _______, KC_LCBR, KC_RCBR, KC_PIPE, KC_BSLS, KC_EQL , KC_INS , _______, _______, _______, KC_UNDS, KC_SLSH, KC_QUES, KC_LBRC, KC_RBRC, _______,
                                 KC_PAUS, _______, KC_RSFT, _______, _______, _______, _______, KC_LSFT, _______, _______
    ),
	
    [_FKEY] = LAYOUT(
      KC_DEL , KC_F10 ,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F13 ,                                     KC_PSCR, KC_F7 ,  KC_F8 ,  KC_F9 ,  KC_F10 , KC_DEL ,
      _______, KC_F11 ,  KC_F4 ,  KC_F5 ,  KC_F6 , KC_HOME,                                     KC_PGUP, KC_F4 ,  KC_F5 ,  KC_F6 ,  KC_F11 , _______,
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
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DT_PRNT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DT_PRNT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
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
		case 2:
          layer_on(_NPAD);
          break;
		case 3:
          layer_off(_NPAD);
          break;
	}
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

const key_override_t mprv = ko_make_basic(MOD_MASK_CTRL, KC_MPRV, KC_CALC);
const key_override_t mply = ko_make_basic(MOD_MASK_CTRL, KC_MPLY, KC_MSEL);
const key_override_t mnxt = ko_make_basic(MOD_MASK_CTRL, KC_MNXT, KC_MYCM);

const key_override_t smprv = ko_make_basic(MOD_MASK_SHIFT, KC_MPRV, KC_CALC);
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

const key_override_t pgdn_end = ko_make_with_layers(MOD_MASK_SHIFT, KC_PGDN, KC_END, 1<<_SYML);
const key_override_t pgup_home = ko_make_with_layers(MOD_MASK_SHIFT, KC_PGUP, KC_HOME, 1<<_SYML);
const key_override_t ques_pipe = ko_make_with_layers(MOD_MASK_SHIFT, KC_QUES, KC_PIPE, 1<<_SYML);
const key_override_t slsh_bsls = ko_make_with_layers(MOD_MASK_SHIFT, KC_SLSH, KC_BSLS, 1<<_SYML);
const key_override_t tild_grv = ko_make_with_layers(MOD_MASK_SHIFT, KC_TILD, KC_GRV, 1<<_SYML);
const key_override_t zero_plus = ko_make_with_layers(MOD_MASK_SHIFT, KC_0, KC_PPLS, 1<<_SYML);
const key_override_t nine_mins = ko_make_with_layers(MOD_MASK_SHIFT, KC_9, KC_MINS, 1<<_SYML);

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
	&pgdn_end,
	&pgup_home,
	&ques_pipe,
	&slsh_bsls,
	&tild_grv,
	&zero_plus,
	&nine_mins,
	&home_up,
	&end_down,
	&up_home,
	&down_end,
	// &capsl,
	// &capsr,
    NULL
};