// Copyright 2021 Drawoceans
#ifndef SRC_BACKEND_INTERFACE_H_
#define SRC_BACKEND_INTERFACE_H_

#include "include/platform_data.h"
#include "include/render_object.h"
#include "src/render_queue.h"

namespace crux {
namespace internal {

class BackendInterface {
 public:
  virtual ~BackendInterface();

  virtual void Init(const PlatformData& platform_data) = 0;
  // TODO(drawoceans): Actual shader interface is not sure now.
  virtual void CompileShader() = 0;
  // TODO(drawoceans): Actual shader interface is not sure now.
  virtual void CreateShaderProgram() = 0;
  // TODO(drawoceans): Actual texture interface is not sure now.
  virtual void AllocateTexture() = 0;
  virtual void CreateVertexBuffer() = 0;
  virtual void RenderFrame() = 0;

  void* ReleaseContext();
  operator bool() const;
  void Draw(RenderObject* render_object);

 protected:
  void* context_ = nullptr;
  RenderQueue render_object_queue_;
};

}  // namespace internal
}  // namespace crux

#endif  // SRC_BACKEND_INTERFACE_H_
