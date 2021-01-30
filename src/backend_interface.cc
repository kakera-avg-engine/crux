// Copyright 2021 Drawoceans
#include "src/backend_interface.h"

crux::internal::BackendInterface::~BackendInterface() {
  context_ = nullptr;
}

void* crux::internal::BackendInterface::ReleaseContext() {
  void* temp_context = context_;
  context_ = nullptr;
  return temp_context;
}

crux::internal::BackendInterface::operator bool() const {
  return context_ != nullptr;
}

void crux::internal::BackendInterface::Draw(crux::RenderObject* render_object) {
  render_object_queue_.Push(render_object);
}
