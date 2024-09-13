#pragma once

#include "spin_lock.hpp"
#include <cstddef>
#include <functional>
#include <list>
#include <thread>
#include <vector>

class Task {
public:
  virtual void Run() = 0;
};

class ThreadPool {
public:
  ThreadPool(size_t thread_count = 0);
  ~ThreadPool();

  static void WorkrThread(ThreadPool *master);

  void ParallelFor(size_t width, size_t height,
                   const std::function<void(size_t, size_t)> &lamda);
  void Wait() const;

  void AddTask(Task *task);
  Task *GetTask();

private:
  std::atomic<int> alive;
  std::vector<std::thread> threads;
  std::list<Task *> tasks;
  SpinLock spin_lock{};
};