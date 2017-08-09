/**
 * pixy.h - base class for a visible resource on the screen. A pixy will be
 *          a 2D rectangle.
 **/
#pragma once

struct Pixy {
  Pixy(VkDevice dev, std::string filename,
       std::string texPath = TEXTURE_PATH) : device(dev), path(filename),
					     texturePath(texPath) {
  }

  ~Pixy() {
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
				   const Pixy & pixy) {
    output << "Pixy: " << pixy.path;

    return output;
  }

  void setData(const std::vector<Vertex> & newVertices,
	       const std::vector<uint32_t> & newIndices) {
    vertices = newVertices;
    indices = newIndices;
  }

  void generate() {
    Vertex topLeft, topRight;
    Vertex bottomLeft, bottomRight;

    topLeft.pos.x = 0.0;
    topLeft.pos.z = 0.0;
    topLeft.pos.y = 0.0;

    topLeft.texCoord.x = 1.0;
    topLeft.texCoord.y = 1.0;

    vertices.push_back(topLeft);

    int tl, tr, bl, br;

    tl = 0;
    tr = tl + 1;

    bl = tr + 1;
    br = bl + 1;

    indices.push_back(tl);
    indices.push_back(bl);
    indices.push_back(br);

    indices.push_back(br);
    indices.push_back(tr);
    indices.push_back(tl);
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

private:
  VkDevice device;
};
