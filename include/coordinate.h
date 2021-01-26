#ifndef CRUX_INCLUDE_COORDINATE_H_
#define CRUX_INCLUDE_COORDINATE_H_

namespace crux {

struct Coordinate {
  union {
    struct { int x, y; };
    struct { int s, t; };
  };
};

} // namespace crux

#endif // CRUX_INCLUDE_COORDINATE_H_