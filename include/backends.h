#ifndef CRUX_INCLUDE_BACKENDS_H_
#define CRUX_INCLUDE_BACKENDS_H_

namespace crux {

enum Backend : int {
  kAuto = 0,
  kOpenGL,
  kDirect3D12,
  kVulkan
};

} // namespace crux

#endif // CRUX_INCLUDE_BACKEND_H_