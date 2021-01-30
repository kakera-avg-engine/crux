// Copyright 2021 Drawoceans
#include "src/render_queue.h"
#include <stdexcept>
#include <utility>

bool crux::internal::TraitComp::operator()(const uint32_t &lhs,
                                           const uint32_t &rhs) const {
  // 4 bits layer, 8 bits shader, 10 bits texture, 10 bits zero(removed z-index)
  // Shift left to save only layer.
  uint8_t lhs_layer = lhs >> 28;
  uint8_t rhs_layer = rhs >> 28;
  if (lhs_layer == rhs_layer) {
    // Shift right to remove layer, shift left to save only shader.
    uint8_t lhs_shader = (lhs << 4) >> 24;
    uint8_t rhs_shader = (rhs << 4) >> 24;
    if (lhs_shader == rhs_shader) {
      // Shift right to remove layer and shader.
      uint16_t lhs_texture = (lhs << 12) >> 22;
      uint16_t rhs_texture = (rhs << 12) >> 22;
      // Texture ids will never equal.
      return lhs_texture > rhs_texture;
    } else {
      return lhs_shader > rhs_shader;
    }
  } else {
    return lhs_layer > rhs_layer;
  }
}


void crux::internal::RenderQueue::Push(crux::RenderObject *render_object) {
  if (!render_object) {
    throw std::invalid_argument("Null render object.");
  }
  // Remove z-index to get trait.
  uint32_t trait = render_object->sort_index() << 10;
  if (auto iter = render_batches_.find(trait); iter != render_batches_.end()) {
    auto& batch = iter->second;
    batch->Push(render_object);
  } else {
    auto ret = render_batches_.emplace(trait, RenderBatch());
    if (!ret.second) {
      throw std::runtime_error("Cannot create new render batch.");
    } else {
      auto& batch = ret.first->second;
      batch->Push(render_object);
    }
  }
}

std::vector<std::unique_ptr<crux::internal::RenderBatch>>
crux::internal::RenderQueue::render_batches() {
  std::vector<std::unique_ptr<crux::internal::RenderBatch>> ret;
  if (render_batches_.empty()) {
    for (auto& batch : render_batches_) {
      ret.emplace_back(std::move(batch.second));
    }
  }
  render_batches_.clear();
  return ret;
}
