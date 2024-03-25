/**********************************************************************
 * Name: Sujan Sharma
 * Email: ssharma627@myseneca.ca
 * StudentID: 157775222
 * Section: ZAA
 *
 * I have done all the coding by myself and only copied the code that
 * my professor provided to complete my workshop and assignments.
 ***********************************************************************/
#ifndef SENECA_HERO_H
#define SENECA_HERO_H

#include "Power.h"
namespace seneca
{
    const int MAX_NAME_LEN = 50;
    class Hero
    {
        char m_name[MAX_NAME_LEN + 1];
        Power *m_powers;
        int m_numPowers;
        int m_powerLevel;

    public:
        /**
         * @brief Construct a new Hero object
         */
        Hero();
        /**
         * @brief Construct a new Hero object
         *
         * @param name name of the hero
         * @param power list of powers
         * @param numPowers number of powers
         *
         */
        Hero(const char *name, Power power[], int numPowers);
        /**
         * @brief Destroy the Hero object
         *
         */
        ~Hero();

        /**
         * @brief Display the hero details
         *
         * @param os
         * @return std::ostream&
         */
        std::ostream &display(std::ostream &os = std::cout) const;
        /**
         * @brief Add a power to the hero
         *
         * @param power
         * @return Hero&
         */
        Hero &operator+=(Power &power);
        /**
         * @brief Remove a power from the hero
         *
         * @param dec
         * @return Hero&
         */
        Hero &operator-=(int dec);
        /**
         * @brief Change the power level of the hero
         *
         * @return void
         *
         */
        void changePower();
        /**
         * @brief Compare the power level of two heroes
         *
         * @param hero2
         * @return true
         * @return false
         */
        bool operator<(Hero &hero2);
        /**
         * @brief Compare the power level of two heroes
         *
         * @param hero2
         * @return true
         * @return false
         */
        bool operator>(Hero &hero2);
    };
    /**
     * @brief Add a power to the hero
     *
     * @param hero
     * @param power
     * @return void
     */
    void operator<<(Hero &hero, Power &power);
    /**
     * @brief Add power to hero
     *
     * @param power
     * @param hero
     * @return void
     */
    void operator>>(Power &power, Hero &hero);
}
#endif