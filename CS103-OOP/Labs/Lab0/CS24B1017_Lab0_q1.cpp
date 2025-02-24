#include <iostream>

class BankAccount
{
private:
    std::string account_number;
    std::string account_holder;
    float balance{0.0};

public:
    BankAccount(std::string ac_no, std::string ac_name, float amount)
    {
        account_number = ac_no;
        account_holder = ac_name;
        balance = amount;
    }
    void deposit(float amount)
    {
        if (amount == 0)
        {
            std::cout << "No amount deposited\n";
            return;
        }
        balance += amount;
    }
    bool withdraw(float amount)
    {
        if (balance < amount)
        {
            std::cout << "Balance insufficient\n";
            return false;
        }
        balance -= amount;
        return true;
    }
    float get_balance()
    {
        return balance;
    }
};

int main()
{
    float balance{0.0};
    std::string acc_no;
    char *acc_name = (char*)malloc(101);
    char temp;
    std::cout << "Enter Account number: ";
    std::cin >> acc_no;
    std::cin.get(temp); 
    std::cout << "Enter Account holder name: ";
    std::cin.getline(acc_name, 100);
    std::string acc_n = acc_name;
    std::cout << "Enter current balance: ";
    std::cin >> balance;
    BankAccount B(acc_no, acc_name, balance);
    while (1)
    {
        char ch;
        std::cout << "Enter 'D'-deposit 'W'-withdraw 'C'-balance, other to exit: ";
        std::cin >> ch;
        float amount;
        switch (ch)
        {
        case 'D':
            std::cout << "Enter amount: ";
            std::cin >> amount;
            B.deposit(amount);
            break;
        case 'W':
            std::cout << "Enter amount: ";
            std::cin >> amount;
            B.withdraw(amount);
            break;
        case 'C':
            std::cout << "Balance is: " << B.get_balance()<<"\n";
            break;
        default:
            exit(0);
            break;
        }
    }
}
