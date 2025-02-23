#include <iostream>

class que
{
private:
    int size;
    int *arr;
    int *front;
    int *rear;

public:
    que(int s);
    ~que();
    void insert(int a);
    void remove();
    void display();
};

que::que(int s)
{
    size = s;
    arr = new int[s];
    front = arr;
    rear = arr;
    std::cout << "Constructor called\n";
}

void que::insert(int a)
{
    if (rear == arr + (size))
    {
        std::cerr << "Que is full\n";
        return;
    }
    *rear = a;
    std::cout << "Element inserted\n";
    rear++;
}

void que::remove()
{
    if (front == rear)
    {
        std::cerr << "No elements to remove\n";
        return;
    }
    std::cout << "Removed element is: " << *front << "\n";
    front++;
}

void que::display()
{
    for (int *i = front; i != rear; i++)
    {
        std::cout << *i << " ";
    }
    std::cout << "\n";
}

que::~que()
{
    delete arr;
    std::cout << "Destructor called\n";
}

int main()
{
    std::cout << "Enter size of que: ";
    int size;
    int input;
    std::cin >> size;
    que q(size);
    while (1)
    {
        std::cout << "Enter 'i' to insert , 'd' to remove, 'p' to print, any other to exit: ";
        char c;
        std::cin >> c;
        switch (c)
        {
        case 'i':
            std::cout << "Enter element: ";
            std::cin >> input;
            q.insert(input);
            break;
        case 'd':
            q.remove();
            break;
        case 'p':
            q.display();
            break;
        default:
            exit (0);
            break;
        }
    }
}