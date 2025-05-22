#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include "mark.hpp"

class bank_account
{
    private:

    
    currency* balance;
    std::string name;
    int id;

    public:
    
    bank_account(currency* b, std::string n):balance(b), name(n)
    {}
    void setID(int ID)
    {
        id = ID;
    }
    int getID()
    {
        return id;
    }
    void setBalance(double amount)
    {
        *balance = amount;
    }
    void deposit(double amount)
    {
        double tmp = balance->getBa();
        tmp += amount;
        setBalance(tmp);
    }
    void withdraw(double amount)
    {
        double tmo = balance->getBa();
        if(tmo > amount)
        {
            tmo -= amount;
            setBalance(tmo);
        }
        else
        {
            std::cout << "you dont have enough money\n";
        }
    }
    double getBalance()
    {
        return balance->to_usd();
    };
    ~bank_account()
    {
        delete balance;
    }
};

class personal : public bank_account
{
    public:

    personal(currency* b , std::string name) : bank_account(b , name){}
    ~personal(){}

};
class organisation : public bank_account
{
    private:

    public:

    organisation(currency* b , std::string name) : bank_account(b , name){}
    ~organisation(){}

};

#endif