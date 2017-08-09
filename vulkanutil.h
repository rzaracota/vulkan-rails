#pragma once

template <typename handleType>
static inline bool safe_destroy_vk(void (*func)(VkDevice, handleType,
						const VkAllocationCallbacks *),
				   VkDevice dev, handleType obj,
				   VkAllocationCallbacks * param) {
  if (func == nullptr) {
    throw std::runtime_error("invalid destroy func");
  } else if (obj == VK_NULL_HANDLE) {
    std::cerr << "safe_destroy: invalid null handle" << std::endl;
  } else {
    func(dev, obj, param);
  }
}
