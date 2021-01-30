// Copyright 2021 Drawoceans
#ifndef SRC_SORT_INDEX_H_
#define SRC_SORT_INDEX_H_

#include <cstdint>

namespace crux {
namespace internal {

class SortIndex {
 public:
  SortIndex() = default;
  explicit SortIndex(uint32_t index);
  SortIndex(const SortIndex& other);
  SortIndex(SortIndex&& other);
  SortIndex& operator=(const SortIndex& other);
  SortIndex& operator=(SortIndex&& other);

  uint16_t z_index() const;
  void set_z_index(uint16_t z_index);
  uint8_t layer() const;
  void set_layer(uint8_t layer);
  uint8_t shader() const;
  void set_shader(uint8_t shader);
  uint16_t texture() const;
  void set_texture(uint16_t texture);
  uint32_t index() const;

 private:
  // 10 bits for z_index.
  //  4 bits for layer.
  //  8 bits for shader.
  // 10 bits for texture.
  uint32_t index_ = 0;
};

}  // namespace internal
}  // namespace crux

#endif  // SRC_SORT_INDEX_H_
