#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <iostream>
#include <iomanip>

class Product
{

    private :

        std::string Name;
        double Price;
        int Amount;
        std::string Unit ;

    public :

    Product(std::string name = " " , double price = 0 , int amount = 0 , std::string unit = " ") : Name(name) , Price(price) , Amount(amount) , Unit(unit)
        {

            if(Amount < 0)
            {   

                Amount = 0;

            }

        }

        std::string getterN()
        {
            return Name;
        }
        double& getterP()
        {
            return Price;
        }
        int& getterA()
        {
            return Amount;
        }


        double getAmount();

        void reduceAmount(int removal);

        void display()const;

        friend std::ostream& operator<<(std::ostream& output , const Product& item);

};

class Fruit : public Product
{
    public:
    Fruit(std::string name = " ", int amount = 0 , double price = 0) : Product(name , price , amount , "kg"){}

};

class Seasoning : public Product
{
    public:
    Seasoning(std::string name  = " ", int amount = 0, double price = 0) : Product(name , price , amount , "g"){}

};

class Snack : public Product
{
    public: 
    Snack(std::string name = " ", int amount = 0, double price = 0) : Product(name , price , amount , "Package"){}
};

#endif