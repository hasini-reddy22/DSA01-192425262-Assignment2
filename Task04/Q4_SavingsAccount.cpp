
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class SavingsAccount
{
private:
    int accountNumber;
    double balance;

    static const int CAPACITY = 10;

    struct Transaction
    {
        string type;
        double amount;
        double remainingBalance;
    };

    Transaction transactions[CAPACITY];
    int count;
    int start;

    // Inline member function
    void addTransaction(string type, double amount)
    {
        int position;

        if (count < CAPACITY)
        {
            position = (start + count) % CAPACITY;
            count++;
        }
        else
        {
            // Overwrite the oldest transaction
            position = start;
            start = (start + 1) % CAPACITY;
        }

        transactions[position] =
            {type, amount, balance};
    }

public:
    // Constructor defined inside the class
    SavingsAccount(int accNo, double initialBalance)
    {
        accountNumber = accNo;
        balance = initialBalance;
        count = 0;
        start = 0;
    }

    // Inline getter
    double getBalance() const
    {
        return balance;
    }

    void deposit(double amount);
    void withdraw(double amount);
    void miniStatement() const;
};

// Deposit function defined outside the class
void SavingsAccount::deposit(double amount)
{
    if (amount <= 0)
    {
        cout << "Invalid deposit amount!\n";
        return;
    }

    balance += amount;
    addTransaction("Deposit", amount);

    cout << "Deposited: Rs. " << amount << endl;
}

// Withdraw function defined outside the class
void SavingsAccount::withdraw(double amount)
{
    if (amount <= 0 || amount > balance)
    {
        cout << "Invalid withdrawal!\n";
        return;
    }

    balance -= amount;
    addTransaction("Withdraw", amount);

    cout << "Withdrawn: Rs. " << amount << endl;
}

// Mini-statement function defined outside the class
void SavingsAccount::miniStatement() const
{
    cout << "\n========== SAVINGS ACCOUNT ==========\n";

    cout << "Account Number: " << accountNumber << endl;
    cout << "Current Balance: Rs. "
         << fixed << setprecision(2) << balance << endl;

    cout << "\nLast " << count << " Transactions:\n";
    cout << "---------------------------------------------\n";

    cout << left << setw(12) << "Type"
         << setw(12) << "Amount"
         << "Balance\n";

    cout << "---------------------------------------------\n";

    for (int i = 0; i < count; i++)
    {
        int position = (start + i) % CAPACITY;

        cout << left << setw(12)
             << transactions[position].type
             << setw(12) << transactions[position].amount
             << transactions[position].remainingBalance
             << endl;
    }

    cout << "---------------------------------------------\n";
}

int main()
{
    SavingsAccount account(1001, 1000.00);

    cout << "SAVINGS ACCOUNT MINI-STATEMENT\n";
    cout << "Initial Balance: Rs. "
         << account.getBalance() << "\n\n";

    // Perform 11 transactions
    for (int i = 1; i <= 11; i++)
    {
        account.deposit(i * 100);
    }

    cout << "\nAfter adding 11 transactions,";
    cout << "\nthe oldest transaction is automatically discarded.";

    account.miniStatement();

    return 0;
}
