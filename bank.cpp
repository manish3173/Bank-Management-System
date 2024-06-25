#include <iostream>
#include <map>
#include <string>

using namespace std;

class Account {
private:
    int accountNumber;
    string name;
    double balance;

public:
    // Default constructor
    Account() : accountNumber(0), name(""), balance(0.0) {}

    Account(int accNum, string accName, double initialBalance) {
        accountNumber = accNum;
        name = accName;
        balance = initialBalance;
    }

    int getAccountNumber() {
        return accountNumber;
    }

    string getName() {
        return name;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            return true;
        } else {
            return false;
        }
    }
};

class Bank {
private:
    map<int, Account> accounts;

public:
    void createAccount(int accountNumber, string name, double initialBalance) {
        Account newAccount(accountNumber, name, initialBalance);
        accounts[accountNumber] = newAccount;
        cout << "Account created successfully.\n";
    }

    void transferMoney(int fromAccount, int toAccount, double amount) {
        if (accounts.find(fromAccount) != accounts.end() && accounts.find(toAccount) != accounts.end()) {
            if (accounts[fromAccount].withdraw(amount)) {
                accounts[toAccount].deposit(amount);
                cout << "Transfer successful.\n";
            } else {
                cout << "Insufficient balance in the source account.\n";
            }
        } else {
            cout << "One or both account numbers are invalid.\n";
        }
    }

    void checkAmount(int accountNumber) {
        if (accounts.find(accountNumber) != accounts.end()) {
            cout << "Account balance for account number " << accountNumber << " is " << accounts[accountNumber].getBalance() << endl;
        } else {
            cout << "Invalid account number.\n";
        }
    }
};

int main() {
    Bank bank;
    int choice, accountNumber;
    string name;
    double amount;
    int fromAccount, toAccount;

    while (true) {
        cout << "\n1. Create Account\n2. Transfer Money\n3. Check Amount\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter initial balance: ";
                cin >> amount;
                bank.createAccount(accountNumber, name, amount);
                break;

            case 2:
                cout << "Enter source account number: ";
                cin >> fromAccount;
                cout << "Enter destination account number: ";
                cin >> toAccount;
                cout << "Enter amount to transfer: ";
                cin >> amount;
                bank.transferMoney(fromAccount, toAccount, amount);
                break;

            case 3:
                cout << "Enter account number: ";
                cin >> accountNumber;
                bank.checkAmount(accountNumber);
                break;

            case 4:
                cout << "Exiting...\n";
                return 0;

            default:
                cout << "Invalid choice.\n";
                break;
        }
    }

    return 0;
}
