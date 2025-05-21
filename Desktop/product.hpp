#ifndef PRODUCT_HPP
#define PRODUCT_HPP

#include <iostream>
#include <iomanip>

class Product
{

    protected :

        std::string Name;
        double Price;
        int Amount;
        std::string Unit;

    public :

        Product(std::string name , double price , int amount , std::string unit){}

        double getAmount();

        void reduceAmount(int removal);

        void display()const;

        friend std::ostream& operator<<(std::ostream& output , const Product& item);

};

class Fruit : public Product
{

    Fruit(std::string name , int amount , double price);

};

class Seasoning : public Product
{

    Seasoning(std::string name , int amount , double price);

};

class Snack : public Product
{

    Snack(std::string name , int amount , double price);
};

#endif