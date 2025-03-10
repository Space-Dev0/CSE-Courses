#include <iostream>
#include <cmath>
#include <bits/stdc++.h>

class Area
{
public:
    double calculateArea(double radius)
    {
        return M_PI * radius * radius;
    }

    double calculateArea(double length, double width)
    {
        return length * width;
    }

    double calculateArea(double a, double b, double c)
    {
        const double s{(a + b + c) / 2};
        return std::sqrt(s * (s - a) * (s - b) * (s - c));
    }

    bool calculateArea(int x)
    {
        for (int i = 2; i < std::sqrt(x); i++)
            if (x % i == 0)
                return false;
        return true;
    }
};

int main()
{
    double r, len, br, a, b, c;
    int p;

    std::cout << "Enter radius: ";
    std::cin >> r;
    std::cout << "Enter length: ";
    std::cin >> len;
    std::cout << "Enter breath: ";
    std::cin >> br;
    std::cout << "Enter a: ";
    std::cin >> a;
    std::cout << "Enter b: ";
    std::cin >> b;
    std::cout << "Enter c: ";
    std::cin >> c;
    std::cout << "Enter num: ";
    std::cin >> p;

    Area A;
    std::cout << std::setprecision(4);
    std::cout << "Circle Area :" << A.calculateArea(r) << "\n";
    std::cout << "Rectangle Area: " << A.calculateArea(len, br) << "\n";
    std::cout << "Triangle Area :" << A.calculateArea(a, b, c) << "\n";
    std::cout << p << (A.calculateArea(p) ? " is a Prime Number" : " is not a Prime Number") << "\n";
}