#include "DrinkReceipe.hpp"
#include <iostream>
#include <string>


DrinkReceipe& DrinkReceipe::setName(std::string name)
{
    this->name = name;
    return *this;
}

DrinkReceipe& DrinkReceipe::setVolume(std::uint16_t volume)
{
    this->volume_in_cl = volume;
    return *this;
}

DrinkReceipe& DrinkReceipe::setTemperature(std::uint16_t temperature)
{
    this->temperature = temperature;
    return *this;
}

DrinkReceipe& DrinkReceipe::setSugar(std::uint16_t sugar_amount)
{
    this->sugar_amount = sugar_amount;
    return *this;
}

DrinkReceipe& DrinkReceipe::setWithIce(bool with_ice)
{
    this->with_ice = with_ice;
    return *this;
}

DrinkReceipe& DrinkReceipe::setWithMilk(bool with_milk)
{
    this->with_milk = with_milk;
    return *this;
}

void DrinkReceipe::print() const
{
    std::cout << "\n\n\tName of the Drink: " << this->name;
    std::cout << "\n\tVolumen in Cl: " << this->volume_in_cl;
    std::cout << "\n\tTemperature: " << this->temperature;
    std::cout << "\n\tSugar Amount: " << this->sugar_amount;
    std::cout << "\n\tWith Ice: ";
    if (this->with_ice)
    {
        std::cout << "true";
    }
    else
    {
        std::cout << "false";
    }
    std::cout << "\n\tWith Milk: ";
    if (this->with_milk)
    {
        std::cout << "true";
    }
    else
    {
        std::cout << "false";
    }
}

bool DrinkReceipe::isValid() const
{
    //Checks if a name is set
    if (this->name.empty())
    {
        return false;
    }

    //Checks if the Temperature is in the allowed range
    if (!((this->temperature <= MAX_TEMP) && (this->temperature => MIN_TEMP)))
    {
        return false;
    }

    //Checks if the Volume is in the allowed range
    if (!((this->volume_in_cl <= MAX_VOLUME) && (this->volume_in_cl => MIN_VOLUME)))
    {
        return false;
    }

    //Checks if the Sugar amount is in the allowed range
    if (!((this->sugar_amount <= MAX_SUGAR_AMOUNT) && (this->sugar_amount >= MIN_SUGAR_AMOUNT)))
    {
        return false;
    }

    return true;
}