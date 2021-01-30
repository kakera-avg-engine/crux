// Copyright 2021 Drawoceans
#ifndef SRC_RENDER_QUEUE_H_
#define SRC_RENDER_QUEUE_H_

#include <cstdint>
#include <map>
#include <vector>
#include <memory>
#include "include/render_object.h"
#include "src/render_batch.h"
#include "src/sort_index.h"

namespace crux {
namespace internal {

// Compare batches.
// First, compare layer.
// Then, compare shader.
// No need to compare texture.
// Ensure the render order and minimize the graphic overload.
class TraitComp {
 public:
  bool operator()(const uint32_t& lhs, const uint32_t& rhs) const;
};

class RenderQueue {
 public:
  RenderQueue() = default;
  RenderQueue(const RenderQueue&) = delete;
  RenderQueue& operator=(const RenderQueue&) = delete;

  void Push(RenderObject* render_object);
  // Will clear the queue.
  std::vector<std::unique_ptr<RenderBatch>> render_batches();

 private:
  // uint32_t saves the trait of a render batch.
  // If the values except z-index of two sort indexes is same, they have the
  // same trait.
  // Only auto z-index render objects can be batched.
  std::map<uint32_t, std::unique_ptr<RenderBatch>, TraitComp> render_batches_;
};

}  // namespace internal
}  // namespace crux

#endif  // SRC_RENDER_QUEUE_H_
