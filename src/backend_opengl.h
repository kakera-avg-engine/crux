// Copyright 2021 Drawoceans
#ifndef SRC_BACKEND_OPENGL_H_
#define SRC_BACKEND_OPENGL_H_

#include "src/backend_interface.h"

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

}  // namespace internal
}  // namespace crux

#endif  // SRC_BACKEND_OPENGL_H_
