#include "evdevinputmanager.h"

EVInputManager::EVInputManager() {
  get_keyboards();
}

EVInputManager::~EVInputManager() {

}

void EVInputManager::get_keyboards() {
  Keyboard fakeKeyboard;

  add_keyboard(fakeKeyboard);
}

void EVInputManager::get_mice() {

}
