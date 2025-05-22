#include <iostream>
#include "bank.hpp"
#include "mark.hpp"
#include "Desktop/product.hpp"

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

            output << item.Name << " : " << item.Price << "USD" << " " << item.Amount << " " << item.Unit;
            return output; 

        }


std::string app()
{

    static int freeItem = 0;
    int cnt = 0;

    Product items[100];

    for(Product& index : items)
    {
        index.getterN() = " ";
    }

    Fruit sib("sib" , 10 , 100);
    items[0] = sib;
    
    currency* bal = nullptr;
    currency* bal2 = nullptr;
    currency* bal3 = nullptr;

    bal = new irr(900000000);
    bal2 = new usd(500000);
    bal3 = new eur(50000);



    organisation cashier(bal2 , "cashier");
    personal customer(bal , "customer");
    personal customer2(bal3 , "customer");

    std::string request;
    int role;
    while(true)
    {
    std::cout << "enter your role (cashier or customer or no to exit) : ";

    std::cin >> request;

    if (request == "no")
    {
        return "no";
    }
    else if(request == "cashier")
    {
        role = 1;
    }
    else if(request == "customer")
    {
        role = 2;
    }
    else
    {
        std::cout << "you should enter either cashier or customer\n";
        return "no";
    }
    if(role == 1)
    {
    while(true)
    {
        int choice;
        std::cout << "you are the cashier\n your commands are :\n 1.add item \n 2.deposit \n 3.withdraw \n 4.balance \n 5.exit \n\n enter the number : ";
        std::cin >> choice;

        if(choice == 1)
        {   

            std::string item;
            std::string name;

            for(Product& index : items)
            {
                if(index.getterN() == " ")
            {
                    double price;
                    int amount;
                    std::cout << "first decide waht type you are adding (fruit / seasoning / snack) \n";
                    std::cin >> item;
                    std::cout << "enter the name : ";
                    std::cin >> name;
                    std::cout << "enter the price : ";
                    std::cin >> price;
                    std::cout << "enter the amount : ";
                    std::cin >> amount;
                    if(item == "fruit")
                    {
                        index = Fruit(name , price , amount);
                        std::cout << "item added\n";
                    }
                    else if(item == "seasoning")
                    {   
                        index = Seasoning(name , price , amount);
                        std::cout << "item added\n";
                    }
                    else if(item == "snack")
                    {
                        index = Snack(name , price , amount);
                        std::cout << "item added\n";
                    }
                    else
                    {
                        std::cout << "this type doesnt exist!!!\n";
                    }
            break;
            }
        }

        }
        else if(choice == 2)
        {
            double deposit;
            std::cout << "enter the amount you want to deposit";
            std::cin >> deposit;
            cashier.deposit(deposit);
        }
        else if(choice == 3)
        {
            double withdraw;
            std::cout << "enter the amount you want to withdraw";
            std::cin >> withdraw;
            cashier.withdraw(withdraw);
        }
        else if(choice == 4)
        {
            std::cout << cashier.getBalance() << "\n";
        }
        else if(choice == 5)
        {
            std::cout << "you have exited from cashier's account\n";
            break;
        }
    }
    }
    if(role == 2)
    {
    while(true)
    {
        int choice;
        std::cout << "you are the coustomer\n your commands are :\n 1.buy item \n 2.deposit \n 3.withdraw \n 4.balance \n 5.display all items \n 6.exit \n\n enter the number : ";
        std::cin >> choice;

        if(choice == 1)
        {
            bool search = false;
            std::string item;
            int number ;
            std::cout << "which item do you want to buy : ";
            std::cin >> item;
            std::cout << "how many : ";
            std::cin >> number;
            for(auto& index : items)
            {
                if(index.getterN() == item )
                {
                    if(customer.getBalance() >= index.getterP() * number && number <= index.getterA())
                    {
                        search = true;
                        customer.withdraw(index.getterP());
                        index.reduceAmount(number);
                        freeItem += number;
                        if(freeItem / 5 > 0)
                        {
                            cnt = freeItem / 5 > 0;
                            std::cout << "you have recived " << cnt << " free items\n";
                            index.reduceAmount(cnt);
                        }
                        }
                        else
                        {
                            std::cout << "not enough money or item\n";
                    }
                    break;
                }

            }
            if(!search)
            {
                std::cout << "item not found!!!!\n";
            }
        }
        else if(choice == 2)
        {
            double deposit;
            std::cout << "enter the amount you want to deposit";
            std::cin >> deposit;
            customer.deposit(deposit);
        }
        else if(choice == 3)
        {
            double withdraw;
            std::cout << "enter the amount you want to withdraw";
            std::cin >> withdraw;
            customer.withdraw(withdraw);
        }
        else if(choice == 4)
        {
            std::cout << customer.getBalance() << "\n";
        }
        else if(choice == 5)
        {
            for(auto& index : items)
            {
                if(index.getterN() != " " )
                {
                    std::cout << index << "\n";
                }
            }
        }
        else if(choice == 6)
        {
            std::cout << "you have exited from cashier's account\n";
            break;
        }
    }
    }

    }
}



