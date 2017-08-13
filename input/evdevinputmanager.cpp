#include <iostream>

#include <fcntl.h>
#include <sys/types.h>

#include <linux/input.h>
#include <libevdev-1.0/libevdev/libevdev.h>

#include "evdevkeyboard.h"

#include "evdevinputmanager.h"

struct evdevice {
  evdevice(std::string filename) : deviceFilename(filename) {
    int fd = open(filename.c_str(), O_RDONLY);

    if (fd < 0) {
      throw std::runtime_error("Failed to open device: " + filename);
    }
  }

  ~evdevice() {
    if (dev != nullptr) {
      libevdev_free(dev);
    }
  }

  friend std::ostream & operator<<(std::ostream & output,
    struct evdevice & device) {
      using std::cout;
      using std::endl;

      cout << "ID: bus " << libevdev_get_id_bustype(device.dev) << " vendor "
           << libevdev_get_id_vendor(device.dev) << " product "
           << libevdev_get_id_product(device.dev) << endl;
    }

  struct libevdev * dev = nullptr;

  const std::string deviceFilename;
};

EVInputManager::EVInputManager() {
}

EVInputManager::~EVInputManager() {

}

void EVInputManager::get_keyboards() {
  EVKeyboard kb;

  add_keyboard(kb);
}

void EVInputManager::get_mice() {

}
