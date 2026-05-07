#include "User.hpp"

#include <iostream>

User::User(std::string name, int id)
    : name(name), id(id)
{
    std::cout << "Constructor called for User: " << name << std::endl;
}

User::~User()
{
    std::cout << "Destructor called for User: " << name << std::endl;
}

void User::printInfo() const 
{
    std::cout << "\n\n\tUser Name: " << name << ", ID: " << id << std::endl;
}


