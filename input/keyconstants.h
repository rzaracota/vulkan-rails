/**
 * keyconstants.h - constant definitions for keyboard keys
 **/
#pragma once

typedef enum _KeyState {
  KS_Down,
  KS_Up,
  KS_Repeat
} KeyState;

typedef enum _KeyConstant {
  KC_Escape = 0,
  KC_Space,
  KC_Left,
  KC_Right,
  KC_Down,
  KC_Up,
  KC_A,
  KC_D,
  KC_S,
  KC_W,
  KC_KEY_CONSTANTS_END
} KeyConstant;
