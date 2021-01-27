// Copyright 2021 Drawoceans
#ifndef INCLUDE_BACKENDS_H_
#define INCLUDE_BACKENDS_H_

namespace crux {

enum Backend : int {
  kAuto = 0,
  kOpenGL,
  kDirect3D12,
  kVulkan
};

}  // namespace crux

#endif  // INCLUDE_BACKENDS_H_
