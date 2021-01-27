// Copyright 2021 Drawoceans
#ifndef INCLUDE_COORDINATE_H_
#define INCLUDE_COORDINATE_H_

namespace crux {

struct Coordinate {
  union {
    struct {
      int x, y;
    };
    struct {
      int s, t;
    };
  };
};

}  // namespace crux

#endif  // INCLUDE_COORDINATE_H_
