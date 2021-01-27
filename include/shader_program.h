// Copyright 2021 Drawoceans
#ifndef INCLUDE_SHADER_PROGRAM_H_
#define INCLUDE_SHADER_PROGRAM_H_

#include <vector>
#include <memory>
#include "include/shader.h"

namespace crux {

// A forward declaration for pImpl.
namespace internal { class ShaderProgramInterface; }

class ShaderProgram {
 public:
  explicit ShaderProgram(std::vector<std::unique_ptr<Shader>> shaders);

 private:
  std::unique_ptr<internal::ShaderProgramInterface> actual_program_;
  int program_id_ = -1;
  static int program_count_;
};

}  // namespace crux

#endif  // INCLUDE_SHADER_PROGRAM_H_
