#include "backend_d3d12.h"
#ifdef _WIN32
#endif // _WIN32

crux::internal::BackendD3D12::~BackendD3D12() {
  #ifdef _WIN32
  if (context_) {

  }
  #endif // _WIN32
}

void crux::internal::BackendD3D12::Init(
    const crux::PlatformData& platform_data) {
  #ifdef _WIN32
  #endif // _WIN32
}