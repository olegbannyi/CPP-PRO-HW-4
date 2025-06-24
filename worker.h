#ifndef WORKER_H
#define WORKER_H

#include <format>
#include <functional>
#include <iostream>
#include <utility>

template <typename R, typename... A> class Worker
{
    std::string name_;
    std::function<R(A...)> functor_;
    std::function<void(std::string, R)> output_;

  public:
    Worker(std::string name, std::function<R(A...)> functor, std::function<void(std::string, R)> output)
        : name_(std::move(name)), functor_(std::move(functor)), output_(std::move(output))
    {
    }
    void run(A... args)
    {
        try
        {
            R result = functor_(args...);
            output_(name_, result);
        }
        catch (const std::exception &e)
        {
            std::cout << std::format("ERROR: {}: {}\n", name_, e.what());
        }
    }
};

#endif // WORKER_H
