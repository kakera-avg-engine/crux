// Copyright 2021 Drawoceans
#include "src/backend_opengl.h"
#include <stdexcept>
#include <vector>
#include <memory>
#include "src/glad.h"
#include "include/render_object.h"
#include "src/render_queue.h"
#include "src/render_batch.h"
#include "src/raw_vertex.h"
// Headers of WGL.
#ifdef _WIN32
# include <Windows.h>
# include <WinUser.h>
# include <wingdi.h>
#endif  // _WIN32

crux::internal::BackendOpenGL::~BackendOpenGL() {
  if (context_) {
#ifdef _WIN32
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(static_cast<HGLRC>(context_));
#endif  // _WIN32
  }
}

void crux::internal::BackendOpenGL::Init(
    const crux::PlatformData& platform_data) {
  if (!platform_data.native_window_handle) {
    throw std::invalid_argument("Null native window handle.");
  }
  if (!platform_data.context) {
    // No context is given, create.
#ifdef _WIN32
    HWND hwnd = reinterpret_cast<HWND>(platform_data.native_window_handle);
    HDC hdc = GetDC(hwnd);
    PIXELFORMATDESCRIPTOR pfd {
      sizeof(PIXELFORMATDESCRIPTOR),
      1,
      PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
      PFD_TYPE_RGBA,
      32,  // Colordepth of framebuffer
      0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
      24,  // Bits of depthbuffer
      8,   // Bits of stencilbuffer
      0,
      PFD_MAIN_PLANE,
      0, 0, 0, 0
    };
    int pixel_format = ChoosePixelFormat(hdc, &pfd);
    SetPixelFormat(hdc, pixel_format, &pfd);
    context_ = wglCreateContext(hdc);
    wglMakeCurrent(hdc, reinterpret_cast<HGLRC>(context_));
    gladLoadGLLoader(reinterpret_cast<GLADloadproc>(wglGetProcAddress));
#endif  // _WIN32
  } else {
    context_ = platform_data.context;
#ifdef _WIN32
    HWND hwnd = reinterpret_cast<HWND>(platform_data.native_window_handle);
    HDC hdc = GetDC(hwnd);
    wglMakeCurrent(hdc, reinterpret_cast<HGLRC>(context_));
    gladLoadGLLoader(reinterpret_cast<GLADloadproc>(wglGetProcAddress));
#endif  // _WIN32
  }
}

void crux::internal::BackendOpenGL::CreateVertexBuffer() {
  auto render_batches = render_object_queue_.render_batches();
  for (auto& batch : render_batches) {
    std::vector<float> unified_vertices_array;
    auto& render_objects = batch->render_objects();
    for (auto render_object : render_objects) {
      auto raw_vertices = render_object->raw_vertex_data();
      const auto raw_vertices_arr = raw_vertices->raw_vertices();
      unified_vertices_array.insert(unified_vertices_array.end(),
                                    raw_vertices_arr.begin(),
                                    raw_vertices_arr.end());
    }
    // opengl binding.
  }
}
