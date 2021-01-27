// Copyright 2021 Drawoceans
#include "include/render_object.h"
#include <stdexcept>

void crux::RenderObject::CheckVerticesAlignment(
    const std::vector<crux::Vertex> &vertices) const {
  if (vertices.empty()) {
    throw std::invalid_argument("Empty vertices array.");
  }
  bool has_texture_coord = false, has_color = false;
  if (vertices[0].texture_coord()) has_texture_coord = true;
  if (vertices[0].color()) has_color = true;
  for (auto& vertex : vertices) {
    bool vertex_has_texture_coord = vertex.texture_coord().has_value();
    bool vertex_has_color = vertex.color().has_value();
    if (vertex_has_texture_coord != has_texture_coord ||
        vertex_has_color != has_color) {
      throw std::invalid_argument("Alignment of vertices is inconsistent.");
    }
  }
}
