// Copyright 2021 Drawoceans
#ifndef INCLUDE_VERTEX_H_
#define INCLUDE_VERTEX_H_

#include <cstdint>
#include <optional>
#include "include/coordinate.h"
#include "include/color.h"

namespace crux {

enum VertexAlignment : uint8_t {
  kPositionOnly = 0,
  kHasTexture = 0xf0u,
  kHasColor = 0xfu,
  kHasColorAndTexture = 0xffu
};

class Vertex {
 public:
  explicit Vertex(const Coordinate& position_coord);
  Vertex(const Coordinate& position_coord, const Coordinate& texture_coord);
  Vertex(const Coordinate& position_coord, const Color& color);
  Vertex(const Coordinate& position_coord, const Coordinate& texture_coord,
         const Color& color);
  Vertex(const Vertex& other);
  Vertex(Vertex&& other);
  Vertex& operator=(const Vertex& other);
  Vertex& operator=(Vertex&& other);

  Coordinate position_coord() const;
  std::optional<Coordinate> texture_coord() const;
  std::optional<Color> color() const;
  VertexAlignment alignment() const;

 private:
  Coordinate position_coord_;
  std::optional<Coordinate> texture_coord_;
  std::optional<Color> color_;
  VertexAlignment alignment_;
};

}  // namespace crux

#endif  // INCLUDE_VERTEX_H_
