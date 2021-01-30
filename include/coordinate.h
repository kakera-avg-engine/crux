// Copyright 2021 Drawoceans
#ifndef INCLUDE_COORDINATE_H_
#define INCLUDE_COORDINATE_H_

namespace crux {

struct Coordinate {
  union {
    struct {
      float x, y;
    };
    struct {
      float s, t;
    };
  };
};

}  // namespace crux

#endif  // INCLUDE_COORDINATE_H_
