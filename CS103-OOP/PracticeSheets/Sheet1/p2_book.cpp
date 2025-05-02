#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

class Library;

class Book
{
    friend class Library;

protected:
    std::string title;
    std::string author;
    long ISBN;

public:
    Book()
    {
        std::cin.ignore();
        std::cout << "Enter Title: ";
        std::getline(std::cin, title);
        std::cout << "Enter Author: ";
        std::getline(std::cin, author);
        std::cout << "Enter ISBN: ";
        std::cin >> ISBN;
    }
    virtual const void display()
    {
        std::cout << "Title: " << title << "\n"
                  << "Author: " << author << "\n"
                  << "ISBN: " << ISBN << "\n";
    }

    virtual ~Book() = default;
};

class Text_Book : public Book
{
    friend class Library;

protected:
    std::string subject;

public:
    Text_Book()
    {
        std::cout << "Enter Subject: ";
        std::cin.ignore();
        std::getline(std::cin, subject);
    }
    void const display() override
    {
        Book::display();
        std::cout << "Subject: " << subject << "\n";
    }
};

class Novel : public Book
{
    friend class Library;

protected:
    std::string genre;

public:
    Novel()
    {
        std::cout << "Enter Genre: ";
        std::cin.ignore();
        std::getline(std::cin, genre);
    }
    const void display() override
    {
        Book::display();
        std::cout << "Genre: " << genre;
    }
};

class Library
{
private:
    std::vector<Book *> list_Books;

public:
    Library()
    {
        size_t numBooks{0};
        std::cout << "Enter number of Books: ";
        std::cin >> numBooks;
        for (size_t i = 0; i < numBooks; i++)
        {
            std::string type;
            std::cout << "---- Book " << i + 1 << " ----\n"
                      << "Novel or Text-Book: ";
            std::cin >> type;
            if (type == "N" || type == "n" || type == "Novel")
            {
                list_Books.push_back(new Novel());
            }
            else if (type == "T" || type == "t" || type == "Type")
            {
                list_Books.push_back(new Text_Book());
            }
            else
            {
                std::cout << "Try again!\n";
                i--;
                continue;
            }
        }
    }

    void add()
    {
        size_t numBooks{0};
        std::cout << "Enter number of Books to add: ";
        std::cin >> numBooks;
        for (size_t i = 0; i < numBooks; i++)
        {
            std::string type;
            std::cout << "Is book " << i << " Novel or Text-Book: ";
            std::cin >> type;
            if (type == "N" || type == "n" || type == "Novel")
            {

                list_Books.push_back(new Novel);
            }
            else if (type == "T" || type == "t" || type == "Type")
            {
                list_Books.push_back(new Text_Book);
            }
            else
            {
                std::cout << "Try again!\n";
                i--;
                continue;
            }
        }
    }

    void searchTitle(std::string &Title_to_search)
    {
        size_t matches{0};
        std::cout << "---- Searching for " << Title_to_search << " ----\n";
        for (auto &&i : list_Books)
        {
            if (i->title == Title_to_search)
            {

                std::cout << "Match " << ++matches << ": \n";

                Novel *nvptr = dynamic_cast<Novel *>(i);
                Text_Book *txBptr = dynamic_cast<Text_Book *>(i);

                if (nvptr != nullptr)
                {
                    std::cout << "(Novel)\n";
                    nvptr->display();
                }
                else if (txBptr != nullptr)
                {
                    std::cout << "(Text-Book)\n";
                    txBptr->display();
                }
            }
        }
        if (matches == 0)
        {
            std::cout << "---- No match found ----\n";
        }
    }
    void searchISBN(long ISBN_to_search)
    {
        size_t matches{0};
        std::cout << "---- Searching for " << ISBN_to_search << " ----\n";
        for (auto &&i : list_Books)
        {
            if (i->ISBN == ISBN_to_search)
            {

                std::cout << "Match " << ++matches << ": \n";

                Novel *nvptr = dynamic_cast<Novel *>(i);
                Text_Book *txBptr = dynamic_cast<Text_Book *>(i);

                if (nvptr != nullptr)
                {
                    std::cout << "(Novel)\n";
                    nvptr->display();
                }
                else if (txBptr != nullptr)
                {
                    std::cout << "(Text-Book)\n";
                    txBptr->display();
                }
            }
        }
        if (matches == 0)
        {
            std::cout << "---- No match found ----\n";
        }
    }

    void searchAuthor(std::string &Author_to_search)
    {
        size_t matches{0};
        std::cout << "---- Searching for " << Author_to_search << " ----\n";
        for (auto &&i : list_Books)
        {
            if (i->author == Author_to_search)
            {

                std::cout << "Match " << ++matches << ": \n";

                Novel *nvptr = dynamic_cast<Novel *>(i);
                Text_Book *txBptr = dynamic_cast<Text_Book *>(i);

                if (nvptr != nullptr)
                {
                    std::cout << "(Novel)\n";
                    nvptr->display();
                }
                else if (txBptr != nullptr)
                {
                    std::cout << "(Text-Book)\n";
                    txBptr->display();
                }
            }
        }
        if (matches == 0)
        {
            std::cout << "---- No match found ----\n";
        }
    }

    void searchGenre(std::string &Genre)
    {
        size_t matches{0};
        std::cout << "---- Searching for " << Genre << " ----\n";
        for (auto &&i : list_Books)
        {
            Novel *nvptr = dynamic_cast<Novel *>(i);
            if (nvptr != nullptr && nvptr->genre == Genre)
            {
                std::cout << "Match " << ++matches << ": \n";
                nvptr->display();
            }
        }
        if (matches == 0)
        {
            std::cout << "---- No match found ----\n";
        }
    }

    void searchSubject(std::string &Subject)
    {
        size_t matches{0};
        std::cout << "---- Searching for " << Subject << " ----\n";
        for (auto &&i : list_Books)
        {
            Text_Book *nvptr = dynamic_cast<Text_Book *>(i);
            if (nvptr != nullptr && nvptr->subject == Subject)
            {
                std::cout << "Match " << ++matches << ": \n";
                nvptr->display();
            }
        }
        if (matches == 0)
        {
            std::cout << "---- No match found ----\n";
        }
    }

    void searchType(std::string &type_to_search)
    {
        size_t matches{0};
        std::cout << "---- Searching for " << type_to_search << " ----\n";

        if (type_to_search == "t" || type_to_search == "text" || type_to_search == "T" || type_to_search == "Text-Book")
        {
            for (auto &&i : list_Books)
            {
                Text_Book *txBptr = dynamic_cast<Text_Book *>(i);

                if (txBptr != nullptr)
                {
                    std::cout << "Match " << ++matches << ": \n";
                    txBptr->display();
                }
            }
        }
        else if (type_to_search == "n" || type_to_search == "novel" || type_to_search == "N" || type_to_search == "Novel")
        {
            for (auto &&i : list_Books)
            {
                Novel *nvptr = dynamic_cast<Novel *>(i);

                if (nvptr != nullptr)
                {
                    std::cout << "Match " << ++matches << ": \n";
                    nvptr->display();
                }
            }
        }

        if (matches == 0)
        {
            std::cout << "---- No match found ----\n";
        }
    }

    void showAll()
    {
        size_t num{0};
        std::cout << "===== LIBRARY =====\n";
        for (auto &&i : list_Books)
        {
            std::cout << "---- Book " << num + 1 << " ----\n";
            Novel *nvptr = dynamic_cast<Novel *>(i);
            Text_Book *txBptr = dynamic_cast<Text_Book *>(i);

            if (nvptr != nullptr)
            {
                std::cout << "(Novel)\n";
                nvptr->display();
            }
            else if (txBptr != nullptr)
            {
                std::cout << "(Text-Book)\n";
                txBptr->display();
            }
        }
    }

    void search()
    {
        int n;
        while (1)
        {
            std::cout << "Search using :\n"
                      << "1. Title\n"
                      << "2. Author\n"
                      << "3. ISBN\n"
                      << "4. Genre\n"
                      << "5. Subject\n"
                      << "6. Type - Novel/Text-Book\n"
                      << "Enter: ";
            std::cin >> n;
            if (n > 6 || n < 1)
            {
                std::cout << "Try again!\n";
                continue;
            }
            break;
        }

        switch (n)
        {
        case 1:
        {
            std::string title_to_search;
            std::cout << "Enter Title: ";
            std::getline(std::cin, title_to_search);
            searchTitle(title_to_search);
            break;
        }
        case 2:
        {
            std::string author_to_search;
            std::cout << "Enter Author: ";
            std::getline(std::cin, author_to_search);
            searchAuthor(author_to_search);
            break;
        }
        case 3:
        {
            long ISBN_to_search;
            do
            {
                std::cout << "Enter ISBN: ";
            } while (!(std::cin >> ISBN_to_search) && std::cout << "Try again!\n");
            searchISBN(ISBN_to_search);
            break;
        }
        case 4:
        {
            std::string genre_to_search;
            std::cout << "Enter Genre: ";
            std::getline(std::cin, genre_to_search);
            searchGenre(genre_to_search);
            break;
        }
        case 5:
        {
            std::string sub_to_search;
            std::cout << "Enter Subject: ";
            std::getline(std::cin, sub_to_search);
            searchSubject(sub_to_search);
            break;
        }
        case 6:
        {
            std::string type_to_search;
            std::cout << "Enter Type: ";
            std::getline(std::cin, type_to_search);
            searchType(type_to_search);
            break;
        }
        default:
            break;
        }
    }
};

int main()
{
    Library L;
    L.search();
    L.showAll();
    L.add();
}