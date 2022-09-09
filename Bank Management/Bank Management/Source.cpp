#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    std::string x = "";
    
    
    std::vector<double> account_details = { 0, 0, 0 };
    while (x != "9") {
        std::cout << "Welcome to my bank!\n------------------------\n To open an account please type [1]\n------------------------\n To show account details, please press [2]\n------------------------\n To deposit, please press [3]\n------------------------\nTo withdraw, please press [4]\n------------------------\nTo exit, press [9]\n";
        std::cin >> x;

        if (x == "9") {
            break;
        }
        else if (x == "1") {
            std::string account_name = "";
            std::string j = "";
            std::cout << "What name should I register your account under?\n";
            std::cin >> account_name;
            std::cout << "Ok, I created a new account with the name " + account_name + ", which has " << account_details[0] << "$ in it\n";
            std::cout << "Do you wish to deposit today? [Y]/[N]\n";
            std::cin >> j;
            if (j == "Y") {
                int l = -1;
                std::cout << "How much do you wish to deposit?\n";
                std::cin >> l;
                account_details[0] += l;
                account_details[1] += l;
                std::cout << "The account under the name " + account_name + " now has " << account_details[0] << "$ in it\n";
            }
            else if (j == "N") {
                std::cout << "Alright, have a good day!\n";
                    continue;
            }
        }
        else if (x == "2") {
            std::string account_name = "";
            std::cout << "What is the name of the account you wish to access?\n";
            std::cin >> account_name;
            std::cout << "Printing account details...\nPrinting account details.\nPrinting account details..\nPrinting account details...\n";
            std::cout << "The account under the name " + account_name + " has " << account_details[0] << "$ in it\nTotal amount deposited: " << account_details[1] << "$\nTotal amount withdrawn: " << account_details[2] << "$\n";
        }
        else if (x == "3") {
            double g = 0;
            std::cout << "How much do you wish to deposit?\n";
            std::cin >> g;
            account_details[0] += g;
            account_details[1] += g;
            std::cout << "Your account now has " << account_details[0] << "$ in it.\n";
        }
        else if (x == "4") {
            double g = 0;
            std::cout << "How much do you wish to withdraw?\n";
            std::cin >> g;
            if (account_details[0] == 0) {
                std::cout << "Error! Your account does not have any money in it to withdraw.\n";
            }
            else if (account_details[0] < g) {
                std::cout << "Error! Your account does not have enough balance to cover that withdrawal.\n";
            } else {
                account_details[0] -= g;
                account_details[2] += g;
            }
            std::cout << "Your account now has " << account_details[0] << "$ in it.\n";
        } else {
            std::cout << "Error! Please try again";
        }
    }


    return 0;
}