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

    complex(int r, int i) : real(r), img(i) {}

    /*                  -------> since operator precedence is from left to right
                        |        x = a + b we already know a is which object
                        |        thus we can only specify one operand            */
    complex operator+(complex &obj)
    {

        complex temp;
        temp.real = obj.real + real;
        temp.img = obj.img + img;
        return temp;
    }

    void display()
    {
        std::cout << "Complex num = " << real << " + " << "i" << img << "\n";
    }
};

int main()
{
    complex c1(2, 3), c2(-4, 5), c3;
    c3 = c1 + c2;
    std::cout << "The addition is ";
    c3.display();
}
