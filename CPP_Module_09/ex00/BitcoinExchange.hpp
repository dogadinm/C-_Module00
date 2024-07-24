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

    std::pair<std::string, double> parser(std::ifstream &inputFile, const char *c);
    bool isValidDate(const std::string& date);
    bool isLeapYear(int year);
    int daysInMonth(int year, int month);
    

public:
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const &copy);
    ~BitcoinExchange();


    BitcoinExchange &operator=(BitcoinExchange const &copy);

    void getValue(char argv[]);

};

