#include <iostream>

int main()
{
    std::string end = "y";
    std::string var = "y";
    double sum = 0;
    
    while (var == end) {
        double ans = 0;
        std::cout << "Enter a number: ";
        std::cin >> ans;
        std::cout << "Do you want to add to the sum (y/n): ";
        std::cin >> var;
        sum = sum + ans;
        
    }
    
    std::cout << "The sum is " << sum;
    
    
    
}
