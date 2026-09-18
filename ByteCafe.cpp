#include<iostream>
#include<fstream>
using namespace std;

class Cafe
{
public:
    int price;
};

class Beverage : public Cafe
{
public:
    void coffee()
    {
        price = 50;
    }

    void tea()
    {
        price = 30;
    }
};

class Snacks : public Cafe
{
public:
    void burger()
    {
        price = 100;
    }

    void sandwich()
    {
        price = 80;
    }
};

class Dessert : public Cafe
{
public:
    void cake()
    {
        price = 120;
    }

    void iceCream()
    {
        price = 70;
    }
};

void createFile()
{
    fstream file;

    file.open("menu.txt", ios::out);

    if(!file)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    file << "1 Coffee 50" << endl;
    file << "2 Tea 30" << endl;
    file << "3 Burger 100" << endl;
    file << "4 Sandwich 80" << endl;
    file << "5 Cake 120" << endl;
    file << "6 IceCream 70" << endl;

    file.close();
}

void displayMenu()
{
    fstream file;
    int id, price;
    char name[30];

    file.open("menu.txt", ios::in);

    if(!file)
    {
        cout << "Error opening file!" << endl;
        return;
    }

    cout << "\n================================" << endl;
    cout << "           BYTE CAFE" << endl;
    cout << "================================" << endl;

    while(file >> id >> name >> price)
    {
        cout << id << ". " << name << " - Rs." << price << endl;
    }

    file.close();
}

int main()
{
    int choice, more;
    int total = 0;

    int coffeeOrder = 0;
    int teaOrder = 0;
    int burgerOrder = 0;
    int sandwichOrder = 0;
    int cakeOrder = 0;
    int iceCreamOrder = 0;

    int id, price;
    char name[30];

    Beverage b;
    Snacks s;
    Dessert d;

    createFile();

    do
    {
        displayMenu();

        cout << "\nEnter your choice: ";
        cin >> choice;

        fstream file;

        file.open("menu.txt", ios::in);

        if(!file)
        {
            cout << "Error opening file!" << endl;
            return 0;
        }

        while(file >> id >> name >> price)
        {
            if(id == choice)
            {
                switch(choice)
                {
                    case 1:
                        b.coffee();
                        total = total + b.price;
                        coffeeOrder = 1;
                        cout << "Coffee added to bill." << endl;
                        break;

                    case 2:
                        b.tea();
                        total = total + b.price;
                        teaOrder = 1;
                        cout << "Tea added to bill." << endl;
                        break;

                    case 3:
                        s.burger();
                        total = total + s.price;
                        burgerOrder = 1;
                        cout << "Burger added to bill." << endl;
                        break;

                    case 4:
                        s.sandwich();
                        total = total + s.price;
                        sandwichOrder = 1;
                        cout << "Sandwich added to bill." << endl;
                        break;

                    case 5:
                        d.cake();
                        total = total + d.price;
                        cakeOrder = 1;
                        cout << "Cake added to bill." << endl;
                        break;

                    case 6:
                        d.iceCream();
                        total = total + d.price;
                        iceCreamOrder = 1;
                        cout << "Ice Cream added to bill." << endl;
                        break;

                    default:
                        cout << "Invalid choice!" << endl;
                }
            }
        }

        file.close();

        cout << "\nDo you want to order more?" << endl;
        cout << "1. Yes" << endl;
        cout << "0. No" << endl;
        cin >> more;

    } while(more == 1);

    cout << "\n================================" << endl;
    cout << "           BYTE CAFE" << endl;
    cout << "================================" << endl;

    cout << "Your Orders:" << endl;

    if(coffeeOrder == 1)
        cout << "Coffee" << endl;

    if(teaOrder == 1)
        cout << "Tea" << endl;

    if(burgerOrder == 1)
        cout << "Burger" << endl;

    if(sandwichOrder == 1)
        cout << "Sandwich" << endl;

    if(cakeOrder == 1)
        cout << "Cake" << endl;

    if(iceCreamOrder == 1)
        cout << "Ice Cream" << endl;

    cout << "--------------------------------" << endl;
    cout << "Total Bill: Rs." << total << endl;
    cout << "================================" << endl;
    cout << "       Thank You! Visit Again!" << endl;

    return 0;
}
