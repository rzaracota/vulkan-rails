#include <iostream>

#include "inputmanager.h"

InputManager::InputManager() {
}

InputManager::~InputManager() {
}

void InputManager::Init() {
  get_keyboards();
  get_mice();
}

bool InputManager::getKeyboardKeyState(KeyConstant key) const {
  if (keyboards.size() < 1) {
    throw std::runtime_error("No keyboards present.");
  }

  return keyboards[0].getKeyState(key);
}

void InputManager::add_keyboard(const Keyboard & newKeyboard) {
  keyboards.push_back(newKeyboard);

  std::cout << "keyboard count: " << keyboards.size() << std::endl;
}

void InputManager::get_keyboards() {
  Keyboard fakeKeyboard;

  add_keyboard(fakeKeyboard);
}

void InputManager::get_mice() {

}
