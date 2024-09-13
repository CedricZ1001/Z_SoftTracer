#pragma once

#include <filesystem>
#include <glm/glm.hpp>
#include <vector>

class Film {
public:
  Film(size_t width, size_t height);

  void Save(const std::filesystem::path &filename);

  inline size_t GetWidth() const { return width; }
  inline size_t GetHeight() const { return height; }
  inline glm::vec3 GetPixel(size_t x, size_t y) {
    return pixels[y * width + x];
  }
  void setPixel(size_t x, size_t y, const glm::vec3 &color) {
    pixels[y * width + x] = color;
  }

private:
  size_t width, height;
  std::vector<glm::vec3> pixels;
};
