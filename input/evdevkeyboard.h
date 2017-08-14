/**
 * evdevkeyboard.h - evdevkeyboard keyboard specialization.
 **/
#pragma once

#include <unordered_map>

#include <thread>

#include "inputmanager.h"

#include "keyboard.h"

#include "evdevice.h"

class EVKeyboard : public Keyboard {
public:
  EVKeyboard(const evdevice & dev) : Keyboard(), device(dev) {
    setupMapping();
  }

  ~EVKeyboard() {

  }

  void setupMapping() {
    evKC.insert({KEY_ESC, KC_Escape});

    evKC.insert({KEY_LEFT, KC_Left});
    evKC.insert({KEY_RIGHT, KC_Right});
    evKC.insert({KEY_UP, KC_Up});
    evKC.insert({KEY_DOWN, KC_Down});
  }

  static void print_event(const struct input_event & event) {
    std::cout << "Event: " << event.type << " "
              << libevdev_event_type_get_name(event.type)
              << " code: " << event.code << " "
              << libevdev_event_code_get_name(event.type, event.code)
              << std::endl;
  }

  void handleEvents() override {
    struct input_event event;

    if (device.dev == nullptr) {
      std::cout << "Uninitialized device." << std::endl;

      return;
    }

    int rc = libevdev_next_event(device.dev, LIBEVDEV_READ_FLAG_NORMAL
        | LIBEVDEV_READ_FLAG_BLOCKING, &event);

    if (rc == LIBEVDEV_READ_STATUS_SUCCESS) {
      if (event.type == EV_KEY) {
        print_event(event);

        auto iter = evKC.find(event.code);

        if (iter != evKC.end()) {
          toggleKey(iter->second);
        }
      }
    }
  }

private:
  const evdevice device;

  std::unordered_map<int,KeyConstant> evKC;
};
