#include "math.h"
#include "thread-pool.h"
#include "worker.h"
#include <format>
#include <functional>
#include <iostream>
#include <sstream>
#include <vector>

const auto print_single = [](std::string name, unsigned int res) {
    std::cout << std::format("=== {} ===\n{}\n", name, res);
};

std::function<void(std::string, std::vector<unsigned int>)> print_list = [](std::string name,
                                                                            std::vector<unsigned int> res) {
    std::stringstream ss;
    ss << std::format("=== {} ===\n", name);
    for (const auto &v : res)
    {
        ss << v << " ";
    }
    std::cout << std::format("{}\n", ss.str());
};

int main()
{
    ThreadPool pool(4);

    Worker<unsigned int, unsigned int> w1("sum_of_squares", sum_of_squares, print_single);
    Worker<unsigned int, unsigned int> w2("factorial", factorial, print_single);
    Worker<std::vector<unsigned int>, unsigned int> w3("prime_number_list", prime_number_list, print_list);
    Worker<std::vector<unsigned int>, unsigned int> w4("fibonacci_list", fibonacci_list, print_list);

    pool.addWorker<unsigned int, unsigned int>(std::move(w1), 1000);
    pool.addWorker<unsigned int, unsigned int>(std::move(w2), 15);
    pool.addWorker<std::vector<unsigned int>, unsigned int>(std::move(w3), 100);
    pool.addWorker<std::vector<unsigned int>, unsigned int>(std::move(w4), 30);

    pool.waitAll();

    return 0;
}
