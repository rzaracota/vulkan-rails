#version 450
#extension GL_ARB_separate_shader_objects : enable

struct ubo {
  mat4 model;
  mat4 view;
  mat4 proj;
};

layout (binding = 0) uniform UniformBufferObject {
  ubo ubos[2];
};

layout(location = 0) in vec3 inPosition;
layout(location = 1) in vec3 inColor;
layout(location = 2) in vec2 inTexCoord;

layout(location = 0) out vec3 fragColor;
layout(location = 1) out vec2 fragTexCoord;

void main() {
  float scale = 0.25;
     
  gl_Position = ubos[gl_InstanceIndex].proj * ubos[gl_InstanceIndex].view *
  ubos[gl_InstanceIndex].model * mat4(mat3(scale)) * vec4(inPosition, 1.0);

  fragColor = inColor;
  fragTexCoord = inTexCoord;
}