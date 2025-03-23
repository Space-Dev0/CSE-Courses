#include <iostream>

using namespace std;

void bubbleSort(int *arr, int n);

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    bubbleSort(arr, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n\n";
}

void bubbleSort(int *arr, int n)
{
    for (int i {0}; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] > arr[j])
            {
                const int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}