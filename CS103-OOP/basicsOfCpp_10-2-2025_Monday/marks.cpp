#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cout << "Enter no. of Students: ";
    cin >> n;
    int arr[n][3];
    string name[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter data for student " << i + 1 << " :\n";
        cout << "Enter student name: ";
        cin >> name[i];
        for (int j = 0; j < 3; j++)
        {
            cout << "Enter marks for Subject " << j + 1 << " :";
            cin >> arr[i][j];
        }
        cout << "\n";
    }

    for (int i = 0; i < n; i++)
    {
        float avg;
        int sum = 0;
        
        cout << "\nAverage for " << name[i] << " is: ";
        
        for (int j = 0; j < 3; j++)
            sum += arr[i][j];
        
        avg = (float)sum / 3;
        cout << avg << "\n";

        if (avg >= 60)
            cout << "Class 1!\n";
        else if (avg >= 40)
            cout << "Class 2!\n";
        else if (avg >= 30)
            cout << "Class 3!\n";
        else
            cout << "Fail\n";
    }
}