// Copyright 2021 Drawoceans
#ifndef INCLUDE_COLOR_H_
#define INCLUDE_COLOR_H_

#include <cstdint>
#include <array>

namespace crux {

class Color {
 public:
  Color() = default;
  Color(uint8_t r, uint8_t g, uint8_t b);
  Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
  Color(const Color& other);
  Color(Color&& other);

  Color& operator=(const Color& other);
  Color& operator=(Color&& other);
  // Order is r g b a.
  std::array<uint8_t, 4> GetColor() const;
 private:
  uint8_t r_ = 0;
  uint8_t g_ = 0;
  uint8_t b_ = 0;
  uint8_t a_ = 0;
};

}  // namespace crux

#endif  // INCLUDE_COLOR_H_
