#pragma once

#include <iostream>

#include <memory>
#include <vector>

#include "vertex.h"

struct TerrainPatch {
public:
  TerrainPatch(const int patchSize = 16, const double patchSpacing = 1.0) :
                 size(patchSize), spacing(patchSpacing) {
    generate();
  }

  void debug_display() const {
    using std::cout;
    using std::endl;

    cout << "Terrain Patch - size: " << size << " spacing: " << spacing <<
      endl;

    cout << "Vertices:" << endl;

    for (auto v : vertices) {
      cout << v.pos << endl;
    }
  }

private:
  static double getHeight(const int x, const int z) {
    double result = 0.0;

    return result;
  }
  
  void generate() {
    const double originZ = -1.0 * (size * spacing / 2.0);
    const double originX = originZ;
    
    for (int j = 0; j < size; j++) {
      for (int i = 0; i < size; i++) {
	vertex_t v;

	v.pos.x = originX + spacing * i;
	v.pos.y = getHeight(i, j);
	v.pos.z = originZ + spacing * j;

	vertices.push_back(v);	
      }
    }
  }

  const int size;
  const double spacing;

  std::vector<vertex_t> vertices;
  std::vector<unsigned int> indices;
};
  

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
