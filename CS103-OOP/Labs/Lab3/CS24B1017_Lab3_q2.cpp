#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::string;
using std::vector;

class Matrices
{
protected:
    vector<vector<int>> data1;
    vector<vector<int>> data2;

public:
    Matrices() {}
    Matrices(int size)
    {
        for (int i = 0; i < size; i++)
        {
            vector<int> temp1(size);
            vector<int> temp2(size);
            data1.push_back(temp1);
            data2.push_back(temp2);
        }
    }
    void input()
    {

        cout << "Enter matrix1 : ";
        for (int i = 0; i < data1.size(); i++)
        {
            for (int j = 0; j < data1.size(); j++)
                cin >> data1[i][j];
        }
        cout << "Enter matrix2 : ";
        for (int i = 0; i < data2.size(); i++)
        {
            for (int j = 0; j < data2.size(); j++)
                cin >> data2[i][j];
        }
    }
};

class privateOperation : virtual private Matrices
{
public:
    privateOperation()
    {
        input();
    }
    void add()
    {
        cout << "\nPrivate inheritance: \n";
        cout << "A + B:\n";
        for (int i = 0; i < data1.size(); i++)
        {
            for (int j = 0; j < data1.size(); j++)
            {
                if (data1[i][j] + data2[i][j] < 0)
                    cout << "\b";
                cout << "\t" << data1[i][j] + data2[i][j];
            }
            cout << "\n";
        }
    }
    void subtract()
    {
        cout << "\nA - B:\n";
        for (int i = 0; i < data1.size(); i++)
        {
            for (int j = 0; j < data1.size(); j++)
            {
                if (data1[i][j] - data2[i][j] < 0)
                    cout << "\b";
                cout << "\t" << data1[i][j] - data2[i][j];
            }
            cout << "\n";
        }
    }
    void multiply()
    {
        cout << "\nA * B: \n";
        for (int i = 0; i < data1.size(); i++)
        {
            for (int j = 0; j < data1.size(); j++)
            {
                int sum{0};
                for (int k = 0; k < data1.size(); k++)
                {
                    sum += data1[i][k] * data2[k][j];
                }

                cout << "\t" << sum;
            }
            cout << "\n";
        }
    }
};

class publicOperation : virtual public Matrices
{
public:
    void add()
    {
        cout << "\nPublic inheritance: \n";
        cout << "A + B:\n";
        for (int i = 0; i < data1.size(); i++)
        {
            for (int j = 0; j < data1.size(); j++)
            {
                if (data1[i][j] + data2[i][j] < 0)
                    cout << "\b";

                cout << "\t" << data1[i][j] + data2[i][j];
            }
            cout << "\n";
        }
    }
    void subtract()
    {
        cout << "\nA - B:\n";
        for (int i = 0; i < data1.size(); i++)
        {
            for (int j = 0; j < data1.size(); j++)
            {
                if (data1[i][j] - data2[i][j] < 0)
                    cout << "\b";

                cout << "\t" << data1[i][j] - data2[i][j];
            }
            cout << "\n";
        }
    }
    void multiply()
    {
        cout << "\nA * B: \n";
        for (int i = 0; i < data1.size(); i++)
        {
            for (int j = 0; j < data1.size(); j++)
            {
                int sum{0};
                for (int k = 0; k < data1.size(); k++)
                {
                    sum += data1[i][k] * data2[k][j];
                }
                if (sum < 0)
                    cout << "\b";
                cout << "\t" << sum;
            }
            cout << "\n";
        }
    }
};

class operation : private privateOperation, private publicOperation
{

public:
    operation(int size) : Matrices(size)
    {
        privateOperation::add();
        privateOperation::subtract();
        privateOperation::multiply();
        publicOperation::add();
        publicOperation::subtract();
        publicOperation::multiply();
    }
};

int main()
{
    int size;
    cout << "Enter size: ";
    cin >> size;
    operation O(size);
}
