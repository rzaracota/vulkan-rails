#pragma once

#include <memory>

#include <unordered_map>

#include "rails.h"

#include "particle.h"


class ParticleEngine {
public:
  ParticleEngine(const int initMaxParticles = 100);
  ~ParticleEngine();

  void Init();

  void Update();
private:
  void setup_buffers();

  std::unordered_map<int,std::shared_ptr<Particle>> activeParticles;
  std::unordered_map<int,std::shared_ptr<Particle>> inactiveParticles;

  int maxParticles;
private: // vulkan
  VkBuffer uniformBuffer;
  VkDeviceMemory uniformBufferMemory;
};
