
#include <iostream>
#include <vector>

int main()
{
    
    std::string x = "";
    std::vector<std::string> library = {"Steelheart", "Firefly", "Calamity"};

    
    while (x != "exit") {
        std::cout << "\n\n\nWelcome to the library! \nTo view the library, type list. \nTo add a book, type new. \nTo remove a book, type remove. \nTo leave, type exit.\n";
        std::cin >> x;
    

        if (x == "exit") {
            break;
        } else if (x == "list") {
            for (int i = 0; i < library.size(); i++) {
                std::cout << "\n" + library[i] + " ";
            }
        } else if (x == "new") {
            std::string z = "";
            std::cout << "What is the name of the book that you wish to add to the library?\n";
            std::cin >> z;
                if (z == "exit") {
                    break;
                } else {
                    library.push_back(z);
                }
                
        } else if (x == "remove") {
            std::string g = "";
            std::cout << "What is the name of the book that you wish to remove?\n";
            std::cin >> g;
                if (g == "exit") {
                    break;
                } else {
                    library.erase(std::remove(library.begin(), library.end(), g), library.end());
                }
        } else {
            std::cout << "Error please type something valid";
        }
    }
    return 0;
    
}
