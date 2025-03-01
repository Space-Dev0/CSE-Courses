
/*                           Global Operator Overloading function
                            /
                           /
    Operator Overloading  -----Member Operator Overloading function
                           \
                            \
                             Friend Operator Overloading function
*/

#include <iostream>

class complex
{
public:
    int real;
    int img;
    complex()
    {
        real = 0;
        img = 0;
    }

    complex(int r, int i) : real(r), img(i) {} // better way of initialization

    void display()
    {
        std::cout << "Complex num = " << real << " + " << "i" << img << "\n";
    }
};

/* Global Operator Overloading function

   --> ReturnType
   |        ----> Keyword
   |        |   --------> Operator
   |        |   |               --> Operands
   |        |   |        _______|_______
   |        |   |       |               |     */
complex operator+(complex &obj1, complex &obj2)
{

    complex temp;
    temp.real = obj1.real + obj2.real;
    temp.img = obj1.img + obj2.img;
    return temp;
}

int main()
{
    complex c1(2, 3), c2(-4, 5), c3;
    c3 = c1 + c2;
    std::cout << "The addition is ";
    c3.display();
}