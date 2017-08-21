#pragma once

#include "rails.h"

#include "pixy.h"

class Particle : public Pixy {
public:
  Particle(VkDevice dev, std::string filename,
            std::string texPath = "chalet/cube.png", const double life = 1000.0) :
              Pixy(dev, filename, texPath), lifetime(life), alive(true) {
                static int idSeed = 0;

                id = idSeed++;

                std::cout << "Particle spawned" << std::endl;
  }

  ~Particle() {

  }

  void Update() {
    std::cout << "Updating particle: " << path << std::endl;

    lifetime -= decay;

    if (lifetime < 0.0) alive = false;

    position += velocity;
  }

  inline bool isAlive() const { return alive; }

  static constexpr double decay = 0.1;

  double lifetime;

  int id;
private:
  bool alive;
};
