// #ifndef MKYRIA_H
// #define MKYRIA_H
#pragma once
#include "quantum.h"

#define LAYOUT( \
    L00, L01, L02, L03, L04, L05,                     R06, R07, R08, R09, R10, R11, \
    L12, L13, L14, L15, L16, L17,                     R18, R19, R20, R21, R22, R23, \
    L24, L25, L26, L27, L28, L29, L30, L31, R32, R33, R34, R35, R36, R37, R38, R39, \
                   L40, L41, L42, L43, L44, R45, R46, R47, R48, R49 \
) \
{ \
	{ L00,   L01,   L02,   L03,   L04,   L05,   KC_NO, KC_NO }, \
    { L12,   L13,   L14,   L15,   L16,   L17,   KC_NO, KC_NO }, \
    { L24,   L25,   L26,   L27,   L28,   L29,   L30,   L31   }, \
    { KC_NO, KC_NO, KC_NO, L40,   L41,   L42,   L43,   L44   }, \
    { KC_NO, KC_NO, R06,   R07,   R08,   R09,   R10,   R11   }, \
    { KC_NO, KC_NO, R18,   R19,   R20,   R21,   R22,   R23   }, \
    { R32,   R33,   R34,   R35,   R36,   R37,   R38,   R39   }, \
    { R45,   R46,   R47,   R48,   R49,   KC_NO, KC_NO, KC_NO }, \
}
#define LAYOUT_split_3x6_5 LAYOUT