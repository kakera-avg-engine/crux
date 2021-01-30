// Copyright 2021 Drawoceans
#ifndef INCLUDE_TEXTURE_H_
#define INCLUDE_TEXTURE_H_

#include <cstdint>
#include <stdexcept>

namespace crux {

class Texture {
 public:
  Texture();

  uint16_t texture_id() const;
  operator bool() const;

 private:
  uint16_t texture_id_ = 0;
  static int texture_count_;
};

}  // namespace crux

#endif  // INCLUDE_TEXTURE_H_
