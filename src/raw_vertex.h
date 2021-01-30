// Copyright 2021 Drawoceans
#ifndef SRC_RAW_VERTEX_H_
#define SRC_RAW_VERTEX_H_

#include <vector>
#include "include/vertex.h"

namespace crux {
namespace internal {

class RawVertexData {
 public:
  explicit RawVertexData(const std::vector<Vertex>& vertices);
  RawVertexData(const RawVertexData& other);
  RawVertexData(RawVertexData&& other);
  RawVertexData& operator=(const RawVertexData& other);
  RawVertexData& operator=(RawVertexData&& other);

  const std::vector<float>& raw_vertices() const;
 private:
  std::vector<float> raw_vertices_;
};

}  // namespace internal
}  // namespace crux

#endif  // SRC_RAW_VERTEX_H_
