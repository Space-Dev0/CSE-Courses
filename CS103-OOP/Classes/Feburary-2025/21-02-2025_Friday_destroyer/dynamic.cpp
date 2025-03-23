#include<iostream>

class dynamic
{
private:
    int *arr;
    int size;
public:
    dynamic(int s);
    void fill_array();
    void display();
    ~dynamic();
};

void dynamic::fill_array()
{
    std::cout << "Enter the elements: ";
    for (int i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }
}

void dynamic::display()
{
    std::cout << "Array elements are: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i]<<" ";
    }
    std::cout << "\n";
}

dynamic::dynamic(int s)
{
    arr = new int[s];
    size = s;
    std::cout << "Constructor called\n"; 
}

dynamic::~dynamic()
{
    delete arr;
    std::cout << "Destructor called\n"; 
}

int main()
{
    dynamic a(5);
    a.fill_array();
    a.display();
}