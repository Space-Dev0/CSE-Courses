#include <iostream>

class Book
{
protected:
    std::string title;
    std::string author;
    long ISBN;

public:
    Book()
    {
        std::cout << "Enter Title: ";
        std::getline(std::cin, title);
        std::cout << "Enter Author: ";
        std::getline(std::cin, author);
        std::cout << "Enter ISBN: ";
    }
    void display()
    {
        std::cout << "Title: " << title << "\n"
                  << "Author: " << author << "\n"
                  << "ISBN: " << ISBN << "\n";
    }
};

class Text_Book : protected Book
{
protected:
    std::string subject;

public:
    Text_Book()
    {
        std::cout << "Enter Subject: ";
        std::getline(std::cin, subject);
    }
    void display()
    {
        Book::display();
        std::cout << "Subject: " << subject;
    }
};

class Novel : protected Book
{
protected:
    std::string genre;

public:
    Novel()
    {
        std::cout << "Enter Genre: ";
        std::getline(std::cin, genre);
    }
    void display()
    {
        Book::display();
        std::cout << "Genre: " << genre;
    }
};

int main()
{
    Novel N;
    Text_Book T;
    N.display();
    T.display();
}