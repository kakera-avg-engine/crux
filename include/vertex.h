#ifndef CRUX_INCLUDE_VERTEX_H_
#define CRUX_INCLUDE_VERTEX_H_

#include <optional>
#include "coordinate.h"
#include "color.h"

namespace crux {

class Vertex {
 public:
  explicit Vertex(const Coordinate& position_coord);
  Vertex(const Coordinate& position_coord, const Coordinate& texture_coord);
  Vertex(const Coordinate& position_coord, const Color& color);
  Vertex(const Coordinate& position_coord, const Coordinate& texture_coord,
         const Color& color);

  Coordinate position_coord() const;
  std::optional<Coordinate> texture_coord() const;
  std::optional<Color> color() const;

 private:
  Coordinate position_coord_;
  std::optional<Coordinate> texture_coord_;
  std::optional<Color> color_;
};

} // namespace

#endif // CRUX_INCLUDE_VERTEX_H_