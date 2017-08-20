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

void ParticleEngine::Init() {
  setup_buffers();
}

void ParticleEngine::Update() {

}
