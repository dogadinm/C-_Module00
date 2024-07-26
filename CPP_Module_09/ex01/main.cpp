#include <iostream>
#include <string>
#include "RPN.hpp"



int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cout << "Should be: RPN \"expression\"" << std::endl;
        return 1;
    }
    std::string input = argv[1];
    RPN calculator;
    calculator.calculator(input);  

    return 0;
}