// Copyright 2021 Drawoceans
#ifndef SRC_BACKEND_INTERFACE_H_
#define SRC_BACKEND_INTERFACE_H_

#include "include/platform_data.h"

namespace crux {
namespace internal {

class BackendInterface {
 public:
  virtual ~BackendInterface();

  virtual void Init(const PlatformData& platform_data) = 0;
  void* ReleaseContext();
  operator bool() const;
 protected:
  void* context_ = nullptr;
};

}  // namespace internal
}  // namespace crux

#endif  // SRC_BACKEND_INTERFACE_H_
