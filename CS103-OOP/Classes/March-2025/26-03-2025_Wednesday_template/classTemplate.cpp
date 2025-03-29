#include <iostream>

template <typename T, typename U>
class A
{
private:
    T value;
    U value2;

public:
    A(T foo, U goo)
    {
        value = foo;
        value2 = goo;
        std::cout << "Constructor invoked\n";
    }
    void display()
    {
        std::cout << "Value is: " << value << "\n";
        std::cout << "Value 2 is: " << value2 << "\n";
    }
};

int main()
{
    int a = 2134;
    float b = 234.23;
    std::string str = "sdcfvbg";
    char c = 'C';

    A<int, int> in(a, a);
    A<float, std::string> fl(b, str);
    A<char, std::string> ch(c, str);
    A<std::string, int> st(str, a);

    in.display();
    fl.display();
    ch.display();
    st.display();
}