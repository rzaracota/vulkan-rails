#include "rails.h"

#include "particleengine.h"

#include "ubo.h"

ParticleEngine::ParticleEngine(const std::shared_ptr<VulkanDevice> vDevice,
                               const int initMaxParticles) :
                                  device(vDevice),
                                  maxParticles(initMaxParticles) {

}

ParticleEngine::~ParticleEngine() {

}

void ParticleEngine::setup_buffers() {
    VkDeviceSize bufferSize = sizeof(UniformBufferObject) * maxParticles;

    device->createBuffer(bufferSize, VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT,
		 VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
		 VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
		 uniformBuffer, uniformBufferMemory);
}

void ParticleEngine::initialize_particles() {
  inactiveParticles.clear();
  for (int i = 0; i < maxParticles; i++) {
    inactiveParticles.push_back(std::make_shared<Particle>(device->getLogicalDevice(),
                                "particle" + std::to_string(i)));
  }
}

void ParticleEngine::Init() {
  setup_buffers();
  initialize_particles();
}

void ParticleEngine::Update() {
  std::for_each(activeParticles.begin(), activeParticles.end(),
        [] (auto pair) {
          pair.second->Update();
        });

  std::for_each(activeParticles.begin(), activeParticles.end(),
        [] (auto pair) {
          // setup uniform buffer
        });
}

void ParticleEngine::Spawn(glm::vec3 origin, glm::vec3 velocity) {
  if (!inactiveParticles.empty()) {
    throw std::runtime_error("No more space for particles.");
  }
}
