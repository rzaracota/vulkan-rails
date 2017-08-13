#include "inputmanager.h"

InputManager::InputManager() {
  get_keyboards();
}

InputManager::~InputManager() {

}

bool InputManager::getKeyboardKeyState(KeyConstant key) const {
  if (keyboards.size() < 1) {
    throw std::runtime_error("No keyboards present.");
  }

  return keyboards[0].getKeyState(key);
}

void InputManager::add_keyboard(const Keyboard & newKeyboard) {
  keyboards.push_back(newKeyboard);
}

void InputManager::get_keyboards() {
  Keyboard fakeKeyboard;

  keyboards.push_back(fakeKeyboard);
}

void InputManager::get_mice() {

}
