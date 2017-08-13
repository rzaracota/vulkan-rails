#include <iostream>

#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>

#include <linux/input.h>
#include <libevdev-1.0/libevdev/libevdev.h>

#include "evdevkeyboard.h"

#include "evdevinputmanager.h"

#include "evdevice.h"

EVInputManager::EVInputManager() {
}

EVInputManager::~EVInputManager() {

}

void EVInputManager::get_keyboards() {
  DIR * dirp = nullptr;

  dirp = opendir(deviceDirectory.c_str());

  if (dirp == nullptr) {
    throw std::runtime_error("Failed to open device directory: "
                              + deviceDirectory);
  }

  auto dent = readdir(dirp);

  while (dent != nullptr) {
    if (dent->d_type != DT_DIR) {
      try {
        evdevice dev(deviceDirectory + "/" + std::string(dent->d_name));

        if (dev.getClass() == DC_Keyboard) {
          EVKeyboard kb;

          add_keyboard(kb);

          std::cout << dev << std::endl;
        }
      } catch (std::exception & e) {
        std::cerr << e.what() << std::endl;
      }
    }

    dent = readdir(dirp);
  }
}

void EVInputManager::get_mice() {

}
