#include <iostream>

template <typename T>
void sort(T arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        T temp{arr[i]};
        int j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
            arr[j + 1] = temp;
        }
    }
}

int main()
{
    int iarr[] = {1, 4, 0, -2, 4};
    float farr[] = {1, 4.5, -43, 7.6};
    char carr[] = {'a', '0', '-', 'b'};

    sort(iarr, 5);
    sort(farr, 4);
    sort(carr, 4);

    for (int i = 0; i < 5; i++)
        std::cout << iarr[i] << " ";
    std::cout << "\n";

    for (int i = 0; i < 4; i++)
        std::cout << farr[i] << " ";
    std::cout << "\n";

    for (int i = 0; i < 4; i++)
        std::cout << carr[i] << " ";
    std::cout << "\n";
}