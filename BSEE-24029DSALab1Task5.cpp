// BSEE-24029DSALab1Task5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
class BankAccount {
public:
    int accountNumber;
    string accountHolderName;
    double balance;
    string accountType;


    BankAccount(int accountNumber, string accountHolderName, double balance, string accountType) {
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = balance;
        this->accountType = accountType;
    }
    void deposit(int amount) {

        balance = amount + balance;
        cout << "Deposited Amount:" << amount << endl;;
    }
    void withdraw(int amount) {
        if (balance >= amount) {
            balance = balance - amount;
            cout << "Amount Withdrawn:" << amount << endl;;
        }
        else
            cout << "Invalid Amount or Insufficient Balance" << endl;
    }
    void displayAccountinfo() {
        cout << "Account number:" << accountNumber << endl;
        cout << "Account HolderName:" << accountHolderName << endl;
        cout << "Balance:" << balance << endl;
        cout << "Account Type:" << accountType << endl;
    }
    double getBalance() {
        return balance;
    }
};
int main()
{
    BankAccount a1(001, "Musa Kaleem", 100000, "Saving");

    double a;
    cout << "Enter the amount to deposit:" << endl;
    cin >> a;
    a1.deposit(a);
    double b;
    cout << "Enter the amount to be withdrawn:" << endl;
    cin >> b;
    a1.withdraw(b);
    a1.displayAccountinfo();
    a1.getBalance();


}
