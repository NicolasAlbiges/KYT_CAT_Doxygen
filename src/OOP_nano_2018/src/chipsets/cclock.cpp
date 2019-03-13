/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** src/cclock.cpp
*/

#include "cclock.hpp"
#include "IComponent.hpp"

cclock::cclock(const std::string &value)
{
    _value = value;
    _nbOfPin = 1;
    _type = "cclock";
    this->_pin = std::vector<nts::pin_t *>(_nbOfPin);
    this->_pin[0] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1, -1});
}

cclock::~cclock()
{
}

nts::Tristate cclock::compute(std::size_t pin)
{
    (void)pin;
    return (this->_pin[0]->state);
}

void cclock::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin != 1) {
        std::cout << "Invalid clock pin number" << std::endl;
        return;
    }
    this->_pin[pin - 1]->father = &other;
    this->_pin[pin - 1]->fatherPinVector[0] = otherPin;
}

void cclock::loop()
{
    if (this->_pin[0]->state == nts::TRUE)
        this->_pin[0]->state = nts::FALSE;
    else if (this->_pin[0]->state == nts::FALSE)
        this->_pin[0]->state = nts::TRUE;
}


void cclock::dump() const
{
}
