/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** src/output.cpp
*/

#include "output.hpp"
#include "IComponent.hpp"

output::output(const std::string &value)
{
    _value = value;
    _nbOfPin = 1;
    _type = "output";
    this->_pin = std::vector<nts::pin_t *>(_nbOfPin);
    this->_pin[0] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1});
}

output::~output()
{
}

nts::Tristate output::compute(std::size_t pin)
{
    if (_pin[0]->father != nullptr) {
        _pin[0]->state = _pin[0]->father->compute(_pin[0]->fatherPinVector[0]);
    }
    return (_pin[0]->state);
}

void output::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin != 1) {
        std::cout << "Invalid input pin number" << std::endl;
        return;
    }
    this->_pin[pin - 1]->father = &other;
    this->_pin[pin - 1]->fatherPinVector[0] = otherPin;
}

void output::dump() const
{
    std::cout << _value << "=";
    if (this->_pin[0]->state == -1)
        std::cout << "U" << std::endl;
    else
        std::cout << this->_pin[0]->state << std::endl;
}