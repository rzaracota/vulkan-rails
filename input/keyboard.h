/**
 * keyboard.h - a keyboard will hold state information about a single keyboard.
 *              This will be the superclass of specialized keyboards such as
 *              evdev, xlib, or win32
 **/
#pragma once

#include <unordered_map>

#include "keyconstants.h"

class Keyboard {
public:
  Keyboard() {
    reinitialize();
  }

  ~Keyboard() {

  }

  bool getKeyState(KeyConstant key) const {
    return keys.at(key);
  }

private:
  void reinitialize() {
    for (int i = 0; i < KC_KEY_CONSTANTS_END; i++) {
      keys[i] = false;
    }
  }

  std::unordered_map<int, bool> keys;
};
