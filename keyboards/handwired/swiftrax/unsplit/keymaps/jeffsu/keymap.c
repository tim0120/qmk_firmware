/*
Copyright 2020 Swiftrax <swiftrax@gmail.com>

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
#include "jeffsu.c"

#include <stdio.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_VA_ARGS(
    ___BASE_1___,
    ___BASE_2___,
    ___BASE_3___,
    ___BASE_4THUMBS___),

  [_NUM] = LAYOUT_VA_ARGS(
    ___NUM_1___,
    ___NUM_2___,
    ___NUM_3___,
    ___NUM_4THUMBS___),

  [_SYM] = LAYOUT_VA_ARGS(
    ___SYM_1___,
    ___SYM_2___,
    ___SYM_3___,
    ___SYM_4THUMBS___),

  [_ADJ] = LAYOUT_VA_ARGS(
    ___ADJ_1___,
    ___ADJ_2___,
    ___ADJ_3___,
    ___ADJ_4THUMBS___),

  [_DESK] = LAYOUT_VA_ARGS(
    ___DESK_1___,
    ___DESK_2___,
    ___DESK_3___,
    ___DESK_4THUMBS___),
};
