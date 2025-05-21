#include "product.hpp"

Product::Product(std::string name , double price , int amount , std::string unit) : Name(name) , Price(price) , Amount(amount) , Unit(unit)
        {

            if(Amount < 0)
            {

                Amount = 0;

            }

        }

double Product::getAmount()
        {

            return Amount;

        }



void Product::reduceAmount(int removal)
        {

            Amount -= removal;

        }

void Product::display()const
        {

            std::cout << Name << " " << std::fixed << std::setprecision(2) << Price << " " << Unit << "\n";

        }

std::ostream& operator<<(std::ostream& output , const Product& item)
        {

            output << item.Name << " : " << item.Price << " " << item.Unit;
            return output; 

        }

Fruit::Fruit(std::string name , int amount , double price) : Product(name , price , amount , "kg"){}

Seasoning::Seasoning(std::string name , int amount , double price) : Product(name , price , amount , "g"){}

Snack::Snack(std::string name , int amount , double price) : Product(name , price , amount , "Package"){}