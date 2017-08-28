#include <iostream>
#include <algorithm>
#include <memory>

#include <chrono>

#include <thread>

#include "inputmanager.h"

InputManager::InputManager() {
}

InputManager::~InputManager() {
  if (watcher != nullptr) watcher->detach();
}

static void event_thread(InputManager * manager) {
  while (manager != nullptr) {
    manager->handleEvents();
  }
}

void InputManager::Init() {
  get_keyboards();
  get_mice();

  watcher = std::make_shared<std::thread>(event_thread, this);
}

void InputManager::handleEvents() {
  // std::for_each(keyboards.begin(), keyboards.end(), [] (auto keyboard) {
  //   keyboard->handleEvents();
  // });

  // only test with first keyboard

  static auto startTime = std::chrono::high_resolution_clock::now();

  auto currentTime = std::chrono::high_resolution_clock::now();

  auto delta = currentTime - startTime;

  if (std::chrono::duration<double, std::milli>(delta).count() >= 2) {
    keyboards[0]->reinitialize();
    keyboards[0]->handleEvents();

    startTime = currentTime;
  }
}

bool InputManager::getKeyboardKeyState(KeyConstant key) const {
  if (keyboards.size() < 1) {
    throw std::runtime_error("No keyboards present.");
  }

  return keyboards[0]->getKeyState(key);
}

void InputManager::registerCallback(void (*callback)(void * data),
                                    void * data, KeyConstant key) {
  keyboards[0]->registerCallback(callback, data, key);
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
