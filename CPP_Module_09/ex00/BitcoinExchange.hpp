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
    std::map<std::string, double> _inputInfo;
public:
    BitcoinExchange();
    ~BitcoinExchange();
    std::map<std::string, double> setMap(std::ifstream &inputFile, const char *c);


    void getValue(char argv[]);
};

