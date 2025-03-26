#include <iostream>

/*
                                    Polymorphism
                                         |
                                         |
                        -----------------------------------
                        |                                 |
                        v                                 v
                    Compile-time                       Runtime
                    Polymorphism                     Polymorphism
                         |                                |
        ----------------------------------                |
        |                |               |                |
        v                v               v                v
    Function         Operator         Template         Function
   Overloading      Overloading          |            Overriding
                                         |
                                --------------------
                                |                  |
                                v                  v
                            Function             Class
                            Template            Template
*/

/*
Function Template Syntax:


    template <typename T>
    FuncRtType FuncName(funcParameter1,funcParameter2 ...)
    {
        funcDefinition
    }

    - The type "T" can be used as a place holder for other types
*/

template <typename T>
T max(T a, T b)
{
    return a > b ? a : b;
}

int main()
{
    float a{12.4}, b{3.5};
    double c{234.4}, d{324.34};
    int e{12}, f{4};

    std::cout << max(a, b) << "\n"
              << max(c, d) << "\n"
              << max(e, f) << "\n";
}
