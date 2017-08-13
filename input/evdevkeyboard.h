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

  ~EVKeyboard() {

  }

  static void print_event(const struct input_event & event) {
    std::cout << "Event: " << event.type << std::endl;
  }

  void handleEvents() override {
    std::cout << "EVKeyboard->handleEvents: " << device.name << std::endl;

    struct input_event event;

    if (device.dev == nullptr) {
      std::cout << "Uninitialized device." << std::endl;

      return;
    }

    int rc = libevdev_next_event(device.dev, LIBEVDEV_READ_FLAG_NORMAL, &event);

    if (rc == LIBEVDEV_READ_STATUS_SUCCESS) {
      print_event(event);
    } else {
      std::cout << "rc: " << rc << std::endl;
    }
  }

private:
  const evdevice device;
};
