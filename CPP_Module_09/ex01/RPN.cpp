#include "RPN.hpp"

RPN::RPN()
{}

RPN::RPN(std::vector<double> vector_): _vector(vector_)
{}

RPN::RPN(RPN const &copy)
{
    *this = copy;
}

RPN::~RPN()
{}
    
RPN &RPN::operator=(RPN const &copy)
{
    this->_vector == copy._vector;
    return *this;
}


void RPN::calculator(const std::string& expression) {
    std::istringstream iss(expression);
    std::string token;

    while (iss >> token) {
        if (isdigit(token[0])) {
            _vector.push_back(token[0] - '0');
        } else if (token.length() == 1 && (token == "+" || token == "-" || token == "*" || token == "/")) {
            if (_vector.size() < 2) {
                std::cerr << "Invalid expression" << std::endl;
                exit(1);
            }
            int b = _vector.back(); 
            _vector.pop_back();
            int a = _vector.back(); 
            _vector.pop_back();
            if (token == "+") 
                _vector.push_back(a + b);
            else if (token == "-") 
                _vector.push_back(a - b);
            else if (token == "*") 
                _vector.push_back(a * b);
            else if (token == "/") {
                if (b == 0) {
                    std::cerr << "Division by zero" << std::endl;
                    exit(1);
                }
                _vector.push_back(a / b);
            }
        } else {
            std::cerr << "Invalid" << std::endl;
            exit(1);
        }
    }

    if (_vector.size() != 1) {
        std::cerr << "This should be an expression" << std::endl;
        exit(1);
    }

    std::cout << _vector.back() << std::endl;
}