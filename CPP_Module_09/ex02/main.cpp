#include "PmergeMe.hpp"


int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: No input provided.\n";
        return 1;
    }
    std::vector<int> data;
    for (int i = 1; i < argc; ++i) {
        int num = std::atoi(argv[i]);
        if (num <= 0) {
            std::cerr << "Error: Only positive integers are allowed.\n";
            return 1;
        }
        data.push_back(num);
    }

    PmergeMe sorter(data);
    sorter.sort();

    return 0;
}