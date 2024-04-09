#include <iostream>
#include <string>
#include <locale>

int main(int argc, char **argv)
{
    int i;
    int j;
    
    if (argc == 1)
        std::cout << "SHHHHH... I THINK THE STUDENTS ARE ASLEEP..." << std::endl;
    else
    {
        i = 1;  
        while (i < argc)
        {
            j = 0;
            while (argv[i][j])
                std::cout << (char)(toupper(argv[i][j++]));
            i++;
        }       
    }
    std::cout << std::endl;
    return 0;
}