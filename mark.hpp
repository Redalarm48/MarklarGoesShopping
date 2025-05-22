#ifndef MARK_HPP
#define MARK_HPP

#include<iostream>

class currency
{
    protected:
    
    double balance;
    std::string name;

    public:

    currency (double b, std::string n)
    {
        balance = b;
        name = n;
    }

    double getBa()
    {
        return balance;
    }

    virtual double to_usd()const{}
    
    ~currency(){}

    currency& operator=(double amt)
    {
        balance = amt;
        return *this;
    }

};

class usd : public currency
{
    private:

    //double to_usd = 1;

    public:

    usd(double balance= 0):currency(balance , "USD"){}

    double to_usd()const override
    {

        return balance;

    }


};

class eur : public currency
{
    private:

    //double to_usd = 1;

    public:

    eur(double balance = 0 ):currency(balance , "EUR"){}

    double to_usd()const override
    {

        return balance * 1.1;

    }


};

class irr : public currency
{
    private:

    //double to_usd = 1;

    public:

    irr(double balance = 0):currency(balance , "IRR"){}

    double to_usd()const override
    {

        return balance / 800000;

    }


};
#endif