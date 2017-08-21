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

int ParticleEngine::getUniformBufferSize() const {
  return uniformBufferSize;
}

void ParticleEngine::setup_buffers() {
    VkDeviceSize bufferSize = sizeof(UniformBufferObject) * maxParticles;

    uniformBufferSize = sizeof (UniformBufferObject) * maxParticles;

    device->createBuffer(bufferSize, VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT,
		 VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
		 VK_MEMORY_PROPERTY_HOST_COHERENT_BIT,
		 uniformBuffer, uniformBufferMemory);
}

void ParticleEngine::initialize_particles() {
  inactiveParticles.clear();
  activeParticles.clear();

  for (int i = 0; i < maxParticles; i++) {
    auto particle = std::make_shared<Particle>(device->getLogicalDevice(),
                                "particle" + std::to_string(i));
    inactiveParticles.push_back(particle);
  }
}

void ParticleEngine::Init() {
  setup_buffers();
  initialize_particles();
}

void ParticleEngine::Update() {
  for (auto iter = activeParticles.begin();
        iter != activeParticles.end();) {
    if (iter->second->lifetime < 0.0) {
      std::cout << "Particle is dying: " << iter->second->path;

      inactiveParticles.push_back(iter->second);

      iter = activeParticles.erase(iter);
    } else {
      iter->second->Update();

      iter++;
    }
  }

  std::for_each(activeParticles.begin(), activeParticles.end(),
        [] (auto pair) {
          // setup uniform buffer
        });
}

void ParticleEngine::Spawn(glm::vec3 origin, glm::vec3 velocity) {
  if (inactiveParticles.empty()) {
    throw std::runtime_error("No more space for particles.");
  }

  auto p = inactiveParticles.front();

  p->position = origin;
  p->velocity = velocity;

  activeParticles.insert({ p->id, p });

  inactiveParticles.pop_front();
}
