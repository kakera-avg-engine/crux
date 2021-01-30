// Copyright 2021 Drawoceans
#include "include/render_object.h"
#include <stdexcept>
#include "src/sort_index.h"
#include "src/raw_vertex.h"

crux::RenderObject::RenderObject(const crux::ShaderProgram &shader_program,
                                 std::vector<crux::Vertex> vertices,
                                 uint8_t layer, uint16_t z_index) {
  if (!shader_program) {
    throw std::invalid_argument("Null shader program.");
  }
  shader_program_ = &shader_program;
  if (vertices.empty()) {
    throw std::invalid_argument("No vertex is passed.");
  }
  if (!CheckVerticesAlignment(vertices)) {
    throw std::invalid_argument("Alignment of vertices is inconsistent.");
  }
  alignment_ = vertices[0].alignment();
  raw_vertex_data_ = std::make_unique<internal::RawVertexData>(vertices);
  if (layer > 15 || z_index > 1023) {
    throw std::domain_error("Layer or z-index is too big.");
  }
  internal::SortIndex sort_index;
  sort_index.set_layer(layer);
  sort_index.set_z_index(z_index);
  sort_index.set_shader(shader_program.program_id());
  sort_index.set_texture(0);
  sort_index_ = sort_index.index();
}

crux::RenderObject::RenderObject(const crux::ShaderProgram &shader_program,
                                 std::vector<crux::Vertex> vertices,
                                 std::vector<int> index_buffer, uint8_t layer,
                                 uint16_t z_index) {
  if (!shader_program) {
    throw std::invalid_argument("Null shader program.");
  }
  shader_program_ = &shader_program;
  if (vertices.empty()) {
    throw std::invalid_argument("No vertex is passed.");
  }
  if (!CheckVerticesAlignment(vertices)) {
    throw std::invalid_argument("Alignment of vertices is inconsistent.");
  }
  alignment_ = vertices[0].alignment();
  raw_vertex_data_ = std::make_unique<internal::RawVertexData>(vertices);
  if (index_buffer.empty()) {
    throw std::invalid_argument("Null index buffer.");
  }
  index_buffer_ = index_buffer;
  if (layer > 15 || z_index > 1023) {
    throw std::domain_error("Layer or z-index is too big.");
  }
  internal::SortIndex sort_index;
  sort_index.set_layer(layer);
  sort_index.set_z_index(z_index);
  sort_index.set_shader(shader_program.program_id());
  sort_index.set_texture(0);
  sort_index_ = sort_index.index();
}

crux::RenderObject::RenderObject(const crux::ShaderProgram &shader_program,
                                 std::vector<crux::Vertex> vertices,
                                 const crux::Texture &texture, uint8_t layer,
                                 uint16_t z_index) {
  if (!shader_program) {
    throw std::invalid_argument("Null shader program.");
  }
  shader_program_ = &shader_program;
  if (vertices.empty()) {
    throw std::invalid_argument("No vertex is passed.");
  }
  if (!CheckVerticesAlignment(vertices)) {
    throw std::invalid_argument("Alignment of vertices is inconsistent.");
  }
  alignment_ = vertices[0].alignment();
  raw_vertex_data_ = std::make_unique<internal::RawVertexData>(vertices);
  if (!texture) {
    throw std::invalid_argument("Null texture.");
  }
  texture_ = &texture;
  if (layer > 15 || z_index > 1023) {
    throw std::domain_error("Layer or z-index is too big.");
  }
  internal::SortIndex sort_index;
  sort_index.set_layer(layer);
  sort_index.set_z_index(z_index);
  sort_index.set_shader(shader_program.program_id());
  sort_index.set_texture(texture.texture_id());
  sort_index_ = sort_index.index();
}

crux::RenderObject::RenderObject(const crux::ShaderProgram &shader_program,
                                 std::vector<crux::Vertex> vertices,
                                 std::vector<int> index_buffer,
                                 const crux::Texture &texture, uint8_t layer,
                                 uint16_t z_index) {
  if (!shader_program) {
    throw std::invalid_argument("Null shader program.");
  }
  shader_program_ = &shader_program;
  if (vertices.empty()) {
    throw std::invalid_argument("No vertex is passed.");
  }
  if (!CheckVerticesAlignment(vertices)) {
    throw std::invalid_argument("Alignment of vertices is inconsistent.");
  }
  alignment_ = vertices[0].alignment();
  raw_vertex_data_ = std::make_unique<internal::RawVertexData>(vertices);
  if (index_buffer.empty()) {
    throw std::invalid_argument("Null index buffer.");
  }
  index_buffer_ = index_buffer;
  if (!texture) {
    throw std::invalid_argument("Null texture.");
  }
  texture_ = &texture;
  if (layer > 15 || z_index > 1023) {
    throw std::domain_error("Layer or z-index is too big.");
  }
  internal::SortIndex sort_index;
  sort_index.set_layer(layer);
  sort_index.set_z_index(z_index);
  sort_index.set_shader(shader_program.program_id());
  sort_index.set_texture(texture.texture_id());
  sort_index_ = sort_index.index();
}

uint32_t crux::RenderObject::sort_index() const {
  return sort_index_;
}

crux::VertexAlignment crux::RenderObject::alignment() const {
  return alignment_;
}

crux::internal::RawVertexData* crux::RenderObject::raw_vertex_data() const {
  return raw_vertex_data_.get();
}

bool crux::RenderObject::CheckVerticesAlignment(
    const std::vector<crux::Vertex> &vertices) {
  VertexAlignment alignment = vertices[0].alignment();
  for (size_t i = 1; i < vertices.size(); i++) {
    if (vertices[i].alignment() != alignment) {
      return false;
    }
  }
  return true;
}
