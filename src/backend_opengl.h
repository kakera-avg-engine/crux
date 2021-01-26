#ifndef CRUX_SRC_BACKEND_OPENGL_H_
#define CRUX_SRC_BACKEND_OPENGL_H_

#include "backend_interface.h"

namespace crux {
namespace internal {

class BackendOpenGL : public BackendInterface {
 public:
  BackendOpenGL() = default;
  BackendOpenGL(const BackendOpenGL&) = delete;
  BackendOpenGL& operator=(const BackendOpenGL&) = delete;
  ~BackendOpenGL();

  void Init(const PlatformData& platform_data) override;
};

} // namespace crux::internal
} // namespace crux

#endif // CRUX_SRC_BACKEND_OPENGL_H_