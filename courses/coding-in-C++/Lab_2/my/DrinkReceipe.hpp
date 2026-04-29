#pragma once;
#include <iostream>
#include <string>
#include <cstdint>
#include <>

class DrinkReceipe{

    private:
        
        std::string name;
        std::uint8_t volume_in_cl;
        std::uint8_t temperature;
        std::bool withMilk;


       // constexpr std::uint16_t ANZ_IGREDIENTS = 5;
       // std::string ingredients[ANZ_IGREDIENTS];





    public:

    DrinkReceipe setName();
    DrinkReceipe setTemperature();
    DrinkReceipe addIngredient();

}