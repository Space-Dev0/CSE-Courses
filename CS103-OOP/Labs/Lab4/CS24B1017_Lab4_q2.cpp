#include <iostream>

struct Smartphone
{
    int Ram;
    int battery;
    Smartphone()
    {
        std::cout << "Enter Ram amount: ";
        std::cin >> Ram;
        std::cout << "Enter Battery size: ";
        std::cin >> battery;
    }
    void display()
    {
        std::cout << "Ram: " << Ram << "GB, Battery: " << battery << "mAh\n\n";
    }
};

struct Laptop
{
    std::string processor;
    int storage;
    Laptop()
    {
        std::cout << "Enter Processor: ";
        std::cin >> processor;
        std::cout << "Enter Storage: ";
        std::cin >> storage;
    }

    void display()
    {
        std::cout << "Processor: " << processor << ", Storage: " << storage << "GB\n\n";
    }
};

struct Television
{
    std::string displayType;
    int screenSize;
    Television()
    {
        std::cout << "Enter Display Type: ";
        std::cin >> displayType;
        std::cout << "Enter Screen Size: ";
        std::cin >> screenSize;
    }

    void display()
    {
        std::cout << "Screen Size: " << screenSize << " inches, Display: "
                  << displayType << "\n\n";
    }
};

template <typename T>
class Product
{
    std::string productID, name;
    double price;
    T category_Specific;

public:
    Product()
    {
        std::cout << "Enter Product ID: ";
        std::cin >> productID;
        std::string temp;
        std::getline(std::cin, temp);
        std::cout << "Enter Product name: ";
        std::getline(std::cin, name);
        std::cout << "Enter Price: ";
        std::cin >> price;
    }
    void display()
    {
        std::cout << "Product ID: " << productID << "\n";
        std::cout << "Name: " << name << "\n";
        std::cout << "Price: " << price << "\n";
    }
    T getCategorySpecific()
    {
        return category_Specific;
    }
};

int main()
{
    Product<Smartphone> P1;
    Product<Laptop> P2;
    Product<Television> P3;

    P1.display();
    P1.getCategorySpecific().display();

    P2.display();
    P2.getCategorySpecific().display();

    P3.display();
    P3.getCategorySpecific().display();
}