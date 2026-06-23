#ifndef USER_HPP
#define USER_HPP

#include <string>
#include <iostream>

class User
{
private:

protected:
    std::string name;
    int id;    

public:
    User(std::string name, int id);
    ~User();
    void printInfo() const; //Prints general User Inforamtion (name and id)
    virtual void printRole() const = 0; // Pure virtual function for adaptive role output depending on the role
};

class Student : public User
{
    private:
        std::string major;

    public:
        Student(std::string name, std::string major, int id) : User(name, id), major(major) {}
        ~Student() {}
        void printRole() const override {
            std::cout << "Role: Student, Major: " << major << std::endl;
        }

};


class Instructor : public User
{
    private:
        std::string title;
        std::string department;
    public:
        Instructor( std::string name, 
                    std::string title, 
                    std::string department, 
                    int id) 
                    : User(name, id), title(title), department(department){}
        ~Instructor() {}

        void printRole() const override {
            std::cout << "Role: Instructor, Title: " << title << ", Department: " << department << std::endl;
        }

};







#endif // USER_HPP
