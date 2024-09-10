#include "film.hpp"
#include "thread_pool.hpp"
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

  film.Save("test.ppm");
  ThreadPool thread_pool{};
  thread_pool.AddTask(new SimpleTask());
  thread_pool.AddTask(new SimpleTask());
  thread_pool.AddTask(new SimpleTask());
  thread_pool.AddTask(new SimpleTask());
  return 0;
}
