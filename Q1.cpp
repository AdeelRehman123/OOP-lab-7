#include <iostream>
using namespace std;

class Account
{
protected:
    int accountNumber;
    double balance;
    string accountHolderName;
    string accountType;

public:
    Account(int accNum, double bal, string name, string type)
        : accountNumber(accNum), balance(bal), accountHolderName(name), accountType(type) {}

    virtual ~Account() {}

    virtual void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
            cout << "Deposited: " << amount << ". New Balance: " << balance << endl;
        }
        else
        {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    virtual void withdraw(double amount)
    {
        if (amount > 0 && amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawn: " << amount << ". New Balance: " << balance << endl;
        }
        else
        {
            cout << "Invalid withdrawal amount or insufficient funds!" << endl;
        }
    }

    virtual void calculateInterest()
    {
        cout << "Interest calculation depends on account type." << endl;
    }

    virtual void printStatement() const
    {
        cout << "Account Number: " << accountNumber << ", Holder: " << accountHolderName
             << ", Balance: " << balance << ", Type: " << accountType << endl;
    }

    void getAccountInfo() const
    {
        printStatement();
    }
};

class SavingsAccount : public Account
{
private:
    double interestRate;
    double minimumBalance;

public:
    SavingsAccount(int accNum, double bal, string name, double rate, double minBal)
        : Account(accNum, bal, name, "Savings"), interestRate(rate), minimumBalance(minBal) {}

    void calculateInterest() override
    {
        double interest = balance * (interestRate / 100);
        cout << "Interest Earned: " << interest << endl;
    }

    void withdraw(double amount) override
    {
        if (balance - amount >= minimumBalance)
        {
            Account::withdraw(amount);
        }
        else
        {
            cout << "Cannot withdraw. Minimum balance requirement not met!" << endl;
        }
    }
};

class CheckingAccount : public Account
{
public:
    CheckingAccount(int accNum, double bal, string name)
        : Account(accNum, bal, name, "Checking") {}

    void printStatement() const override
    {
        cout << "Checking Account Statement: ";
        Account::printStatement();
    }
};

class FixedDepositAccount : public Account
{
private:
    double fixedInterestRate;
    int maturityDate;

public:
    FixedDepositAccount(int accNum, double bal, string name, double rate, int maturity)
        : Account(accNum, bal, name, "Fixed Deposit"), fixedInterestRate(rate), maturityDate(maturity) {}

    void calculateInterest() override
    {
        double interest = balance * (fixedInterestRate / 100);
        cout << "Fixed Deposit Interest Earned: " << interest << endl;
    }

    void withdraw(double amount) override
    {
        if (maturityDate > 0)
        {
            cout << "Cannot withdraw before maturity date (" << maturityDate << " months remaining)!" << endl;
        }
        else
        {
            Account::withdraw(amount);
        }
    }
};

int main()
{
    SavingsAccount sa(101, 5000, "Alice", 3.5, 1000);
    CheckingAccount ca(102, 3000, "Bob");
    FixedDepositAccount fda(103, 10000, "Charlie", 5.0, 12);

    cout << "\n--- Savings Account Operations ---\n";
    sa.deposit(2000);
    sa.withdraw(4000);
    sa.calculateInterest();
    sa.printStatement();

    cout << "\n--- Checking Account Operations ---\n";
    ca.deposit(1000);
    ca.withdraw(2000);
    ca.printStatement();

    cout << "\n--- Fixed Deposit Account Operations ---\n";
    fda.calculateInterest();
    fda.withdraw(5000);
    fda.printStatement();

    return 0;
}
