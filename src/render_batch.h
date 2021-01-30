// Copyright 2021 Drawoceans
#ifndef SRC_RENDER_BATCH_H_
#define SRC_RENDER_BATCH_H_

#include <cstdint>
#include <vector>
#include "include/render_object.h"
#include "src/sort_index.h"

namespace crux {
namespace internal {

class RenderBatch {
 public:
  RenderBatch() = default;
  RenderBatch(const RenderBatch& other) = delete;
  RenderBatch& operator=(const RenderBatch& other) = delete;

  const std::vector<RenderObject*>& render_objects();

  void Push(RenderObject* render_object);

 private:
  void ResortObjects();
  std::vector<RenderObject*> render_objects_;
};

}  // namespace internal
}  // namespace crux

#endif  // SRC_RENDER_BATCH_H_
