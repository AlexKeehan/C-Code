#include <iostream>

int main()
{
    std::string ans = "";
    std::cout << "Abbreviation converter: ";
    std::cin >> ans;
    
    if (ans == "AMA") {
        std::cout << "ask me anything";
    } else if (ans == "LOL") {
        std::cout << "laughing out loud";
    } else if (ans == "LMK") {
        std::cout << "let me know";
    } else if (ans == "IMHO") {
        std::cout << "in my humble opinion";
    } else if (ans == "IDK") {
        std::cout << "I don't know";
    } else {
        std::cout << "Unknown";
    }
    
    
    
}
