// Copyright 2021 Drawoceans
#include "include/surface.h"
#include <cassert>
#include <stdexcept>
#include "src/backend_opengl.h"

#ifdef BUILD_WITH_D3D12_
# include "src/backend_d3d12.h"
#endif  // BUILD_WITH_D3D12_
#ifdef BUILD_WITH_VULKAN_
# include "src/backend_vulkan.h"
#endif  // BUILD_WITH_VULKAN_

crux::Surface &crux::Surface::GetSurface() {
  static crux::Surface surface;
  return surface;
}

void crux::Surface::Init(crux::Backend backend,
                         const crux::PlatformData& platform_data,
                         crux::Resolution resolution) {
  if (backend == crux::Backend::kAuto) {
    SelectRightBackend();
  } else {
    backend_ = backend;
  }
  InitActualBackend(platform_data);
}

crux::Backend crux::Surface::backend() const {
  return backend_;
}

crux::Resolution crux::Surface::resolution() const {
  return resolution_;
}

void crux::Surface::set_resolution(crux::Resolution resolution) {
  resolution_ = resolution;
}

crux::Color crux::Surface::clear_color() const {
  return clear_color_;
}

void crux::Surface::set_clear_color(crux::Color clear_color) {
  clear_color_ = clear_color;
}

void* crux::Surface::ReleaseContext() {
  return actual_backend_->ReleaseContext();
}

void crux::Surface::Draw(crux::RenderObject* render_object) {
}

void crux::Surface::UpdateFrame() {
}

void crux::Surface::SelectRightBackend() {
  // TODO(drawoceans): Always select OpenGL until other backends are supported.
  backend_ = crux::Backend::kOpenGL;
}

void crux::Surface::InitActualBackend(const crux::PlatformData& platform_data) {
  if (backend_) {
    throw std::runtime_error("Backend is reinitialized.");
  }
  switch (backend_) {
    case crux::Backend::kOpenGL: {
      actual_backend_ = std::make_unique<crux::internal::BackendOpenGL>();
      break;
    }
#ifdef BUILD_WITH_D3D12_
    case crux::Backend::kDirect3D12: {
      actual_backend_ = std::make_unique<crux::internal::BackendD3D12>();
      break;
    }
#endif  // BUILD_WITH_D3D12_
#ifdef BUILD_WITH_VULKAN_
    case crux::Backend::kVulkan: {
      actual_backend_ = std::make_unique<crux::internal::BackendVulkan>();
      break;
    }
#endif  // BUILD_WITH_VULKAN_
    default: {
      throw std::invalid_argument("Un supported backend.");
    }
  }
  actual_backend_->Init(platform_data);
}
