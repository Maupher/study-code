#ifndef DRINKRECEIPE_HPP
#define DRINKRECEIPE_HPP

#include <string>
#include <cstdint>


class DrinkReceipe
{

    private:

        //const --> Constante Werte und Funktionen zu laufzeit
        //constexpr --> Grenzen und Werte welche zur Initialisierung notwendig sind
        static constexpr std::uint16_t BASE_TEMP = 12U;
        static constexpr std::uint16_t BASE_SUGAR_AMOUNT = 0U;
        static constexpr std::uint16_t BASE_VOLUME_IN_CL = 10U;
        static constexpr bool BASE_MILK = false;
        static constexpr bool BASE_ICE = false;
        //most senseful use Variable Array length --> int test[HOW_MANY]

        static constexpr std::uint16_t MAX_TEMP = 100U;
        static constexpr std::uint16_t MIN_TEMP = 0U;
        static constexpr std::uint16_t MAX_VOLUME = 100U;
        static constexpr std::uint16_t MIN_VOLUME = 1U;
        static constexpr std::uint16_t MAX_SUGAR_AMOUNT = 50U;
        static constexpr std::uint16_t MIN_SUGAR_AMOUNT = 0U;


        std::string name;
        std::uint16_t volume_in_cl = BASE_VOLUME_IN_CL;
        std::uint16_t temperature = BASE_TEMP;
        std::uint16_t sugar_amount = BASE_SUGAR_AMOUNT;
        bool with_ice = BASE_ICE;
        bool with_milk = BASE_MILK;

    public:

    DrinkReceipe& setName(std::string name);
    DrinkReceipe& setVolume(std::uint16_t volume);
    DrinkReceipe& setTemperature(std::uint16_t temperature);
    DrinkReceipe& setSugar(std::uint16_t sugar_amount);
    DrinkReceipe& setWithIce(bool with_ice);
    DrinkReceipe& setWithMilk(bool with_milk);

    void print() const;
    bool isValid() const;

};
#endif // DRINKRECREIPE_HPP