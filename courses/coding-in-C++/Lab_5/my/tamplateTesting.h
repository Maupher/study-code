//
// Created by toaster on 5/11/26.
//

#ifndef STUDY_CODE_TAMPLATETESTING_H
#define STUDY_CODE_TAMPLATETESTING_H

#include <iostream>

template <template T, typename N>
class pair
{
    private:
        T value_1;
        N value_2;

    public:
        Pair(T value_1, N value_2) : value_1(value_1), value_2(value_2)
        {

        }

        T getValue_1()
        {
            return this->value_1;
        }
        N getValue_2()
        {
            return this->value_2;
        }

        void setValue_1(T val)
        {
            this->value_1 = val;
        }
        void setValue_2(N val)
        {
            this->value_2 = val;
        }
};




#endif //STUDY_CODE_TAMPLATETESTING_H
