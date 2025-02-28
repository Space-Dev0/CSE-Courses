#include <iostream>

class str
{
public:
    std::string str1;
    friend str operator+(str &, str &); // friend declaration

    str(std::string st) : str1(st) {};
};

str operator+(str &obj1, str &obj2)
{
    // Creating char array str3 of length (str1.len + str2.len + 1)
    char str3[obj1.str1.length() + obj2.str1.length() + 1];
    int i;

    // Appending str1 to str3
    for (i = 0; i < obj1.str1.length(); i++)
        str3[i] = obj1.str1.at(i);

    // Appending str2 to str3
    for (int j = 0; j < obj2.str1.length(); j++, i++)
        str3[i] = obj2.str1.at(j);

    str3[i] = '\0'; // Assigning null char for C-style string

    /* assign temp object with C-style string
     * implicit conversion from char* -> std::string  */
    str temp(str3);

    return temp;
}

int main()
{
    str s1("Gello"), s2(" sfvre"), s3("\0");
    s3 = s1 + s2;
    std::cout << s3.str1 << "\n";
}