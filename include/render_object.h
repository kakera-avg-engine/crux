#ifndef CRUX_INCLUDE_RENDER_OBJECT_H_
#define CRUX_INCLUDE_RENDER_OBJECT_H_

#include <vector>
#include <optional>
#include "shader_program.h"
#include "vertex.h"
#include "texture.h"

namespace crux {

class RenderObject {
 public:
  // Order of vertices in the std::vector is renderring order.
  RenderObject(const ShaderProgram& shader_program,
               std::vector<Vertex> vertices);
  // Renderring order can be customed by index_buffer, just like EBO in OpenGL.
  RenderObject(const ShaderProgram& shader_program, 
               std::vector<Vertex> vertices, std::vector<int> index_buffer);
  // Order of vertices in the std::vector is renderring order.
  RenderObject(const ShaderProgram& shader_program,
               std::vector<Vertex> vertices, const Texture& texture);
  // Renderring order can be customed by index_buffer, just like EBO in OpenGL.
  RenderObject(const ShaderProgram& shader_program,
               std::vector<Vertex> vertices, std::vector<int> index_buffer,
               const Texture& texture);

 private:
  ShaderProgram* shader_program_ = nullptr;
  std::vector<Vertex> vertices_;
  std::optional<std::vector<int>> index_buffer_;
  Texture* texture_;
};

} // namespace crux

#endif // CRUX_INCLUDE_RENDER_OBJECT_H_