#include <iostream>

template <typename T>
class myClass
{
private:
    T data;

public:
    myClass(const T var) : data(var) {}
    friend void show(const myClass<T> &obj)
    {
        std::cout << "Data: " << obj.data << "\n";
    }
};

int main()
{
    myClass<int> in(23);
    myClass<float> fl(34.45);
    myClass<char> ch('e');
    show(in);
    show(fl);
    show(ch);
}