#include <iostream>
#include <vector>

template <typename T>
class Product
{
protected:
    T productID;
    std::string name;
    double price;
    void displayDetails()
    {
        std::cout << "Product ID: " << productID << "\n"
                  << "Name: " << name << "\n"
                  << "Price: $" << price << "\n";
    }

public:
    Product()
    {
        std::cin >> productID >> name >> price;
    }
};

class Electronics : protected Product<int>
{
private:
    int warrantyInMonths;
    std::string brand;

public:
    Electronics()
    {
        std::cin >> brand >> warrantyInMonths;
    }
    void displayDetails()
    {
        std::cout << "\n[Electronics]\n";
        Product::displayDetails();
        std::cout << "Brand: " << brand << "\n"
                  << "Warranty: " << warrantyInMonths << "\n";
    }
};

class Clothing : protected Product<std::string>
{
private:
    std::string size;
    std::string fabricType;

public:
    Clothing()
    {
        std::cin >> size >> fabricType;
    }
    void displayDetails()
    {
        std::cout << "\n[Clothing]\n";
        Product::displayDetails();
        std::cout << "Size: " << size << "\n"
                  << "Fabric Type: " << fabricType << "\n";
    }
};

int main()
{
    int num;
    std::string category;
    std::cin >> num;
    std::vector<int> EorC;
    std::vector<Electronics> ele;
    std::vector<Clothing> clt;
    for (int i = 0; i < num; i++)
    {
        std::string category;
        std::cin >> category;
        if (category == "Electronics")
        {
            EorC.push_back(1);
            Electronics E;
            ele.push_back(E);
        }
        else
        {
            EorC.push_back(0);
            Clothing C;
            clt.push_back(C);
        }
    }

    for (int i = 0; i < num; i++)
    {
        if (EorC[i] == 1)
        {
            ele[0].displayDetails();
            ele.erase(ele.begin());
        }
        else
        {
            clt[0].displayDetails();
            clt.erase(clt.begin());
        }
    }
}