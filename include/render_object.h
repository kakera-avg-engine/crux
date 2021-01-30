// Copyright 2021 Drawoceans
#ifndef INCLUDE_RENDER_OBJECT_H_
#define INCLUDE_RENDER_OBJECT_H_

#include <cstdint>
#include <vector>
#include <memory>
#include "include/shader_program.h"
#include "include/vertex.h"
#include "include/texture.h"

namespace crux {

namespace internal { class RawVertexData; }

class RenderObject {
 public:
  // Order of vertices in the std::vector is renderring order.
  // Available values for layer is 0~15.
  // Available values for z-index is 1~1023, 0 means to create automatically
  // by submit order.
  // Each layer has an independent z-index domain.
  RenderObject(const ShaderProgram& shader_program,
               std::vector<Vertex> vertices, uint8_t layer = 0,
               uint16_t z_index = 0);
  // Renderring order can be customed by index_buffer, just like the EBO in
  // OpenGL.
  // Available values for layer is 0~15.
  // Available values for z-index is 1~1023, 0 means to create automatically
  // by submit order.
  // Each layer has an independent z-index domain.
  RenderObject(const ShaderProgram& shader_program,
               std::vector<Vertex> vertices, std::vector<int> index_buffer,
               uint8_t layer = 0, uint16_t z_index = 0);
  // Order of vertices in the std::vector is renderring order.
  // Available values for layer is 0~15.
  // Available values for z-index is 1~1023, 0 means to create automatically
  // by submit order.
  // Each layer has an independent z-index domain.
  RenderObject(const ShaderProgram& shader_program,
               std::vector<Vertex> vertices, const Texture& texture,
               uint8_t layer = 0, uint16_t z_index = 0);
  // Renderring order can be customed by index_buffer, just like the EBO in
  // OpenGL.
  // Available values for layer is 0~15.
  // Available values for z-index is 1~1023, 0 means to create automatically
  // by submit order.
  // Each layer has an independent z-index domain.
  RenderObject(const ShaderProgram& shader_program,
               std::vector<Vertex> vertices, std::vector<int> index_buffer,
               const Texture& texture, uint8_t layer = 0, uint16_t z_index = 0);
  RenderObject(const RenderObject&) = delete;
  RenderObject& operator=(const RenderObject&) = delete;

  uint32_t sort_index() const;
  VertexAlignment alignment() const;
  internal::RawVertexData* raw_vertex_data() const;

 private:
  static bool CheckVerticesAlignment(const std::vector<Vertex>& vertices);

  const ShaderProgram* shader_program_ = nullptr;
  std::vector<int> index_buffer_;
  const Texture* texture_ = nullptr;
  uint32_t sort_index_ = 0;
  std::unique_ptr<internal::RawVertexData> raw_vertex_data_;
  VertexAlignment alignment_;
};

}  // namespace crux

#endif  // INCLUDE_RENDER_OBJECT_H_
