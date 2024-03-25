/**********************************************************************
 * Name: Sujan Sharma
 * Email: ssharma627@myseneca.ca
 * StudentID: 157775222
 * Section: ZAA
 *
 * I have done all the coding by myself and only copied the code that
 * my professor provided to complete my workshop and assignments.
 ***********************************************************************/
#include <iostream>
#include <cstring>
#include "Hero.h"
#include "Power.h"

namespace seneca
{
    Hero::Hero()
    {
        m_name[0] = '\0';
        m_powers = nullptr;
        m_numPowers = 0;
        m_powerLevel = 0;
    }
    Hero::Hero(const char *name, Power power[], int numPowers)
    {
        if (name != nullptr && name[0] != '\0')
        {
            std::strcpy(m_name, name);
        }
        else
        {
            m_name[0] = '\0';
        }
        m_powers = new Power[numPowers];
        for (int i = 0; i < numPowers; i++)
        {
            m_powers[i] = power[i];
        }
        m_numPowers = numPowers;
        changePower();
    }
    Hero::~Hero()
    {
        delete[] m_powers;
        m_powers = nullptr;
    }
    std::ostream &Hero::display(std::ostream &os) const
    {
        if (m_name[0] != '\0')
        {
            os << "Name: " << m_name << std::endl;
            os << "List of available powers: " << std::endl;
            for (int i = 0; i < m_numPowers; i++)
            {
                os << "  Name: " << m_powers[i].checkName() << ", Rarity: " << m_powers[i].checkRarity() << std::endl;
            }
            os << "Power level: " << m_powerLevel;
        }
        return os;
    }
    Hero &Hero::operator+=(Power &power)
    {
        Power *pow = new Power[m_numPowers + 1];
        for (int i = 0; i < m_numPowers; i++)
        {
            pow[i] = m_powers[i];
        }
        pow[m_numPowers] = power;
        delete[] m_powers;
        m_powers = pow;
        m_numPowers++;
        changePower();
        return *this;
    }
    void Hero::changePower()
    {
        int totalRarity = 0;
        for (int i = 0; i < m_numPowers; ++i)
        {
            totalRarity += m_powers[i].checkRarity();
        }
        totalRarity *= m_numPowers;
        m_powerLevel = totalRarity;
    }
    Hero &Hero::operator-=(int dec)
    {
        if (m_powerLevel > 0 && m_powerLevel >= dec)
            m_powerLevel -= dec;
        return *this;
    }
    bool Hero::operator<(Hero &hero2)
    {
        return m_powerLevel < hero2.m_powerLevel;
    }
    bool Hero::operator>(Hero &hero2)
    {
        return m_powerLevel > hero2.m_powerLevel;
    }

    void operator<<(Hero &hero, Power &power)
    {
        hero += power;
    }

    void operator>>(Power &power, Hero &hero)
    {
        hero << power;
    }
}