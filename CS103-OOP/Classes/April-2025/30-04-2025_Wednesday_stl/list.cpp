#include <iostream>
#include <list>

/*
 *
 *    Index   0 1 2 3 4 5 6 ... n
 *    Array = [][][][][][][]...[]
 *            |_________________|  Here we only store address of first element
 *                    |
 *                    V
 *            Contiguous Memory
 *
 *
 *    Singly-linked List:
 *
 *    Index         0            1            2                  n
 *               | Data |---->| Data |---->| Data |----> ... |  Data   |
 *    Structure  |ptr->2|  |  |ptr->3|  |  |ptr->4|   |      |ptr->NULL|
 *                  |      |____________|_____________|           |
 *                  V                   V                         V
 *                Head            Single links                  Tail
 *
 *
 *    Doubly-linked List: (std::list is a doubly linked list)
 *
 *    Index           0              1            2                  n
 *               |   Data  |---->| Data |---->| Data |----> ... |  Data   |
 *    Structure  |ptr->NULL|     |ptr->1|     |ptr->2|          |ptr->n-1 |
 *               |  ptr->2 |<----|ptr->4|<----|ptr->4|<---- ... |ptr->NULL|
 *                    |       |____________|_____________|           |
 *                    V                    V                         V
 *                   Head             Double links                  Tail
 *
 *
 */

int main()
{

    std::list<int> L1;

    L1.push_back(10);
    L1.push_back(11);
    L1.push_back(12);
    L1.push_back(13);

    std::cout << "Init List: ";
    for (auto &&i : L1)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "Size: " << L1.size();
    std::cout << "\n";

    std::cout << "Element at back: " << L1.back() << "\n";
    std::cout << "Element at front: " << L1.front() << "\n";

    std::cout << "Popping front and back \n";

    L1.pop_back();
    L1.pop_front();

    std::cout << "New element at back: " << L1.back() << "\n";
    std::cout << "New element at front: " << L1.front() << "\n";

    L1.push_back(13);
    L1.push_front(10);

    for (auto &&i : L1)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";

    std::cout << "Reversing: \n";

    L1.reverse();

    for (auto &&i : L1)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "Pushing -1, 0: \n";

    L1.push_back(-1);
    L1.push_back(0);

    for (auto &&i : L1)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "Sorting: \n";

    L1.sort();

    for (auto &&i : L1)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "Pushing 2 10s: \n";

    L1.push_back(10);
    L1.push_back(10);

    for (auto &&i : L1)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";

    L1.unique();

    std::cout << "Unique: \n";

    for (auto &&i : L1)
    {
        std::cout << i << " ";
    }

    std::cout << "\n";

    std::cout << "Addresses: \n";

    for (auto &&i : L1)
    {
        std::cout << &i << "\n";
    }

    std::cout << "Init list 2:\n";

    std::list<int> L2 = {0, -1, 311, 5};

    for (auto &&i : L2)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "Sorting list 2: \n";
    L2.sort();

    for (auto &&i : L2)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "Merging: \n";

    L1.merge(L2);

    for (auto &&i : L1)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";

    std::cout << "Checking if L2 is empty: \n";
    std::cout << std::boolalpha;
    std::cout << L2.empty() << "\n";
}