#pragma once

#include <memory>

#include <unordered_map>

#include "rails.h"

#include "vulkandevice.h"

#include "particle.h"


class ParticleEngine {
public:
  ParticleEngine(const std::shared_ptr<VulkanDevice> inDevice,
                 const int initMaxParticles = 100);
  ~ParticleEngine();

  void Init();

  void Update();

  void Spawn(glm::vec3 origin, glm::vec3 velocity);

private:
  void setup_buffers();
  void initialize_particles();

  std::unordered_map<int,std::shared_ptr<Particle>> activeParticles;
  std::deque<std::shared_ptr<Particle>> inactiveParticles;

  int maxParticles;
private: // vulkan
  VkBuffer uniformBuffer;
  VkDeviceMemory uniformBufferMemory;

  const std::shared_ptr<VulkanDevice> device;
};
