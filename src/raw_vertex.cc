// Copyright 2021 Drawoceans
#include "src/raw_vertex.h"
#include <utility>
#include "include/coordinate.h"
#include "include/color.h"

crux::internal::RawVertexData::RawVertexData(
    const std::vector<crux::Vertex> &vertices) {
  for (auto& vertex : vertices) {
    auto position = vertex.position_coord();
    raw_vertices_.push_back(position.x);
    raw_vertices_.push_back(position.y);
    auto tex_coord = vertex.texture_coord();
    if (tex_coord) {
      raw_vertices_.push_back(tex_coord->s);
      raw_vertices_.push_back(tex_coord->t);
    }
    auto color = vertex.color();
    if (color) {
      auto color_arr = color->GetColor();
      raw_vertices_.push_back(static_cast<float>(color_arr[0]) / 255.0f);
      raw_vertices_.push_back(static_cast<float>(color_arr[1]) / 255.0f);
      raw_vertices_.push_back(static_cast<float>(color_arr[2]) / 255.0f);
      raw_vertices_.push_back(static_cast<float>(color_arr[3]) / 255.0f);
    }
  }
}

crux::internal::RawVertexData::RawVertexData(
    const crux::internal::RawVertexData& other)
    : raw_vertices_(other.raw_vertices_) {}

crux::internal::RawVertexData::RawVertexData(
    crux::internal::RawVertexData&& other)
    : raw_vertices_(std::move(other.raw_vertices_)) {}

crux::internal::RawVertexData &crux::internal::RawVertexData::operator=(
    const crux::internal::RawVertexData& other) {
  raw_vertices_ = other.raw_vertices_;
}

crux::internal::RawVertexData &crux::internal::RawVertexData::operator=(
    crux::internal::RawVertexData &&other) {
  raw_vertices_ = std::move(other.raw_vertices_);
}

const std::vector<float>& crux::internal::RawVertexData::raw_vertices() const {
  return raw_vertices_;
}

