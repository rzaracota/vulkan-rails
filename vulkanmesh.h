#pragma once

#include <glm/glm.hpp>

struct Mesh {
  Mesh(VkDevice dev, std::string filename,
       std::string texPath = TEXTURE_PATH) : device(dev), path(filename),
					     texturePath(texPath) {
  }

  virtual ~Mesh() {
    std::cout << "Mesh dtor: " << path << std::endl;

    safe_destroy_vk<VkBuffer>(vkDestroyBuffer, device, vertexBuffer, nullptr);
    safe_destroy_vk<VkDeviceMemory>(vkFreeMemory, device,
				    vertexBufferMemory, nullptr);

    safe_destroy_vk<VkBuffer>(vkDestroyBuffer, device, indexBuffer, nullptr);
    safe_destroy_vk<VkDeviceMemory>(vkFreeMemory, device, indexBufferMemory,
				    nullptr);
  }

  bool operator==(const Mesh & that) const {
    return path == that.path;
  }

  friend std::ostream & operator<<(std::ostream & output,
				   const Mesh & mesh) {
    output << "Mesh: " << mesh.path;

    return output;
  }

  void setData(const std::vector<Vertex> & newVertices,
	       const std::vector<uint32_t> & newIndices) {
    vertices = newVertices;
    indices = newIndices;
  }

  VkBuffer vertexBuffer;
  VkDeviceMemory vertexBufferMemory;

  VkBuffer indexBuffer;
  VkDeviceMemory indexBufferMemory;

  std::vector<Vertex> vertices;
  std::vector<uint32_t> indices;

  std::string path;

  VkDescriptorSet descriptorSet;

  std::string texturePath;

  glm::vec3 position;
  glm::vec3 velocity;

  // orientation

private:
  VkDevice device;
};
