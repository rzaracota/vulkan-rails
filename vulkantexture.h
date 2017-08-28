#pragma once

struct Texture {
  Texture(VkDevice dev, std::string filename) : path(filename),
							device(dev) {
  }

  ~Texture() {
    std::cout << "Destroying texture: " << path << std::endl;

    safe_destroy_vk<VkSampler>(vkDestroySampler, device, sampler, nullptr);

    if (imageView != VK_NULL_HANDLE) {
      vkDestroyImageView(device, imageView, nullptr);
    }

    if (image != VK_NULL_HANDLE) {
      vkDestroyImage(device, image, nullptr);
    }

    if (imageMemory != VK_NULL_HANDLE) {
      vkFreeMemory(device, imageMemory, nullptr);
    }
  }

  uint32_t width, height;

  VkImage image;
  VkImageView imageView;
  VkSampler sampler;
  VkDeviceMemory imageMemory;

  bool operator==(const Texture & that) const {
    std::cout << "operator==" << std::endl;

    return path == that.path;
  }

protected:
  std::string path;

private:
  VkDevice device;
};
