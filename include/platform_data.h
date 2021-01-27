// Copyright 2021 Drawoceans
#ifndef INCLUDE_PLATFORM_DATA_H_
#define INCLUDE_PLATFORM_DATA_H_

namespace crux {

// Bind native platform data to a surface.
struct PlatformData {
  void* native_window_handle = nullptr;
  // For X11 only.
  void* native_display_type = nullptr;
  void* context = nullptr;
};

}  // namespace crux

#endif  // INCLUDE_PLATFORM_DATA_H_
