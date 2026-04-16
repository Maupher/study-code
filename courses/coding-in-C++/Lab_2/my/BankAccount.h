#pragma once
#include <iostream>
#include <string>

class BankAccount{

    private:
        std::string owner;
        double balance;

    public:
        BankAccount(std::string own, double bal);
        void setOwner(std::string& ownerName);
        std::string getOwner();
        void deposit(double);
        void withdraw(double);
        double getBalance() const;
        void getAccountInfo() const;
};

