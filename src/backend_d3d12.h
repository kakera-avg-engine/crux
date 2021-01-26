#ifndef CRUX_SRC_BACKEND_D3D12_H_
#define CRUX_SRC_BACKEND_D3D12_H_

#include "backend_interface.h"

namespace crux {
namespace internal {

class BackendD3D12 : public BackendInterface {
 public:
  BackendD3D12() = default;
  BackendD3D12(const BackendD3D12&) = delete;
  BackendD3D12& operator=(const BackendD3D12&) = delete;
  ~BackendD3D12();

  void Init(const PlatformData& platform_data) override;

 #ifdef _WIN32
 private:
 #endif // _WIN32
};

} // namespace crux::internal
} // namespace crux

#endif // CRUX_SRC_BACKEND_D3D12_H_