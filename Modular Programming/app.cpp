#include "Operators.h"
#include <iostream>
#include <cstdlib>

int main()
{
    // Numbers used 6 and 9
    std::cout << "ADD " << add(6, 9) << std::endl;
    std::cout << "SUB " << sub(6, 9) << std::endl;
    std::cout << "MUL " << mul(6, 9) << std::endl;
    std::cout << "DIV " << div(6.0f, 9.0f) << std::endl;
    // ...
    system("pause");
}