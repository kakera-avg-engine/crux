#ifndef CRUX_INCLUDE_SHADER_PROGRAM_H_
#define CRUX_INCLUDE_SHADER_PROGRAM_H_

#include <vector>
#include <memory>
#include "shader.h"

namespace crux {

// A forward declaration for pImpl.
namespace internal { class ShaderProgramInterface; }

class ShaderProgram {
 public:
  ShaderProgram(std::vector<std::unique_ptr<Shader>> shaders);

 private:
  std::unique_ptr<internal::ShaderProgramInterface> actual_program_;
};

} // namespace crux

#endif // CRUX_INCLUDE_SHADER_PROGRAM_H_