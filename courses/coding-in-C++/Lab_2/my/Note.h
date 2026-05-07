#pragma once

#include <iostream>
#include <string>


class Note{
    private:
        std::string *text;
    public:
        Note(std::string s);
        ~Note();
        void display();

};