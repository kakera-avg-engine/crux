#ifndef CRUX_INCLUDE_SURFACE_H_
#define CRUX_INCLUDE_SURFACE_H_

#include <memory>
#include "platform_data.h"
#include "backends.h"
#include "resolution.h"

namespace crux {

// A forward declaration for pImpl.
namespace internal { class BackendInterface; }

class Surface {
 public:
  Surface(Backend backend, const PlatformData& platform_data,
          Resolution resolution);

  Backend backend();

  Resolution resolution();
  void set_resolution(Resolution resolution);

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