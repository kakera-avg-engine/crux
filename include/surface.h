#ifndef CRUX_INCLUDE_SURFACE_H_
#define CRUX_INCLUDE_SURFACE_H_

#include <memory>
#include "platform_data.h"
#include "backends.h"
#include "resolution.h"
#include "render_object.h"

namespace crux {

// A forward declaration for pImpl.
namespace internal { class BackendInterface; }

class Surface {
 public:
  // If platform_data.context is not nullptr, the ownership of context will be
  // transferred to the surface. You can call ReleaseContext() to return the
  // ownership back.
  // If backend is kAuto, the surface will create graphic context by itself
  // and ignore the given value of platform_data.context.
  Surface(Backend backend, const PlatformData& platform_data,
          Resolution resolution);

  Backend backend() const;

  Resolution resolution() const;
  void set_resolution(Resolution resolution);

  // Release the graphic context to manage it manually.
  void* ReleaseContext();
  void Draw(const RenderObject& render_object);
  void UpdateFrame();

 private:
  void SelectRightBackend();
  void InitActualBackend(const PlatformData& platform_data);

  Backend backend_;
  Resolution resolution_;
  std::unique_ptr<internal::BackendInterface> actual_backend_;
};

} // namespace crux

#endif // CRUX_INCLUDE_SURFACE_H_