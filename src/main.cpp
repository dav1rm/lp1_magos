#include <iostream>
#include <iomanip>
#include "../include/canvas.h"

int main(int argc, char **argv)
{
    if (argc > 5)
    {
        std::cout << "Too many arguments" << std::endl;
        return 0;
    }
    if (argc < 2)
    {
        //gera col, heightm e width
    }
    else if (argc < 3)
    {
        // gera heightm e width
    }
    else if (argc < 4)
    {
        //gera width
    }

    std::cout << "rodando o programa " << std::endl;
}