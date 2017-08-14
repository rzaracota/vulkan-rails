#include "keyconstants.h"

#include "inputmanager.h"

#include "evdevinputmanager.h"

#include <exception>

static void keyboardTest(InputManager & manager) {
  for (int i = 0; i < KC_KEY_CONSTANTS_END; i++) {
    if (manager.getKeyboardKeyState(static_cast<KeyConstant>(i)) != false) {
      throw std::runtime_error("Keyboard is not initialized.");
    }
  }

  int done = false;

  while (done == false) {
    done = manager.getKeyboardKeyState(KC_Escape);
  }
}

int main(int argc, char * argv[]) {
  EVInputManager evManager;

  evManager.Init();

  keyboardTest(evManager);
}
