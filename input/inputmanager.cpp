#include "inputmanager.h"

InputManager::InputManager() {

}

InputManager::~InputManager() {

}

bool InputManager::getKeyboardKeyState(KeyConstant key) const {
  if (keyboards.size() < 1) {
    throw std::runtime_error("No keyboards present.");
  }

  return true;
}

void InputManager::get_keyboards() {
}

void InputManager::get_mice() {

}
