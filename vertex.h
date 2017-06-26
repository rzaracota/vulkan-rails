#pragma once

struct vector3 {
  double x, y, z;

  friend std::ostream & operator<<(std::ostream & output,
				   const vector3 & that) {
    output << "{ " << that.x << ", " << that.y << ", " << that.z << "}";

    return output;
  }
};

struct vector2 {
  double x, y;
};

struct vertex_t {
  vector3 pos;
  vector3 color;
  vector2 uv;
};
