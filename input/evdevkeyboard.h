/**
 * evdevkeyboard.h - evdevkeyboard keyboard specialization.
 **/

#pragma once

#include "inputmanager.h"

#include "keyboard.h"

#include "evdevice.h"

class EVKeyboard : public Keyboard {
public:
  EVKeyboard(const evdevice & dev) : device(dev) {

  }

  ~EVKeyboard() {

  }
private:
  const evdevice & device;
};
