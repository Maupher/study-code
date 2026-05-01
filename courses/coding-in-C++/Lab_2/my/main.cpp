#include <iostream>
#include "DrinkReceipe.hpp"


int main()
{
    DrinkReceipe drink1;

    drink1.setName("BlackTea")
            .setSugar(2)
            .setTemperature(50)
            .setVolume(20)
            .setWithIce(false)
            .setWithMilk(true);

    if (!drink1.isValid())
    {
        std::cout << "\n\n\n\tBad error";
    }
    else
    {
        drink1.print();
    }

    return 0;
}