// Copyright 2021 Drawoceans
#include "src/sort_index.h"
#include <stdexcept>

crux::internal::SortIndex::SortIndex(uint32_t index) : index_(index) {}

crux::internal::SortIndex::SortIndex(const crux::internal::SortIndex &other)
    : index_(other.index_) {}

crux::internal::SortIndex::SortIndex(crux::internal::SortIndex &&other) {
  index_ = other.index_;
  other.index_ = 0;
}

crux::internal::SortIndex &crux::internal::SortIndex::operator=(
    const crux::internal::SortIndex &other) {
  if (this != &other) {
    index_ = other.index_;
  }
  return *this;
}

crux::internal::SortIndex &crux::internal::SortIndex::operator=(
    crux::internal::SortIndex &&other) {
  if (this != &other) {
    index_ = other.index_;
    other.index_ = 0;
  }
  return *this;
}

uint16_t crux::internal::SortIndex::z_index() const {
  return uint16_t(index_ >> 22);
}

void crux::internal::SortIndex::set_z_index(uint16_t z_index) {
  if (z_index > 1023) {
    throw std::invalid_argument("Z-index is too big.");
  }
  // Magic number to clear z-index.
  // 10bits 0 and 22 bits 1.
  index_ &= 0x3fffffu;
  // Move z-index to high 10 bits.
  index_ |= (static_cast<uint32_t>(z_index) << 22);
}

uint8_t crux::internal::SortIndex::layer() const {
  return uint8_t((index_ << 10) >> 28);
}

void crux::internal::SortIndex::set_layer(uint8_t layer) {
  if (layer > 15) {
    throw std::invalid_argument("Layer is too big.");
  }
  // Magic number to clear layer.
  // 10bits 1, 4bits 0, and 18 bits 1.
  index_ &= 0xffc3ffffu;
  // Move z-index to 11-14 bits.
  index_ |= (static_cast<uint32_t>(layer) << 18);
}

uint8_t crux::internal::SortIndex::shader() const {
  return uint8_t((index_ << 14) >> 24);
}

void crux::internal::SortIndex::set_shader(uint8_t shader) {
  // Magic number to clear shader.
  // 14bits 1, 8bits 0, and 10 bits 1.
  index_ &= 0xfffc03ffu;
  // Move z-index to 11-14 bits.
  index_ |= (static_cast<uint32_t>(shader) << 10);
}

uint16_t crux::internal::SortIndex::texture() const {
  // Magic number to save low 10 bits.
  // 22 bits 0 and 10 bits 1.
  return uint16_t(index_ & 0x3ffu);
}

void crux::internal::SortIndex::set_texture(uint16_t texture) {
  if (texture > 1023) {
    throw std::invalid_argument("Texture is too big.");
  }
  // Magic number to clear texture.
  // 22 bits 1 and 10 bits 0.
  index_ &= 0xfffffc00u;
  index_ |= static_cast<uint32_t>(texture);
}

uint32_t crux::internal::SortIndex::index() const {
  return index_;
}
