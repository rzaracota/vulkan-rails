#pragma once

#include "inputmanager.h"

class EVInputManager : public InputManager {
public:
  EVInputManager();
  ~EVInputManager();

private:
    void get_keyboards();
    void get_mice();
};
