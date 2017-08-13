#pragma once

struct evdevice {
  evdevice(std::string filename) : deviceFilename(filename),
                                   deviceClass(DC_Unknown) {
    int fd = open(filename.c_str(), O_RDONLY);

    if (fd < 0) {
      throw std::runtime_error("Failed to open device: " + filename);
    }

    if (libevdev_new_from_fd(fd, &dev) < 0) {
      throw std::runtime_error("Failed to open device: " + filename);
    }

    get_information();

    determineClass();
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

      if (device.dev == nullptr) {
        output << device.deviceFilename << ": Device not loaded.";

        return output;
      }

      output << device.deviceFilename << ": " << device.name
             << " : " << InputManager::DeviceClassNames(device.deviceClass);

      return output;
  }

  void get_information() {
    evdevVersion = libevdev_get_driver_version(dev);
    name = std::string(libevdev_get_name(dev));

    const char * phys = libevdev_get_phys(dev);

    location = (phys != nullptr) ? phys : "";

    const char * uniq = libevdev_get_uniq(dev);

    uniqueID = (uniq != nullptr) ? uniq : "";
  }

  bool checkMouse() const {
    bool result = false;

    // has motion events
    if (libevdev_has_event_type(dev, 2)
        && libevdev_has_event_code(dev, EV_REL, REL_X)
        && libevdev_has_event_code(dev, EV_REL, REL_Y)) {
          result = true;
    }

    return result;
  }

  bool checkKeyboard() const {
    bool result = false;

    // has key events
    if (libevdev_has_event_type(dev, 1)
        && libevdev_has_event_code(dev, EV_KEY, KEY_ESC)
        && libevdev_has_event_code(dev, EV_KEY, KEY_SPACE)) {
          result = true;
    }

    return result;
  }

  void determineClass() {
    bool maybeMouse = checkMouse();
    bool maybeKeyboard = checkKeyboard();

    if (maybeMouse && !maybeKeyboard) {
      deviceClass = DC_Mouse;
    } else if (maybeKeyboard && !maybeMouse) {
      deviceClass = DC_Keyboard;
    } else {
      deviceClass = DC_Unknown;
    }
  }

  void displayDetailed(std::ostream & output = std::cout) {
    using std::endl;

    output << deviceFilename << ": bus " << libevdev_get_id_bustype(dev)
               << " vendor "
               << libevdev_get_id_vendor(dev) << " product "
               << libevdev_get_id_product(dev);

    output << "EvDev version: " << std::hex << evdevVersion << endl;
    output << "Name: " << name << endl;
    output << "Location: " << location << endl;
    output << "UniqueID: " << uniqueID << endl;
  }

  struct libevdev * dev = nullptr;

  const std::string deviceFilename;

  int evdevVersion;
  std::string name;
  std::string location;
  std::string uniqueID;

  DeviceClass getClass() const {
    return deviceClass;
  }

private:
  DeviceClass deviceClass;
};
