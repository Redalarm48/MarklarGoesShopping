#include <iostream>
#include "bank.hpp"
#include "mark.hpp"
void deposit(double amount)
{
    
}

void withdraw(double amount)
{

}

void getBalance()
{

}

std::string input()
{
    std::string request;
    std::cin >> request;
    if (request == "no")
    {
        return "no";
    }
    else
    {
        switch (1)
        {
        case 1:
            /* code */
            //return req;
            break;
        
        default:
            std::cout << "no such request is defined!";
            break;
        }
    }
}