#pragma once

#include "graphicsdevice.h"

class VulkanDevice : public GraphicsDevice {
public:
  VulkanDevice(VkDevice vulkanDevice, VkPhysicalDevice physDevice);

  ~VulkanDevice();

  uint32_t findMemoryType(uint32_t typeFilter,
			  VkMemoryPropertyFlags properties);

  void createBuffer(VkDeviceSize size, VkBufferUsageFlags usage,
		    VkMemoryPropertyFlags properties, VkBuffer& buffer,
		    VkDeviceMemory& bufferMemory);

private:
  VkDevice device;
  VkPhysicalDevice physicalDevice;
};
