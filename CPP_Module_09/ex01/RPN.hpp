#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

class RPN
{
private:
    std::vector<double> _vector;
public:
    RPN();
    RPN(RPN const &copy);
    RPN(std::vector<double> _vector);
    ~RPN();
    
    RPN &operator=(RPN const &copy);

    void calculator(const std::string& expression);
};
