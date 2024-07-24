#include "BitcoinExchange.hpp"

#include <iomanip>


BitcoinExchange::BitcoinExchange(BitcoinExchange const &copy)
{
	*this = copy;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &copy)
{
	this->_btcInfo = copy._btcInfo;
	return (*this);
}


BitcoinExchange::BitcoinExchange()
{
    std::string line;
    std::ifstream btcFile ("./data.csv");
    std::getline(btcFile, line);
    while (true)
    {
        std::pair<std::string, double> res = parser(btcFile, ",");
        if (res.first == "NULL")
             break; 
        _btcInfo[res.first] = res.second;
    }
    
    // std::map<std::string, double>::iterator it = _btcInfo.begin();
    // while (it != _btcInfo.end())
    // {
        
    //     std::cout << "Date: "<< it->first <<  " " <<  "Price: " << it->second << std::endl;
    //     ++it;
    // }
}

void BitcoinExchange::getValue(char argv[])
{
    double value;
    std::string line;

    std::map<std::string, double>::iterator it;
    std::ifstream inputFil (argv);
    std::getline(inputFil, line);


    while (true)
    {
        std::pair<std::string, double> res = parser(inputFil, "|");
        if (res.first == "NULL")
             break;
        else if (res.first == "Error: bad input")
             continue;
        
        it = _btcInfo.lower_bound(res.first);
        it--;

        if (res.second < 0){
            std::cout <<"Error: not a positive number."<< std::endl;
            continue;
        }else if (res.second > 1000){
            std::cout << "Error: too large a number." << std::endl;
            continue;
        }
            
        value = _btcInfo[it->first] * res.second;    
        std::cout << res.first << " => "<< res.second << " = " << value << std::endl;
    }
    inputFil.close();

}

std::pair<std::string, double> BitcoinExchange::parser(std::ifstream &inputFile, const char *c)
{

    std::size_t separPos;
    std::string line;
    std::string line_no_space;    
    std::string inputDate;
    std::string valueStr;
    size_t index;
    double value;

    if (!inputFile.is_open()){
        std::cout << "Cant open the file" << std::endl;
        exit(1);
    }
    


    if (std::getline(inputFile, line))
    {
        line_no_space = line;

        // Delete space 
        index = 0;
        while((index = line_no_space.find(' ')) != std::string::npos)
            line_no_space.erase(index, 1);

        // Divide a line 
        if (((separPos = line_no_space.find(c)) != std::string::npos))
        {
            // Get Date
            inputDate = line_no_space.substr(0, separPos);
            if (!isValidDate(inputDate)) {
                std::cerr << "Error: bad input => " << line << std::endl;
                return std::make_pair("Error: bad input", 0.0);
            }
            // Get value
            valueStr = line_no_space.substr(separPos + 1);
            std::istringstream ist(valueStr);
            if (!(ist >> value)) { 
                std::cerr << "Error: bad input => " << line << std::endl;
                return std::make_pair("Error: bad input", 0.0);
            }
        }
        else{
            std::cerr << "Error: bad input => " << line << std::endl;
            return std::make_pair("Error: bad input", 0.0);
        }
    }
    else
        return std::make_pair("NULL", 0.0);
    return std::make_pair(inputDate, value);

}


bool BitcoinExchange::isValidDate(const std::string& date) {
    std::istringstream iss(date);
    int year, month, day;
    char delimiter1, delimiter2;

    if (!(iss >> year >> delimiter1 >> month >> delimiter2 >> day) ||
        delimiter1 != '-' || delimiter2 != '-' || month < 1 || month > 12 || day < 1) {
        return false;
    }

    // Checking the correctness of the day depending on the monthа
    return day <= daysInMonth(year, month);
}

// Checking the number of days in a month
int BitcoinExchange::daysInMonth(int year, int month) {
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            return isLeapYear(year) ? 29 : 28;
        default:
            return 0;
    }
}

// Leap year check
bool BitcoinExchange::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

BitcoinExchange::~BitcoinExchange()
{
}
