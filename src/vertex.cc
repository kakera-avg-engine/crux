// Copyright 2021 Drawoceans
#include "include/vertex.h"

crux::Vertex::Vertex(const crux::Coordinate& position_coord)
    : position_coord_(position_coord) {}

crux::Vertex::Vertex(const crux::Coordinate& position_coord,
                     const crux::Coordinate& texture_coord)
    : position_coord_(position_coord),
      texture_coord_(texture_coord) {}

crux::Vertex::Vertex(const crux::Coordinate& position_coord,
                     const crux::Color& color)
    : position_coord_(position_coord),
      color_(color) {}

crux::Vertex::Vertex(const crux::Coordinate& position_coord,
                     const crux::Coordinate& texture_coord,
                     const crux::Color& color)
    : position_coord_(position_coord),
      texture_coord_(texture_coord),
      color_(color) {}

crux::Vertex::Vertex(const crux::Vertex& other)
    : position_coord_(other.position_coord_),
      texture_coord_(other.texture_coord_),
      color_(other.color_) {}

crux::Vertex::Vertex(crux::Vertex&& other) {
  position_coord_ = other.position_coord_;
  texture_coord_ = other.texture_coord_;
  color_ = other.color_;
  other.position_coord_ = Coordinate{};
  other.texture_coord_ = std::nullopt;
  other.color_ = std::nullopt;
}

crux::Vertex& crux::Vertex::operator=(const crux::Vertex& other) {
  if (this != &other) {
    position_coord_ = other.position_coord_;
    texture_coord_ = other.texture_coord_;
    color_ = other.color_;
  }
  return *this;
}

crux::Vertex& crux::Vertex::operator=(crux::Vertex&& other) {
  if (this != &other) {
    position_coord_ = other.position_coord_;
    texture_coord_ = other.texture_coord_;
    color_ = other.color_;
    other.position_coord_ = Coordinate{};
    other.texture_coord_ = std::nullopt;
    other.color_ = std::nullopt;
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
