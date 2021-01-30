// Copyright 2021 Drawoceans
#ifndef INCLUDE_SURFACE_H_
#define INCLUDE_SURFACE_H_

#include <memory>
#include "include/platform_data.h"
#include "include/backends.h"
#include "include/resolution.h"
#include "include/color.h"
#include "include/render_object.h"

namespace crux {

// A forward declaration for pImpl.
namespace internal { class BackendInterface; }

class Surface {
 public:
  static Surface& GetSurface();
  // If platform_data.context is not nullptr, the ownership of context will be
  // transferred to the surface. You can call ReleaseContext() to return the
  // ownership back.
  // If backend is kAuto, the surface will create graphic context by itself
  // and ignore the given value of platform_data.context.
  void Init(Backend backend, const PlatformData& platform_data,
            Resolution resolution);

  Surface(const Surface&) = delete;
  Surface& operator=(const Surface&) = delete;

  Backend backend() const;

  Resolution resolution() const;
  void set_resolution(Resolution resolution);

  Color clear_color() const;
  void set_clear_color(Color clear_color);

  // Release the graphic context to manage it manually.
  void* ReleaseContext();
  void Draw(RenderObject* render_object);
  void UpdateFrame();

 private:
  Surface() = default;
  void SelectRightBackend();
  void InitActualBackend(const PlatformData& platform_data);

  Backend backend_;
  Resolution resolution_;
  Color clear_color_;
  static std::unique_ptr<internal::BackendInterface> actual_backend_;
};

}  // namespace crux

#endif  // INCLUDE_SURFACE_H_
