/**
 * keyboard.h - a keyboard will hold state information about a single keyboard.
 *              This will be the superclass of specialized keyboards such as
 *              evdev, xlib, or win32
 **/
#pragma once

#include <iostream>

#include <unordered_map>

#include "keyconstants.h"

struct Callback {
  Callback() {}
  
  Callback(void (*callback)(void *cbData),
           void * dataPtr) : data(dataPtr) {

  }

  void operator()() {
    if (callback != nullptr) {
      callback(data);
    }
  }

  void * data;
  void (*callback)(void*);
};

class Keyboard {
public:
  Keyboard() {
    reinitialize();
  }

  ~Keyboard() {

  }

  virtual void handleEvents() {
  }

  bool getKeyState(KeyConstant key) const {
    if (key < 0 || key > KC_KEY_CONSTANTS_END) {
      throw std::runtime_error("Invalid key specified: " + key);
    }

    return keys.at(key);
  }

  void registerCallback(void (*callback)(void * data), void * data,
                        KeyConstant key) {
    Callback cb(callback, data);

    callbacks.insert({ key,  cb });
  }

  void setKey(KeyConstant key, bool state) {
    keys[key] = state;

    if (state == false && callbacks.find(key) != callbacks.cend()) {
      callbacks[key]();
    }
  }

  void reinitialize() {
    for (int i = 0; i < KC_KEY_CONSTANTS_END; i++) {
      keys[i] = false;
    }
  }

private:
  std::unordered_map<int, bool> keys;
  std::unordered_map<KeyConstant, Callback> callbacks;
};
