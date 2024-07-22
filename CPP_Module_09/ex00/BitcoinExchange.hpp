#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <fstream>
#include <string>
#include <sstream>

class BitcoinExchange
{
private:
    std::map<std::string, double> _btcInfo;
public:
    BitcoinExchange();
    ~BitcoinExchange();

    void getValue(char argv[]);
};

