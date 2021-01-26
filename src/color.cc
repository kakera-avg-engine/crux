#include "color.h"

crux::Color::Color(uint8_t r, uint8_t g, uint8_t b)
    : r_(r), g_(g), b_(b), a_(0) {}

crux::Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
    : r_(r), g_(g), b_(b), a_(a) {}

crux::Color::Color(const crux::Color& other)
    : r_(other.r_), g_(other.g_), b_(other.b_), a_(other.a_) {}

crux::Color::Color(crux::Color&& other) {
  r_ = other.r_;
  g_ = other.g_;
  b_ = other.b_;
  a_ = other.a_;
  other.r_ = 0;
  other.g_ = 0;
  other.b_ = 0;
  other.a_ = 0;
}

crux::Color& crux::Color::operator=(const crux::Color& other) {
  if (this != &other) {
      r_ = other.r_;
      g_ = other.g_;
      b_ = other.b_;
      a_ = other.a_;
    }
    return *this;
}

crux::Color& crux::Color::operator=(crux::Color&& other) {
  if (this != &other) {
    r_ = other.r_;
    g_ = other.g_;
    b_ = other.b_;
    a_ = other.a_;
    other.r_ = 0;
    other.g_ = 0;
    other.b_ = 0;
    other.a_ = 0;
  }
  return *this;
}

std::array<uint8_t, 4> crux::Color::GetColor() const {
  return std::array<uint8_t, 4>{ r_, g_, b_, a_ };
}