/**
 * keyboard.h - a keyboard will hold state information about a single keyboard.
 *              This will be the superclass of specialized keyboards such as
 *              evdev, xlib, or win32
 **/
#pragma once

#include <iostream>

#include <unordered_map>

#include "keyconstants.h"

class Keyboard {
public:
  Keyboard() {
    reinitialize();
  }

  ~Keyboard() {

  }

  virtual void handleEvents() {
  }

  bool getKeyState(KeyConstant key) const {
    if (key < 0 || key > KC_KEY_CONSTANTS_END) {
      throw std::runtime_error("Invalid key specified: " + key);
    }

    return keys.at(key);
  }

  void toggleKey(KeyConstant key) {
    keys[key] = !keys.at(key);
  }

  void reinitialize() {
    for (int i = 0; i < KC_KEY_CONSTANTS_END; i++) {
      keys[i] = false;
    }
  }

private:

  std::unordered_map<int, bool> keys;
};
