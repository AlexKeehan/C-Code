#include <iostream>

int main()
{
    
    double f = 76.2;
    double c = (f - 32) * 5 / 9;
    std::cout << "76.2 F is " << c << "C";
    
    double x = 0;
    std::cout << "Enter a temperature in fahrenheit: ";
    std::cin >> x;
    
    double c2 = (x - 32) * 5 / 9;
    std::cout << c2 << " Celsius";
}
