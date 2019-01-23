#include <iostream>
#include "calculator.hpp"


int main()
{
    auto result = calculateExpression("5 3 a");
    std::cout << result.value;
    std::cout << result.error;
}
