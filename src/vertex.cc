// Copyright 2021 Drawoceans
#include "include/vertex.h"

crux::Vertex::Vertex(const crux::Coordinate& position_coord)
    : position_coord_(position_coord),
      alignment_(VertexAlignment::kPositionOnly) {}

crux::Vertex::Vertex(const crux::Coordinate& position_coord,
                     const crux::Coordinate& texture_coord)
    : position_coord_(position_coord),
      texture_coord_(texture_coord),
      alignment_(VertexAlignment::kHasTexture) {}

crux::Vertex::Vertex(const crux::Coordinate& position_coord,
                     const crux::Color& color)
    : position_coord_(position_coord),
      color_(color),
      alignment_(VertexAlignment::kHasColor) {}

crux::Vertex::Vertex(const crux::Coordinate& position_coord,
                     const crux::Coordinate& texture_coord,
                     const crux::Color& color)
    : position_coord_(position_coord),
      texture_coord_(texture_coord),
      color_(color),
      alignment_(VertexAlignment::kHasColorAndTexture) {}

crux::Vertex::Vertex(const crux::Vertex& other)
    : position_coord_(other.position_coord_),
      texture_coord_(other.texture_coord_),
      color_(other.color_),
      alignment_(other.alignment_) {}

crux::Vertex::Vertex(crux::Vertex&& other) {
  position_coord_ = other.position_coord_;
  texture_coord_ = other.texture_coord_;
  color_ = other.color_;
  alignment_ = other.alignment_;
  other.position_coord_ = Coordinate{};
  other.texture_coord_ = std::nullopt;
  other.color_ = std::nullopt;
  other.alignment_ = VertexAlignment::kPositionOnly;
}

crux::Vertex& crux::Vertex::operator=(const crux::Vertex& other) {
  if (this != &other) {
    position_coord_ = other.position_coord_;
    texture_coord_ = other.texture_coord_;
    color_ = other.color_;
    alignment_ = other.alignment_;
  }
  return *this;
}

crux::Vertex& crux::Vertex::operator=(crux::Vertex&& other) {
  if (this != &other) {
    position_coord_ = other.position_coord_;
    texture_coord_ = other.texture_coord_;
    color_ = other.color_;
    alignment_ = other.alignment_;
    other.position_coord_ = Coordinate{};
    other.texture_coord_ = std::nullopt;
    other.color_ = std::nullopt;
    other.alignment_ = VertexAlignment::kPositionOnly;
  }
  return *this;
}

crux::Coordinate crux::Vertex::position_coord() const {
  return position_coord_;
}

std::optional<crux::Coordinate> crux::Vertex::texture_coord() const {
  return texture_coord_;
}

std::optional<crux::Color> crux::Vertex::color() const {
  return color_;
}

crux::VertexAlignment crux::Vertex::alignment() const {
  return alignment_;
}
