#ifndef BANK_HPP
#define BANK_HPP

#include <iostream>
#include "mark.hpp"

class bank_account
{
    protected:

    
    currency* balance;
    std::string name;
    int id;
    

    public:

    static double limit;
    
    bank_account(currency* b, std::string n):balance(b), name(n){}

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
    virtual void deposit(double amount){}

    virtual void withdraw(double amount){}

    double getterLimit()
    {
        return limit;
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
    void deposit(double amount)override
    {
        if(getterLimit() < 1000)
        {
            double tmp = balance->getBa();
            tmp += amount;
            setBalance(tmp);
            limit += amount;
            
        }
        else
        {
            std::cout << "transfer limit passed \n";
        }
    }
    void withdraw(double amount)override
    {
        if(getterLimit() < 1000)
        {
            double tmo = balance->getBa();
            if(tmo > amount)
            {
                tmo -= amount;
                setBalance(tmo);
                limit += amount;
            }
            else
            {
                std::cout << "you dont have enough money\n";
            }
        }
        else
        {
            std::cout << "transfer limit passed \n";
        }
    }
    ~personal(){}

};
class organisation : public bank_account
{
    private:

    public:

    organisation(currency* b , std::string name) : bank_account(b , name){}
    void deposit(double amount)override
    {
        if(getterLimit() <= 1000)
        {
            double tmp = balance->getBa();
            tmp += amount;
            setBalance(tmp);
            limit += amount;
        }
        else
        {
            std::cout << "transfer limit passed \n";
        }
    }
    void withdraw(double amount)override
    {
        if(getterLimit() <= 1000)
        {
            double tmo = balance->getBa();
            if(tmo > amount)
            {
                tmo -= amount;
                setBalance(tmo);
                limit += amount;
            }
            else
            {
                std::cout << "you dont have enough money \n";
            }
        }
        else
        {
            std::cout << "transfer limit passed \n";
        }
    }
    ~organisation(){}

};

double bank_account::limit = 0;
#endif