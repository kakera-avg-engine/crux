// Copyright 2021 Drawoceans
#ifndef INCLUDE_SHADER_H_
#define INCLUDE_SHADER_H_

#include <cstdint>
#include <memory>

namespace crux {

enum ShaderType : int {
  kVertex,
  kFragment,
};

// A forward declaration for pImpl.
namespace internal { class ShaderInterface; }

class Shader {
 public:
  // Load shader from memory buffer. Can only read C-style string text shader.
  Shader(const char* buffer, size_t buffer_size, ShaderType type);
  // Load shader from bytecode. For Vulkan only.
  Shader(uint32_t* bytecode, size_t bytecode_size, ShaderType type);

  ShaderType type() const;

 private:
  ShaderType type_;
  std::unique_ptr<internal::ShaderInterface> actual_shader_;
};

}  // namespace crux

#endif  // INCLUDE_SHADER_H_
