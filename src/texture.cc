// Copyright 2021 Drawoceans
#include "include/texture.h"

int crux::Texture::texture_count_ = 1;

crux::Texture::Texture() {
  if (texture_count_ > 1023) {
    throw std::runtime_error("Too much textures.");
  }
  texture_id_ = texture_count_;
  texture_count_++;
}

uint16_t crux::Texture::texture_id() const {
  return texture_id_;
}

crux::Texture::operator bool() const {
  return texture_id_ > 0;
}
