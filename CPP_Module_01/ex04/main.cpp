#include <iostream>
#include <fstream>


std::string	read_and_save(char **argv)
{
    char    c;
    std::string		str;
    std::ifstream   ifs;

    ifs.open(argv[1]);
    if (ifs.is_open())
    {
        while (!ifs.eof() && ifs >> std::noskipws >> c)
            str += c;
    }
    else
    {
        std::cerr << "Error: '" << argv[1] << "'" << " doesn't exist" << std::endl;
        str = "false";
    }
    ifs.close();
    return (str); 
}

int replace(char **argv, std::string	str)
{
    std::ofstream ofs;
    int pos;
    bool found = false;

    for (int i = 0; i < (int)str.size(); i++)
    {
        pos = str.find(argv[2], i);
        if (pos != -1 && pos == i)
        {
            found = true;
            break;            
        }
    }

    if (!found) 
    {
        std::cerr << "Error: String '" << argv[2] << "' not found in file '" << argv[1] << "'" << std::endl;
        return 1;
    }
        
    ofs.open((std::string(argv[1]) + ".replace").c_str());
    if (!ofs.is_open())
    {
        std::cerr << "Error: Unable to create file " << argv[1] << ".replace" << std::endl;
        return (1);
    }

    for (int i = 0; i < (int)str.size(); i++)
    {
        pos = str.find(argv[2], i);
        if (pos != -1 && pos == i)
        {
            ofs << argv[3];
            i += std::string(argv[2]).size() - 1;
        }
        else 
            ofs << str[i];         
    }
    ofs.close(); 
    return (0);
}


int main(int argc, char **argv)
{
    std::string		str;

    if (argc != 4)
    {
        std::cerr << "Shoud be: ./replace filename string_old string_new " << std::endl;
        return (1);
    }
    else
    {
        str = read_and_save(argv);
        if (str == "false")
            return (1);        
    }
    return (replace(argv, str));
}