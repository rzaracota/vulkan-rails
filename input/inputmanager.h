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
   virtual ~InputManager();

   void Init();

   bool getKeyboardKeyState(KeyConstant key) const;

 protected:
   void add_keyboard(const Keyboard & keyboard);

  private:
    virtual void get_keyboards();
    virtual void get_mice();

    std::vector<Keyboard> keyboards;

    // consider making a singleton
 };
