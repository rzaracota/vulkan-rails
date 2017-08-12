#include "keyconstants.h"

#include "inputmanager.h"

#include <exception>

static void keyboardTest(InputManager & manager) {
  for (int i = 0; i < KC_KEY_CONSTANTS_END; i++) {
    if (manager.getKeyboardKeyState(static_cast<KeyConstant>(i)) != false) {
      throw std::runtime_error("Keyboard is not initialized.");
    }
  }
}

int main(int argc, char * argv[]) {
  InputManager inputManager;

  keyboardTest(inputManager);
}
