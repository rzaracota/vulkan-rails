#pragma once

#include "pixy.h"

class Particle : public Pixy {
public:
  Particle(VkDevice dev, std::string filename,
            std::string texPath = "chalet/cube.png", const double life = 1000.0) :
              Pixy(dev, filename, texPath), lifetime(life) {

  }

  ~Particle() {

  }

  void Update() {
    lifetime -= decay;
  }
private:
  static constexpr double decay = 1.0;

  double lifetime;
};
