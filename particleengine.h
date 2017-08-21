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

  std::deque<std::shared_ptr<Particle>> getParticles() const {
    return inactiveParticles;
  }

  std::unordered_map<int, std::shared_ptr<Particle>> getActiveParticles() {
    return activeParticles;
  }

  int getUniformBufferSize() const;

private:
  void setup_buffers();
  void initialize_particles();

  std::deque<std::shared_ptr<Particle>> inactiveParticles;
  std::unordered_map<int,std::shared_ptr<Particle>> activeParticles;

  int maxParticles;

public:
  VkBuffer uniformBuffer;

  VkDeviceMemory uniformBufferMemory;

private:
  int uniformBufferSize;

  const std::shared_ptr<VulkanDevice> device;
};
