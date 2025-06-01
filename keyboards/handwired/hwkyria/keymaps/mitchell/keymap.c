#include QMK_KEYBOARD_H
#include "quantum.h"

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

enum custom_keycodes {
	squared = SAFE_RANGE,
	cubed,
	degree,
};

// Aliases for readability
#define MTGAP    TO(_MTGAP)

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

#define MIR   	 TL_LOWR
#define QMIR   	 LT(_QMIR, KC_BSPC)

#define ARACTV   TG(_ARACTV)

#define NAV      MO(_NAV)
#define NAV2     MO(_NAV2)
#define NAV3     MO(_NAV3)
#define SYM      MO(_SYM)

#define FKEY     MO(_FKEY)

#define SET      MO(_SET)
#define SET2     MO(_SET2)

#define HM_ESC LSFT_T(KC_ESC)
#define HM_ENT RSFT_T(KC_ENT)


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
      KC_DEL ,  KC_P   ,  KC_O  , KC_I   ,  KC_U  ,  KC_Y  ,                                     _______,   KC_7 ,   KC_8 ,   KC_9 , KC_PAST, _______,
      KC_ENT ,  KC_SCLN,  KC_L  , KC_K   ,  KC_J  ,  KC_H  ,                                     KC_PPLS,   KC_4 ,   KC_5 ,   KC_6 ,   KC_0 , KC_ENT ,
      KC_RCTL,  KC_COMM,  KC_DOT, KC_COMM,  KC_M  ,  KC_N  , _______, _______, _______, _______, KC_PMNS,   KC_1 ,   KC_2 ,   KC_3 , KC_SLSH, _______,
                                  KC_APP , KC_RALT, KC_BSPC, _______, _______,  FKEY  , _______, KC_PDOT, _______, _______
    ),

	[_ARACTV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______,  FKEY  , _______, _______, _______, _______, _______, _______, _______, _______,
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
      KC_LCTL,   NAV2 , KC_MPRV, KC_MPLY, KC_MNXT , KC_VOLD, _______, _______, _______, KC_SLEP, KC_TILD, KC_EXLM,  KC_AT , KC_HASH, _______, _______,
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
      _______, squared,  cubed , KC_UNDS, KC_SLSH, KC_LPRN, _______, _______,  FKEY  , _______, KC_PGDN, KC_F13 ,  KC_F14 ,  KC_F15 ,  KC_F24 , _______,
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


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode){
		case squared:
			if(record->event.pressed){ 
				SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(50) SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P7) SS_TAP(X_P8) SS_DELAY(50) SS_UP(X_LALT));
			}
			break;
		case cubed:
			if(record->event.pressed){ 
				SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(50) SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P7) SS_TAP(X_P9) SS_DELAY(50) SS_UP(X_LALT));
			}
			break;
		case degree:
			if(record->event.pressed){ 
				SEND_STRING(SS_DOWN(X_LALT) SS_DELAY(50) SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P7) SS_TAP(X_P6) SS_DELAY(50) SS_UP(X_LALT));
			}
			break;
    }
    return true;
}