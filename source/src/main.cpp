#include "film.hpp"
#include "thread_pool.hpp"
#include <chrono>
#include <glm/glm.hpp>
#include <iostream>

class SimpleTask : public Task {
public:
  void run() override { std::cout << "Hello World !" << std::endl; }
};

int main() {
  Film film{1920, 1080};
  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < 200; ++j) {
      film.setPixel(j, i, {0.5, 0.7, 0.2});
    }
  }
  auto now = std::chrono::high_resolution_clock::now();
  film.Save("test.ppm");
  auto time = std::chrono::high_resolution_clock::now() - now;
  auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(time);
  std::cout << "Time:" << ms.count() << "\n";

  ThreadPool thread_pool{};
  thread_pool.AddTask(new SimpleTask());
  thread_pool.AddTask(new SimpleTask());
  thread_pool.AddTask(new SimpleTask());
  thread_pool.AddTask(new SimpleTask());
  return 0;
}
