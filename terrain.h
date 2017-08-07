#pragma once

#include <iostream>

#include <memory>
#include <vector>

#include "vertex.h"

class TerrainGenerator {
  TerrainGenerator() {}
  ~TerrainGenerator() {}

 private:
  std::shared_ptr<TerrainPatch>
    generatePatch(const int size = 16, const double spacing = 4.0) const {
    auto result = std::shared_ptr<TerrainPatch>(new TerrainPatch(size,
								 spacing));

    return result;
  }
};

int test_terrain() {
  TerrainPatch patch;

  patch.debug_display();
}
