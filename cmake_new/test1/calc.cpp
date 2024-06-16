#include <iostream>
#include "calc.h"

int main() {
    int a = 10, b = 5;
    std::cout << "a + b = " << add(a, b) << std::endl;
    std::cout << "a - b = " << sub(a, b) << std::endl;
    std::cout << "a * b = " << mult(a, b) << std::endl;
    std::cout << "a / b = " << div2(a, b) << std::endl;
    return 0;
}