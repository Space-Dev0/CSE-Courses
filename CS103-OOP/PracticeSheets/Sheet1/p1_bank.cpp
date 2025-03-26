#include <iostream>

class Bank_Account
{
protected:
    std::string account_number;
    double balance{0};

public:
    Bank_Account()
    {
        std::cout << "Enter account number: ";
        std::cin >> account_number;
        std::cout << "Enter current balance: ";
        std::cin >> balance;
    }
    void deposit(double amount)
    {
        balance += amount;
    }
    void withdraw(double amount)
    {
        if (amount > balance)
        {
            std::cerr << "Balance inefficient!\n";
            return;
        }
        balance -= amount;
    }
    void displayAcNum()
    {
        std::cout << "Account number: " << account_number << "\n";
    }
    void displayBalance()
    {
        std::cout << "Balance: " << balance << "\n";
    }
};

class Savings_Account : public Bank_Account
{
protected:
    double Interest_rate{0};

public:
    Savings_Account()
    {
        std::cout << "Enter interest rate: ";
        std::cin >> Interest_rate;
    }
    void addInterest()
    {
        balance += balance * Interest_rate;
    }
};

class Current_Account : public Bank_Account
{
protected:
    double overdraftLimit{0};

public:
    Current_Account()
    {
        std::cout << "Enter overdraft limit: ";
        std::cin >> overdraftLimit;
    }
    void withdraw(double amount)
    {
        if (balance + overdraftLimit < amount)
        {
            std::cerr << "Overdraft limit exceeded!\n";
            return;
        }
        balance -= amount;
    }
};

int main()
{
    Savings_Account S;
    Current_Account C;

    while (1)
    {
        char aType, op;
        double amount;
        std::cout << "\nSelect Account Savings or Current (S/C): ";
        std::cin >> aType;

        if (aType != 'S' && aType != 'C')
            break;

        std::cout << "Withdraw or Deposit (W/D): ";
        std::cin >> op;
        std::cout << "Enter amount: ";
        std::cin >> amount;
        if (aType == 'S')
        {
            if (op == 'D')
                S.deposit(amount);
            else
                S.withdraw(amount);
            S.displayAcNum();
            S.displayBalance();
        }
        else
        {
            if (op == 'D')
                C.deposit(amount);
            else
                C.withdraw(amount);
            C.displayAcNum();
            C.displayBalance();
        }
    }
}