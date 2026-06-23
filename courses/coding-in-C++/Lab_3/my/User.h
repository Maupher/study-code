//
// Created by ibach on 03.05.2026.
//

#ifndef STUDY_CODE_USER_H
#define STUDY_CODE_USER_H

#include <string.h>
#include <cstdint>
#include <stdint.h>

class User {

    private:
        std::string first_name;
        std::string last_name;
        int student_id;

public:
    void set_credentials(string first_name, string last_name, int student_id);
    



};



#endif //STUDY_CODE_USER_H
