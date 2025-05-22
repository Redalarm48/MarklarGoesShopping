#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include "mark.hpp"

class bank_account
{
    private:

    usd balance;
    std::string name;
    int id;

    public:
    
    bank_account(usd b, std::string n):balance(b), name(n)
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
        balance = amount;
    }
    void deposit(double amount)
    {
        double tmp = balance.getBa();
        tmp += amount;
        setBalance(tmp);
    }
    void withdraw(double amount)
    {
        double tmo = balance.getBa();
        tmo -= amount;
        setBalance(tmo);
    }
    double getBalance()
    {
        return balance.to_usd();
    };
    ~bank_account(){}
};

class personal : public bank_account
{
    private:

    public:

    personal(double balance, std::string name): bank_account(balance, name)
    {}
    ~personal(){}

};
class organisation : public bank_account
{
    private:

    public:

    organisation(double balance, std::string name): bank_account(balance, name)
    {}
    ~organisation(){}

};

#endif