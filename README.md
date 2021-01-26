# Crux
[简体中文](https://github.com/kakera-avg-engine/crux/blob/dev/master/README_zh_hans.md) | [日本語](https://github.com/kakera-avg-engine/crux/blob/dev/master/README_ja_jp.md)

A cross-platform 2D graphic library for Kakera AVG Engine.

## What is it?

It's a cross-platform 2D graphic library like [Skia](https://skia.org/) and [Cairo](https://www.cairographics.org/), but gives user more control of rendering details. In this sense, it's more like [bgfx](https://github.com/bkaradzic/bgfx).

Notice: It **is not** an universal library but a customized library for Kakera AVG Engine, please ensure the library can fit your project before using it.

## How to build?

(uncomplete)

## How to use?

Here is a simple guide that the basic usage of Crux library.

### 1. Create a window on your platform.

Create a window on your platform, you can use [SDL](https://www.libsdl.org/) or [GLFW](https://www.glfw.org/) or any other libraries you like.  You can also use native APIs, it's doesn't matter. It's the only important thing that there is a window. Do not remember to get the handle of the window, if you are using X11, display type is also necessary.

###  2. Create a Crux surface.

Create a surface by initializing a `Surface` class defined in `include/surface.h` to start your Crux trip. You have to specify the graphic backend you want, or just pass a `kAuto` to let Crux choose the right one automatically. Then fill a `PlatformData` structure with your native window handle. If you have your own graphic context(`GLcontext` of OpenGL, or `vkInstance` of Vulkan, etc.), you can also fill it in, but don't forget to call `ReleaseContext()` after you get a surface to give the ownership of graphic context back to you. Last, tell Crux the resolution, or size in pixel, of your window. If everything goes well, you have already got a Crux surface. If you have multiple windows, you should create surfaces for each window.

### 3. Prepare the vertex input.

As mentioned before, Crux is a low-level 2D graphic library. So it means you need to create the whole graphic pipeline to render something although it's a simple version. Start from this step you have to create a very simple graphic pipeline, but in fact many features of an actual graphic pipeline like OpenGL's and Vulkan's are unsupported in Crux, so you just have to prepare the vertex data and shaders. Unlike OpenGL or other "real" graphic APIs, there is no normalized device coordinates in Crux, all coordinates are transformed by a 2D projection matrix so you can use screen coordinates directly.

Include `include/vertex,h` to create a vertex. It needs a coordinate as position of screen, and optional color information and texture coordinate. The definition of texture coordinates is same as OpenGL's, (0, 0) means lower-left, (0, 1) means top-left, (1, 0) means lower-right, (1, 1) means top-right. See [this atricle](https://learnopengl.com/Getting-started/Textures) for more information.

### 4. Load shaders and create shader program.

Load your shader file and create a Crux shader. You can create a shader with a C-style string or a bytecode, it depends on the graphic backend. Use GLSL text string if you are using OpenGL, or use SPIR-V bytecode if you are using Vulkan. You also need to tell Crux that the shader is a vertex shader or a fragment(pixel) shader by pass a `ShaderType` enumeration. The support for geometry shader is in plan.

If you have created your vexter shader and fragment shader, you need to put them together to create a shader program, just by passing a `std::vector` of some `std::unique_ptr<crux::Shader>`.

### 5. Allocate a texture. (optional)

If you want to render an picture, you have to allocate a texture for it. Just read the raw pixels of your picture by [stb_image](https://github.com/nothings/stb) or other libraries you like, then pass the pointer to the pixels and the resolution of your picture, you'll get the allocated texture. If you decide to bind the texture with your vertices, don't forget to specify texture coordinates of your vertices.

### 6. Create a render object.

This selection you will put all of above objects together, including the vertices, the shader program and the texture if you allocated one. There is another thing maybe useful named index buffer, or element buffer. If no index buffer is passed, the renderring order will be the order of vertices in the array. But if there is a index buffer, the renderring order will be controlled by the index buffer. It can also save vertices to save memory space. For more infromation, please read the *Element Buffer Objects* selection of [this article](https://learnopengl.com/#!Getting-started/Hello-Triangle), it is discussing the element buffer objects of OpenGL, but they are almost the same thing.

### 7. Draw the render object by the surface.

Once the render object is created, you can call the `Draw()` method of the surface that you created at step 2 to submit the render object to your surface. When all render objects are submitted, then call the `UpdateFrame()` to actually draw them as a frame and display it on your screen. Congratulations, you have already show something with Crux!

## License (MIT License)

<a href="https://opensource.org/licenses/MIT" target="_blank">
<img align="right" src="http://opensource.org/trademarks/opensource/OSI-Approved-License-100x137.png">
</a>

```
MIT License

Copyright (c) 2021 Kakera AVG Engine

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
```

