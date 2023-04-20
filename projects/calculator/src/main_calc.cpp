#include "calc/calculator.h"
#include <iostream>
#include <string>


int main(){
    std::string s;
    std::cin>>s;

    Calculator calculator(s);
    std::cout << calculator.calculate();
    return 0;
}
