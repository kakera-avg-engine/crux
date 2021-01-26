#ifndef CRUX_SRC_BACKEND_INTERFACE_H_
#define CRUX_SRC_BACKEND_INTERFACE_H_

#include "platform_data.h"

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

} // namespace crux::internal
} // namespace crux

#endif // CRUX_SRC_BACKEND_INTERFACE_H_