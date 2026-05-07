#include <Note.h>

Note::Note(std::string s){
    text = new std::string;
    *text = s;
};

Note::~Note(){
    delete text;
    *text = nullptr;
    std::cout << "\n\n\tMemory released";
}

void Note::display(){
    std::cout << text;
}