#include "film.hpp"
#include "thread_pool.hpp"
#include <chrono>
#include <cstddef>
#include <glm/glm.hpp>
#include <iostream>

// class SimpleTask : public Task {
// public:
//   void Run() override { std::cout << "Hello World !" << std::endl; }
// };

int main() {
  ThreadPool thread_pool{};

  Film film{1920, 1080};

  thread_pool.ParallelFor(200, 100, [&](size_t x, size_t y) {
    film.setPixel(x, y, {0.5, 0.7, 0.2});
  });

  // for (int i = 0; i < 100; ++i) {
  //   for (int j = 0; j < 200; ++j) {
  //     film.setPixel(j, i, {0.5, 0.7, 0.2});
  //   }
  // }

  auto now = std::chrono::high_resolution_clock::now();
  thread_pool.Wait();
  film.Save("test.ppm");
  auto time = std::chrono::high_resolution_clock::now() - now;
  auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(time);
  std::cout << "Time:" << ms.count() << "\n";
  std::cout << film.GetPixel(1, 1).x << "," << film.GetPixel(1, 1).y << ","
            << film.GetPixel(1, 1).z;

  // thread_pool.AddTask(new SimpleTask());
  // thread_pool.AddTask(new SimpleTask());
  // thread_pool.AddTask(new SimpleTask());
  // thread_pool.AddTask(new SimpleTask());
  return 0;
}
