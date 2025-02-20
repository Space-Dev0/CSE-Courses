#include <iostream>

class car
{
public:
    std::string brand;
    std::string model;
    float speed;
    int seats;
    int year;
    car()
    {
        // brand = "Toyota";
        // model = "Fortuner";
        // speed = 120.34;
        // seats = 4;
        // year = 1324;
        // std::cout << "Default constructor is evoked\n";
        std::cout << "Enter Brand: ";
        std::cin >> brand;
        std::cout << "Enter Model: ";
        std::cin >> model;
        std::cout << "Enter speed: ";
        std::cin >> speed;
        std::cout << "Enter seats: ";
        std::cin >> seats;
        std::cout << "Enter year: ";
        std::cin >> year;

    }
    void display()
    {
        std::cout << brand << "\t" << model << "\t" << speed << "\t" << seats << "\t" << year << "\n";
    }
    car(std::string a, std::string b, float c, int d, int e)
    {
        brand = a;
        model = b;  
        speed = c;
        seats = d;
        year = e;
        std::cout << "Parametrized constructor is evoked\n";
    }
};

int main()
{
    car c;
    car c1("Mustang","M5",125.3,45,34);
    c.display();
    c1.display();
}