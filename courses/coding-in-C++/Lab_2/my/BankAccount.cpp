#include "BankAccount.h"

void BankAccount::setOwner(std::string& ownerName)
{
    getline(std::cin, owner);
    return;
}

std::string BankAccount::getOwner(){
    return owner;
}

void BankAccount::deposit(double amount)
{
    balance += amount;
    return;
}

void BankAccount::withdraw(double amount)
{
    if (balance >= amount)
    {
        balance -= amount;
    }
    else 
    {
        std::cout << "\n\n\tBalance is insufficient!";
    }

    return;
}

double BankAccount::getBalance() const //const at the end defines that the funcion can't change anything and only read
{
    return balance;
}

void BankAccount::getAccountInfo() const
{
    std::cout << "\n--------------------------------";
    std::cout << "\n\tOwner: " << owner;
    std::cout << "\n\tBalance: " << balance;
    std::cout << "\n--------------------------------";
}

BankAccount::BankAccount(std::string own, double bal)
{
    owner = own;
    balance = balance;
}
