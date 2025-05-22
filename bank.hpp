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

void deposit(double amount);
void withdraw(double amount);
void getBalance();
#endif