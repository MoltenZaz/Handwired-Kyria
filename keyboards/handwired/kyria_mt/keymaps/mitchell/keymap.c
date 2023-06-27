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

enum layers {
    _MTGAP = 0,
    _DVORAK,
    _GAMING,
    _QWERTY,
    _MIR,
    _DMIR,
    _GMIR,
    _QMIR,
    _NMOD,
    _RARW,
    _NAV,
    _NAV2,
    _SYM,
    _SMIR,
    _FKEY,
	_FKEYNUM,
    _PLOVER,
    _SET,
};

void matrix_init_user() {
  steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
}

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

#define NMOD   	 TG(_NMOD)
#define RARW   	 TG(_RARW)

#define NAV      MO(_NAV)
#define NAV2     MO(_NAV2)
#define SYM      MO(_SYM)
#define SMIR     MO(_SMIR)
#define FKEY     MO(_FKEY)
#define FKEYNUM  MO(_FKEYNUM)
#define PLOVER   TG(_PLOVER)
#define SET      MO(_SET)

// Note: LAlt/Enter (ALT_ENT) is not the same thing as the keyboard shortcut Alt+Enter.
// The notation `mod/tap` denotes a key that activates the modifier `mod` when held down, and
// produces the key `tap` when tapped (i.e. pressed and released).

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_MTGAP] = LAYOUT(
     KC_TAB  , KC_Y ,  KC_P   ,  KC_O  ,   KC_U ,   KC_J ,                                            KC_K,    KC_D ,  KC_L ,   KC_C ,  KC_W , KC_ENT,
     SC_LSPO , KC_I ,  KC_N   ,  KC_E  ,   KC_A ,   KC_COMM ,                                         KC_M,    KC_H ,  KC_T ,   KC_S ,  KC_R,  SC_RSPC,
     LM_LCTL , KC_Q ,  KC_Z   ,  KC_QUOT,  KC_DOT,  KC_SCLN , KC_ESC,  SYM   ,     KC_F13  , KC_DEL,  KC_B,    KC_F ,  KC_G,    KC_V ,  KC_X,  LM_RCTL,
                                 LM_LGUI , LM_LALT,   NAV,    KC_SPC , MIR   ,      SYM    , KC_BSPC, NAV,    LM_RALT, KC_APP
    ),

    [_DVORAK] = LAYOUT(
     KC_TAB  ,KC_QUOTE,KC_COMM,  KC_DOT,   KC_P ,   KC_Y ,                                         KC_F,   KC_G ,  KC_C ,   KC_R ,  KC_L , KC_ENT,
     SC_LSPO, KC_A ,   KC_O   ,  KC_E  ,   KC_U ,   KC_I ,                                         KC_D,   KC_H ,  KC_T ,   KC_N ,  KC_S , SC_RSPC,
     LM_LCTL ,KC_SCLN, KC_Q   ,  KC_J  ,   KC_K ,   KC_X , KC_ESC , SYM    ,     KC_F13 , KC_DEL,  KC_B,   KC_M ,  KC_W ,   KC_V ,  KC_Z , LM_RCTL,
                                 LM_LGUI, LM_LALT,  NAV,   KC_SPC , DMIR   ,      SYM   , KC_BSPC, NAV,   LM_RALT, KC_APP
    ),

    [_QWERTY] = LAYOUT(
     KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,   KC_T ,                                         KC_Y,    KC_U ,   KC_I ,   KC_O ,  KC_P ,   KC_ENT,
     SC_LSPO , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,   KC_G ,                                         KC_H,    KC_J ,   KC_K ,   KC_L ,  KC_SCLN, SC_RSPC,
     KC_LCTL , KC_Z ,  KC_X   ,  KC_C  ,   KC_V ,   KC_B , KC_ESC , SYM    ,     KC_F13 , KC_DEL , KC_N,    KC_M ,   KC_COMM, KC_DOT ,KC_SLSH, LM_RCTL,
                                KC_LGUI , KC_LALT, KC_LSFT,KC_SPC , QMIR   ,       SYM  , KC_BSPC, KC_RSFT, KC_RALT, KC_APP
    ),
	
    [_GAMING] = LAYOUT(
     KC_T    , KC_TAB  , KC_Q ,  KC_W   ,  KC_E  ,   KC_R ,                                         KC_Y,    KC_U ,  KC_I , KC_O , KC_P , KC_ENT,
     KC_G    , KC_LSFT , KC_A ,  KC_S   ,  KC_D  ,   KC_F ,                                         KC_H,    KC_J ,  KC_K , KC_L , KC_9 , KC_RSFT,
     KC_B    , KC_LCTL , KC_Z ,  KC_X   ,  KC_C  ,   KC_V , KC_ESC , SYM    ,     KC_F13 , KC_DEL , KC_N,    KC_M ,  KC_6 , KC_7 , KC_8 , KC_RCTL,
                                 KC_APP , KC_LALT,   NAV,   KC_SPC , GMIR   ,     KC_1   , KC_2  ,  KC_3,    KC_4,   KC_5
    ),

    [_MIR] = LAYOUT(
      KC_ENT ,  KC_W  ,  KC_C  ,  KC_L  ,  KC_D  ,  KC_K  ,                                     KC_PSLS,  KC_P7 ,  KC_P8 ,  KC_P9 , KC_PPLS, KC_PENT,
      SC_RSPC,  KC_R  ,  KC_S  ,  KC_T  ,  KC_H  ,  KC_M  ,                                     KC_PAST,  KC_P4 ,  KC_P5 ,  KC_P6 , KC_PMNS, KC_PENT,
      LMM_RCTL,  KC_X  ,  KC_V  ,  KC_G  ,  KC_F  ,  KC_B  , GAMING ,   FKEY ,   NMOD ,   RARW , KC_NUM ,  KC_P1 ,  KC_P2 ,  KC_P3 , KC_PDOT, _______,
                                 KC_APP , LMM_RALT, KC_BSPC, _______, _______, _______, _______,  KC_P0 , KC_PDOT, _______
    ),

    [_DMIR] = LAYOUT(
      KC_ENT ,  KC_L  ,  KC_R  ,  KC_C  ,  KC_G  ,  KC_F  ,                                     KC_PSLS,  KC_P7 ,  KC_P8 ,  KC_P9 , KC_PPLS, KC_PENT,
      SC_RSPC,  KC_S  ,  KC_N  ,  KC_T  ,  KC_H  ,  KC_D  ,                                     KC_PAST,  KC_P4 ,  KC_P5 ,  KC_P6 , KC_PMNS, KC_PENT,
      LMM_RCTL,  KC_Z  ,  KC_V  ,  KC_W  ,  KC_M  ,  KC_B  , GAMING ,   FKEY ,   NMOD ,   RARW , KC_NUM ,  KC_P1 ,  KC_P2 ,  KC_P3 , KC_PDOT, _______,
                                 KC_APP , LMM_RALT, KC_BSPC, _______, _______, _______, _______,  KC_P0 , KC_PDOT, _______
    ),

    [_GMIR] = LAYOUT(
      KC_ENT ,  KC_P   ,  KC_O  , KC_I   ,  KC_U  ,  KC_Y  ,                                     KC_PSLS,  KC_P7 ,  KC_P8 ,  KC_P9 , KC_PPLS, KC_PENT,
      KC_RSFT,  KC_SCLN,  KC_L  , KC_K   ,  KC_J  ,  KC_H  ,                                     KC_PAST,  KC_P4 ,  KC_P5 ,  KC_P6 , KC_PMNS, KC_PENT,
      KC_RCTL,  KC_COMM,  KC_DOT, KC_COMM,  KC_M  ,  KC_N  , GAMING ,   FKEY ,   NMOD ,   RARW , KC_NUM ,  KC_P1 ,  KC_P2 ,  KC_P3 , KC_PDOT, _______,
                                  KC_APP , KC_RALT, KC_BSPC, _______, _______, _______, _______, KC_P0  , KC_PDOT, _______
    ),
	
    [_QMIR] = LAYOUT(
      KC_ENT ,  KC_P   ,  KC_O  , KC_I   ,  KC_U  ,  KC_Y  ,                                     KC_PSLS,  KC_P7 ,  KC_P8 ,  KC_P9 , KC_PPLS, KC_PENT,
      KC_LSFT,  KC_SCLN,  KC_L  , KC_K   ,  KC_J  ,  KC_H  ,                                     KC_PAST,  KC_P4 ,  KC_P5 ,  KC_P6 , KC_PMNS, KC_PENT,
      KC_LCTL,  KC_COMM,  KC_DOT, KC_COMM,  KC_M  ,  KC_N  , GAMING ,   FKEY ,   NMOD ,   RARW , KC_NUM ,  KC_P1 ,  KC_P2 ,  KC_P3 , KC_PDOT, _______,
                                  KC_APP , KC_RALT, KC_BSPC, _______, _______, _______, _______, KC_P0  , KC_PDOT, _______
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
      _______, KC_LEFT, KC_DOWN,  KC_UP , KC_RIGHT, KC_VOLU,                                     KC_VOLU, KC_LEFT, KC_UP  , KC_DOWN, KC_RIGHT, _______,
      _______,   NAV2 , KC_MPRV, KC_MPLY, KC_MNXT , KC_VOLD,  DVORAK, KC_SLEP, _______, _______, KC_VOLD, KC_MPRV, KC_MPLY, KC_MNXT,   NAV2  , _______,
                                 _______, _______ , _______, KC_ACL1, _______, _______, KC_ACL1, _______, _______, _______
    ),
	
	[_NAV2] = LAYOUT(
      _______, G(KC_0), G(KC_9), G(KC_8), G(KC_7), G(KC_6),                                     G(KC_5), G(KC_4), G(KC_3), G(KC_2), G(KC_1), _______,
      _______, G(KC_1), G(KC_2), G(KC_3), G(KC_4), G(KC_5),                                     G(KC_6), G(KC_7), G(KC_8), G(KC_9), G(KC_0), _______,
      _______, _______, _______, _______, _______, _______, QWERTY , _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
	
	
	[_SYM] = LAYOUT(
      KC_CAPS, KC_EXLM,  KC_AT , KC_HASH, KC_DLR , KC_PERC,                                     KC_CIRC, KC_AMPR, KC_ASTR, KC_MINS, KC_PPLS, KC_SCRL,
      SC_LAPO,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,                                      KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  , SC_RAPC,
      _______, KC_PGDN, KC_PGUP, KC_PIPE, KC_BSLS, KC_TILD,  MTGAP , _______,   FKEY , KC_INS , KC_GRV , KC_SLSH, KC_QUES, KC_HOME, KC_END , _______,
                                 KC_PSCR, _______, KC_LSFT, _______,  SMIR  , _______, _______, KC_RSFT, _______, KC_PAUS
    ),
	
    [_SMIR] = LAYOUT(
      KC_SCRL, KC_PPLS, KC_MINS, KC_ASTR, KC_AMPR, KC_CIRC,                                     KC_PERC, KC_DLR , KC_HASH,  KC_AT , KC_EXLM, KC_CAPS,
      SC_RAPC,  KC_0  ,  KC_9  ,  KC_8  ,  KC_7  ,  KC_6  ,                                      KC_5  ,  KC_4  ,  KC_3  ,  KC_2  ,  KC_1  , SC_LAPO,
      _______, KC_END , KC_HOME, KC_QUES, KC_SLSH, KC_GRV , KC_INS , _______, _______, _______, KC_TILD, KC_BSLS, KC_PIPE, KC_PGUP, KC_PGDN, _______,
                                 KC_PAUS, _______, KC_LSFT, _______, _______, _______, _______, KC_RSFT, _______, KC_PSCR
    ),
	
    [_FKEY] = LAYOUT(
      KC_F11 , KC_F10 ,  KC_F9 ,  KC_F8 ,  KC_F7 ,  KC_F6 ,                                      KC_F5 ,  KC_F4 ,  KC_F3 ,  KC_F2 ,  KC_F1 , KC_F12 ,
      KC_F12 ,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,                                      KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 , KC_F11 ,
      KC_LSFT, FKEYNUM, FKEYNUM, FKEYNUM, FKEYNUM, FKEYNUM,  KC_F13, _______, _______, PLOVER , FKEYNUM, FKEYNUM, FKEYNUM, FKEYNUM, FKEYNUM, KC_RSFT,
                                 KC_LCTL, KC_LGUI, KC_LALT, _______, _______, _______, _______, KC_RALT, KC_RGUI, KC_RCTL
    ),
	
	[_FKEYNUM] = LAYOUT(
      XXXXXXX,   KC_0 ,   KC_9 ,   KC_8 ,   KC_7 ,   KC_6 ,                                       KC_5 ,   KC_4 ,   KC_3 ,   KC_2 ,   KC_1 , XXXXXXX,
      SC_LSPO,   KC_1 ,   KC_2 ,   KC_3 ,   KC_4 ,   KC_5 ,                                       KC_6 ,   KC_7 ,   KC_8 ,   KC_9 ,   KC_0 , SC_RSPC,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
	
    [_PLOVER] = LAYOUT(
	  STN_N1 , STN_N2 , STN_N3 , STN_N4 , STN_N5 , STN_N6 ,  								    STN_N7 , STN_N8 , STN_N9 , STN_NA , STN_NB , STN_NC ,
	  XXXXXXX, STN_S1 , STN_TL , STN_PL , STN_HL , STN_ST1,                                     STN_ST3, STN_FR , STN_PR , STN_LR , STN_TR , STN_DR ,
	  XXXXXXX, STN_S2 , STN_KL , STN_WL , STN_RL , STN_ST2,  MTGAP , XXXXXXX,    SET , XXXXXXX, STN_ST4, STN_RR , STN_BR , STN_GR , STN_SR , STN_ZR ,
								 XXXXXXX, XXXXXXX, XXXXXXX,  STN_A , STN_O  ,  STN_E , STN_U  , XXXXXXX, XXXXXXX, XXXXXXX
    ),
	
    [_SET] = LAYOUT(
      QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  NK_ON ,                                      NK_ON , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_BOOT,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  NK_OFF,                                      NK_OFF, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
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

const key_override_t delete_key_override = ko_make_with_layers(MOD_MASK_SHIFT, KC_BSPC, KC_DEL, 1<<_MIR | 1<<_DMIR | 1<<_GMIR);

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

const key_override_t vol_whu = ko_make_basic(MOD_MASK_CTRL, KC_VOLU, KC_WH_U);
const key_override_t vol_whd = ko_make_basic(MOD_MASK_CTRL, KC_VOLD, KC_WH_D);

const key_override_t svol_whu = ko_make_basic(MOD_MASK_SHIFT, KC_VOLU, KC_WH_U);
const key_override_t svol_whd = ko_make_basic(MOD_MASK_SHIFT, KC_VOLD, KC_WH_D);

const key_override_t m1_mute = ko_make_basic(MOD_MASK_SHIFT, KC_BTN1, KC_MUTE);

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
	&delete_key_override,
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
	&vol_whu,
	&vol_whd,
	&svol_whu,
	&svol_whd,
	&m1_mute,
    NULL
};