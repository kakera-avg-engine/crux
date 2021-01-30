// Copyright 2021 Drawoceans
#include "src/render_batch.h"
#include <stdexcept>

const std::vector<crux::RenderObject*>&
crux::internal::RenderBatch::render_objects() {
  ResortObjects();
  return render_objects_;
}

void crux::internal::RenderBatch::Push(crux::RenderObject* render_object) {
  if (!render_objects_.empty()) {
    if (render_object->alignment() != render_objects_.back()->alignment()) {
      throw std::invalid_argument("Inconsistent vertex alignment.");
    }
  }
  render_objects_.push_back(render_object);
}

void crux::internal::RenderBatch::ResortObjects() {
  for (size_t i = 0; i < render_objects_.size() - 1; i++) {
  }
}
