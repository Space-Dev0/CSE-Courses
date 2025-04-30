#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<std::string> sentence;
    std::cout << "Enter sentence: ";
    std::string word;
    while (std::cin >> word)
    {
        sentence.push_back(word);
        }

    std::reverse(sentence.begin(), sentence.end());

    for (auto &&i : sentence)
    {
        std::cout << i << " ";
    }
}