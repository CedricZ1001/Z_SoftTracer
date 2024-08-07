#pragma once

#include<vector>
#include<thread>
#include<list>
#include<mutex>

class Task{
public:
    virtual void run() = 0;
};

class ThreadPool{
public:
    ThreadPool(size_t thread_count = 0);
    ~ThreadPool();

    static void WorkrThread(ThreadPool *master);

    void AddTask(Task *task);
    Task *GetTask();

private:
    bool alive;
    std::vector<std::thread> threads;
    std::list<Task *> tasks;
    std::mutex lock;
};