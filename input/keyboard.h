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

  }

  ~Keyboard() {

  }

  void reinitialize() {
    for (auto iter = keys.begin(); iter != keys.cend(); iter++) {
      iter->second = false;
    }
  }

private:
  std::unordered_map<int, bool> keys;
};
