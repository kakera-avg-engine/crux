// Copyright 2021 Drawoceans
#include "include/shader_program.h"
#include <stdexcept>

int crux::ShaderProgram::program_count_ = 1;

crux::ShaderProgram::ShaderProgram(
    std::vector<std::unique_ptr<crux::Shader>> shaders) {
  if (shaders.empty()) {
    throw std::invalid_argument("No shader is passed.");
  }
  if (program_count_ > 255) {
    throw std::runtime_error("Too much shader programs.");
  }
  program_id_ = program_count_;
  program_count_++;
}

uint8_t crux::ShaderProgram::program_id() const {
  return program_id_;
}

crux::ShaderProgram::operator bool() const {
  return program_id_ > 0;
}
