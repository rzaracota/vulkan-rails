#pragma once

#include "inputmanager.h"

class EVInputManager : public InputManager {
public:
  EVInputManager();
  ~EVInputManager();

private:
    void get_keyboards() override;
    void get_mice() override;
};
