#include "backend_opengl.h"
#include <stdexcept>
#include "glad.h"
// Headers of WGL.
#ifdef _WIN32
# include <Windows.h>
# include <WinUser.h>
# include <wingdi.h>
#endif // _WIN32

crux::internal::BackendOpenGL::~BackendOpenGL() {
  if (context_) {
    #ifdef _WIN32
    wglMakeCurrent(NULL, NULL);
    wglDeleteContext(static_cast<HGLRC>(context_));
    #endif // _WIN32
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
    HWND hwnd = static_cast<HWND>(platform_data.native_window_handle);
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
    wglMakeCurrent(hdc, static_cast<HGLRC>(context_));
    #endif // _WIN32
  } else {
    context_ = platform_data.context;
    #ifdef _WIN32
    HWND hwnd = static_cast<HWND>(platform_data.native_window_handle);
    HDC hdc = GetDC(hwnd);
    wglMakeCurrent(hdc, static_cast<HGLRC>(context_));
    #endif // _WIN32
  }
}