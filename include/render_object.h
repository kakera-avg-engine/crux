// Copyright 2021 Drawoceans
#ifndef INCLUDE_RENDER_OBJECT_H_
#define INCLUDE_RENDER_OBJECT_H_

#include <cstdint>
#include <vector>
#include "include/shader_program.h"
#include "include/vertex.h"
#include "include/texture.h"

namespace crux {

class RenderObject {
 public:
  // Order of vertices in the std::vector is renderring order.
  RenderObject(const ShaderProgram& shader_program,
               std::vector<Vertex> vertices, uint8_t layer = 0);
  // Renderring order can be customed by index_buffer, just like the EBO in
  // OpenGL.
  RenderObject(const ShaderProgram& shader_program,
               std::vector<Vertex> vertices, std::vector<int> index_buffer,
               uint8_t layer = 0);
  // Order of vertices in the std::vector is renderring order.
  RenderObject(const ShaderProgram& shader_program,
               std::vector<Vertex> vertices, const Texture& texture,
               uint8_t layer = 0);
  // Renderring order can be customed by index_buffer, just like the EBO in
  // OpenGL.
  RenderObject(const ShaderProgram& shader_program,
               std::vector<Vertex> vertices, std::vector<int> index_buffer,
               const Texture& texture, uint8_t layer = 0);
  RenderObject(const RenderObject&) = delete;
  RenderObject& operator=(const RenderObject&) = delete;

  uint32_t sort_index() const;

 private:
  void CheckVerticesAlignment(const std::vector<Vertex>& vertices) const;
  void CalcSortIndex();

  ShaderProgram* shader_program_ = nullptr;
  std::vector<Vertex> vertices_;
  std::vector<int> index_buffer_;
  Texture* texture_ = nullptr;
  uint32_t sort_index_ = 0;
};

}  // namespace crux

#endif  // INCLUDE_RENDER_OBJECT_H_
