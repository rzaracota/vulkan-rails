#ifndef _ubo_header_
#define _ubo_header_

struct UniformBufferObject {
  glm::mat4 model;
  glm::mat4 view;
  glm::mat4 proj;
};

#endif /* end of include guard: _ubo_header_ */
