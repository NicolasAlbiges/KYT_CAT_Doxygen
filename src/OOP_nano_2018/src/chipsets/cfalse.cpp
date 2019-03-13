/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** src/cfalse.cpp
*/

#include "cfalse.hpp"
#include "IComponent.hpp"

cfalse::cfalse(const std::string &value)
{
    _value = value;
    _nbOfPin = 1;
    _type = "cfalse";
    this->_pin = std::vector<nts::pin_t *>(_nbOfPin);
    this->_pin[0] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[0]->state = nts::FALSE;
}

cfalse::~cfalse()
{
}

nts::Tristate cfalse::compute(std::size_t pin)
{
    (void)pin;
    return (nts::FALSE);
}

void cfalse::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin != 1) {
        std::cout << "Invalid pin number" << std::endl;
        return;
    }
    this->_pin[pin - 1]->father = &other;
    this->_pin[pin - 1]->fatherPinVector[0] = otherPin;
}

void cfalse::dump() const
{
}
