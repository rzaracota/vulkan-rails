/**
 * pixy.h - base class for a visible resource on the screen. A pixy will be
 *          a 2D rectangle.
 **/
#pragma once

#include "rails.h"

#include "vulkanmesh.h"

struct Pixy : public Mesh {
  Pixy(VkDevice dev, std::string filename,
       std::string texPath = "chalet/cube.png") : Mesh(dev, filename) {
    generate();
  }

  ~Pixy() {
  }

  bool operator==(const Mesh & that) const {
    return path == that.path;
  }

  friend std::ostream & operator<<(std::ostream & output,
				   const Pixy & pixy) {
    output << "Pixy: " << pixy.path;

    return output;
  }

  void setData(const std::vector<Vertex> & newVertices,
	       const std::vector<uint32_t> & newIndices) {
    vertices = newVertices;
    indices = newIndices;
  }

  void generate() {
    Vertex topLeft, topRight;
    Vertex bottomLeft, bottomRight;

    topLeft.pos.x = -1.0;
    topLeft.pos.z = 1.0;
    topLeft.pos.y = 0.0;

    topLeft.texCoord.x = 0.0;
    topLeft.texCoord.y = 0.0;

    vertices.push_back(topLeft);

    topRight.pos.x = 1.0;
    topRight.pos.z = 1.0;
    topRight.pos.y = 0.0;

    topRight.texCoord.x = 1.0;
    topRight.texCoord.y = 0.0;

    vertices.push_back(topRight);

    bottomLeft.pos.x = -1.0;
    bottomLeft.pos.z = -1.0;
    bottomLeft.pos.y = 0.0;

    bottomLeft.texCoord.x = 0.0;
    bottomLeft.texCoord.y = 1.0;

    vertices.push_back(bottomLeft);

    bottomRight.pos.x = 1.0;
    bottomRight.pos.z = -1.0;
    bottomRight.pos.y = 0.0;

    bottomRight.texCoord.x = 1.0;
    bottomRight.texCoord.y = 1.0;

    vertices.push_back(bottomRight);

    int tl, tr, bl, br;

    tl = 0;
    tr = 1;

    bl = 2;
    br = 3;

    indices.push_back(bl);
    indices.push_back(br);
    indices.push_back(tl);

    indices.push_back(tl);
    indices.push_back(br);
    indices.push_back(tr);
  }
};
