/**
 * inputmanager.h - Manager for all inputs for all players.
 **/
 #pragma once

#include <exception>
#include <vector>

#include "keyboard.h"

/**
 * DeviceClass - type of device
 **/
typedef enum _DeviceClass {
  DC_Keyboard,
  DC_Mouse,
  DC_Gamepad,
  DC_Unknown
} DeviceClass;

static const std::string device_class_names[] = {
  "Keyboard",
  "Mouse",
  "Gamepad",
  "Unknown"
};

class InputManager {
  public:
   InputManager();
   virtual ~InputManager();

   void Init();

   bool getKeyboardKeyState(KeyConstant key) const;
   
   static std::string DeviceClassNames(DeviceClass & cl) {
      return device_class_names[cl];
   }

 protected:
   void add_keyboard(const Keyboard & keyboard);

  private:
    virtual void get_keyboards();
    virtual void get_mice();

    std::vector<Keyboard> keyboards;

    // consider making a singleton
 };
