/**
 * evdevkeyboard.h - evdevkeyboard keyboard specialization.
 **/
#pragma once

#include <thread>

#include "inputmanager.h"

#include "keyboard.h"

#include "evdevice.h"

class EVKeyboard : public Keyboard {
public:
  EVKeyboard(const evdevice & dev) : device(dev) {

  }

  EVKeyboard(const EVKeyboard & that) : device(that.device) {
    std::cout << "EVKeyboard copy ctor" << std::endl;
  }

  ~EVKeyboard() {

  }

  static void print_event(const struct input_event & event) {
    std::cout << "Event: " << event.type << std::endl;
  }

  void handleEvents() override {
    std::cout << "Handle evdevkeyboard events" << std::endl;

    struct input_event event;

    int rc = libevdev_next_event(device.dev, LIBEVDEV_READ_FLAG_NORMAL, &event);

    if (rc == LIBEVDEV_READ_STATUS_SUCCESS) {
      print_event(event);
    } else {
      std::cout << "No new events" << std::endl;
    }
  }

private:
  const evdevice & device;
};
