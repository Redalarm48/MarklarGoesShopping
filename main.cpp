#include <iostream>
#include "bank.hpp"
#include "mark.hpp"
#include "func.cpp"

using namespace std;

int main()
{
    personal a(0,"cust");
    a.setID(2);
    organisation o(0,"org");
    o.setID(1);
    bool run = true;
    int id;
    while(run)
    {
        cout << "enter your id number";
        cin >> id;        
        while(run && id == 1)
        {
            cout << "enter your request: \n" << "(if you don't have any enter 'no')";
            std::string req = input();
            if (req == "no")
            {
                run = false;
            }
        }
        while (run && id != 1)
        {
            cout << "enter your request: \n" << "(if you don't have any enter 'no')";
            std::string req = input();
            if (req == "no")
            {
                run = false;
            }        
        }
    }
    return 0;
}