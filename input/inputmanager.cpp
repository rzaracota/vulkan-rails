#include <iostream>
#include <algorithm>

#include "inputmanager.h"

InputManager::InputManager() {
}

InputManager::~InputManager() {
}

void InputManager::Init() {
  get_keyboards();
  get_mice();
}

void InputManager::handleEvents() {
  std::for_each(keyboards.begin(), keyboards.end(), [] (auto keyboard) {
    keyboard->handleEvents();
  });
}

bool InputManager::getKeyboardKeyState(KeyConstant key) const {
  if (keyboards.size() < 1) {
    throw std::runtime_error("No keyboards present.");
  }
  
  return keyboards[0]->getKeyState(key);
}

void InputManager::add_keyboard(const std::shared_ptr<Keyboard> newKeyboard) {
  keyboards.push_back(newKeyboard);

  std::cout << "keyboard count: " << keyboards.size() << std::endl;
}

void InputManager::get_keyboards() {
  Keyboard keyboard;

  add_keyboard(std::make_shared<Keyboard>(keyboard));
}

void InputManager::get_mice() {

}
