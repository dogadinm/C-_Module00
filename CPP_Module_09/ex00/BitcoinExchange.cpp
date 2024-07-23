#include "BitcoinExchange.hpp"

#include <iomanip>

BitcoinExchange::BitcoinExchange()
{
    // std::size_t commonPos;
    // std::string date;
    // std::string valueStr;
    // double value;

    // std::cout << std::fixed << std::setprecision(2);
    std::ifstream btcFile ("./data.csv");
    _btcInfo = setMap(btcFile, ",");
    // if (!btcFile.is_open())
    // {
    //     std::cout << "cant open data.cvs" << std::endl;
    //     exit(1);
    // }
    // std::string line;
    // std::getline(btcFile, line);

    // while (std::getline(btcFile, line))
    // {
    //     commonPos = line.find(',');

    //     if (commonPos != std::string::npos)
    //     {
    //         date = line.substr(0, commonPos);
    //         valueStr = line.substr(commonPos + 1);
    //         std::istringstream ist(valueStr);
    //         ist>>value;        
    //         _btcInfo[date] = value;
    //     }
    //     else{
    //         std::cerr << "Error: invalid input format" << std::endl;
    //     }

    // }
    std::map<std::string, double>::iterator it = _btcInfo.begin();
    while (it != _btcInfo.end())
    {
        
        std::cout << "Date: "<< it->first <<  " " <<  "Price: " << it->second << std::endl;
        ++it;
    }
}

void BitcoinExchange::getValue(char argv[])
{
    std::ifstream inputFil (argv);
    _inputInfo = setMap(inputFil, ",");
//     std::ifstream inputFile (argv);
//     std::size_t pipePos;
//     std::string inputDate;
//     std::string valueStr;
//     double value;
//     double value2;
 
//     if (!inputFile.is_open())
//     {
//         std::cout << "cant open data.cvs" << std::endl;
//         exit(1);
//     }
//     std::string line;
//     std::getline(inputFile, line);

//     while (std::getline(inputFile, line))
//     {
//         size_t index = 0;
//         while((index = line.find(' ')) != std::string::npos)
//             line.erase(index, 1);
        
//         if ((pipePos = line.find('|')) != std::string::npos)
//         {

            
//             inputDate = line.substr(0, pipePos);
//             valueStr = line.substr(pipePos + 1);
//             std::istringstream ist(valueStr );
//             ist>>value;
//             value2 = _btcInfo[inputDate] * value;
//             std::cout << inputDate << " => "<< valueStr << " = " << 
//                 value2 << std::endl;

//         }
//         else{
//             std::cerr << "Error: invalid input format" << std::endl;
//         }

//     }
}

std::map<std::string, double> BitcoinExchange::setMap(std::ifstream &inputFile, const char *c)
{

    std::size_t pipePos;
    std::string inputDate;
    std::string valueStr;
    double value;
    // double value2;

    std::map<std::string, double> tmp;
 
    if (!inputFile.is_open())
    {
        std::cout << "cant open data.cvs" << std::endl;
        exit(1);
    }
    std::string line;
    std::getline(inputFile, line);

    while (std::getline(inputFile, line))
    {
        size_t index = 0;
        while((index = line.find(' ')) != std::string::npos)
            line.erase(index, 1);
        
        if ((pipePos = line.find(c)) != std::string::npos)
        {

            
            inputDate = line.substr(0, pipePos);
            valueStr = line.substr(pipePos + 1);
            std::istringstream ist(valueStr );
            ist>>value;
            // value2 = _btcInfo[inputDate] * value;
            // std::cout << inputDate << " => "<< valueStr << " = " << 
            //     value2 << std::endl;
            tmp[inputDate] = value;
        }
        else{
            std::cerr << "Error: invalid input format" << std::endl;
        }

    }
    return tmp;
}

BitcoinExchange::~BitcoinExchange()
{
}
