/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** src/ctrue.cpp
*/

#include "ctrue.hpp"
#include "IComponent.hpp"

ctrue::ctrue(const std::string &value)
{
    _value = value;
    _nbOfPin = 1;
    _type = "ctrue";
    this->_pin = std::vector<nts::pin_t *>(_nbOfPin);
    this->_pin[0] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[0]->state = nts::TRUE;
}

ctrue::~ctrue()
{
}

nts::Tristate ctrue::compute(std::size_t pin)
{
    (void)pin;
    return (nts::TRUE);
}

void ctrue::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin != 1) {
        std::cout << "Invalid pin number" << std::endl;
        return;
    }
    this->_pin[pin - 1]->father = &other;
    this->_pin[pin - 1]->fatherPinVector[0] = otherPin;
}

void ctrue::dump() const
{
}
