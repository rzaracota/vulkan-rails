/**
 * inputmanager.h - Manager for all inputs for all players.
 **/
 #pragma once

#include <exception>
#include <vector>

#include "keyboard.h"

class InputManager {
  public:
   InputManager();
   ~InputManager();

   bool getKeyboardKeyState(KeyConstant key) const;
  private:
    void get_keyboards();
    void get_mice();

    std::vector<Keyboard> keyboards;

    // consider making a singleton
 };
