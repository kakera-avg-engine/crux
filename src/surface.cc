#include "surface.h"
#include <cassert>
#include "backend_d3d12.h"
#include "backend_opengl.h"
#include "backend_vulkan.h"

crux::Surface::Surface(crux::Backend backend,
                       const crux::PlatformData& platform_data,
                       crux::Resolution resolution) {
  if (backend == crux::Backend::kAuto) {
    SelectRightBackend();
  }
  InitActualBackend(platform_data);
}

crux::Backend crux::Surface::backend() {
  return backend_;
}

crux::Resolution crux::Surface::resolution() {
  return resolution_;
}

void crux::Surface::set_resolution(crux::Resolution resolution) {
  resolution_ = resolution;
}

void crux::Surface::UpdateFrame() {
}

void crux::Surface::SelectRightBackend() {

}

void crux::Surface::InitActualBackend(const crux::PlatformData& platform_data) {
  switch (backend_) {
    case crux::Backend::kDirect3D12: {
      actual_backend_ = std::make_unique<crux::internal::BackendD3D12>();
      break;
    }
    case crux::Backend::kOpenGL: {
      actual_backend_ = std::make_unique<crux::internal::BackendOpenGL>();
      break;
    }
    case crux::Backend::kVulkan: {
      actual_backend_ = std::make_unique<crux::internal::BackendVulkan>();
      break;
    }
    default: {
      assert(false);
    }
  }
  actual_backend_->Init(platform_data);
}