#include <iostream>

/* Types of Inheritance  (A <- B  =>  A is parent of B)
           |
           |
           |-----> Single Level Inheritance
           |                 |
           |                 |
           |                 -->      A  <--  B
           |
           |
           |-----> Multi Level Inheritance
           |                 |
           |                 |
           |                 -->      A  <--  B  <-- C
           |
           |
           |-----> Multiple inheritance
           |                 |
           |                 |
           |                 |        A  <--\
           |                 |               \
           |                 -->              ------ B
           |                                 /
           |                          C  <--/
           |
           |
           |-----> Hierarchical inheritance
           |                 |
           |                 |
           |                 |
           |                 |                /----- B
           |                 |               /
           |                 -->      A  <---------- C
           |                                 \
           |                                  \----- D
           |
           |
           ------> Hybrid inheritance
                             |
                             |
                             |                - B  <--\
                             |               /         \
                             -->      A  <---           ---- D
                                             \         /
                                              - C  <--/
*/

/*
Access Specifiers:

                |     Public      Protected       Private    |
----------------|--------------------------------------------|
Parent Class    |       y             y              y       |
                |                                            |
Derived Class   |       y             y              n       |
                |                                            |
Others          |       y             n              n       |
*/

class vehicle
{
protected:
    int mfdate;
    std::string license;
    std::string brand;

public:
    vehicle(int mf, std::string lic, std::string bran) : mfdate(mf), license(lic), brand(bran) {}
    void display()
    {
        std::cout << mfdate << license << brand;
    }
};

class car : public vehicle
{
private:
    int seats;
    int horsepower;

public:
    car(int seat, int hp, int mf, std::string lic, std::string bran) : horsepower(hp), seats(seats), vehicle(mf, lic, bran) {}
};

class bike : public vehicle
{
private:
    int speed;
    int CC;

public:
    bike(int sp, int cc, int mf, std::string lic, std::string bran) : speed(sp), CC(cc), vehicle(mf, lic, bran) {}
    void display()
    {
        std::cout << mfdate << license << brand << speed << CC;
    }
};

int main()
{
    bike C(3, 234, 2004, "dcewf342", "lolo");
    C.display();
}