/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** src/input.cpp
*/

#include "input.hpp"
#include "IComponent.hpp"
#include "AComponent.hpp"

input::input(const std::string &value): AComponent::AComponent()
{
    _value = value;
    _nbOfPin = 1;
    _type = "input";
    this->_pin = std::vector<nts::pin_t *>(_nbOfPin);
    this->_pin[0] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1, -1});
}

input::~input()
{
}

nts::Tristate input::compute(std::size_t pin)
{
    (void)pin;
    return (this->_pin[0]->state);
}

void input::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin != 1) {
        std::cout << "Invalid input pin number" << std::endl;
        return;
    }
    this->_pin[pin - 1]->father = &other;
    this->_pin[pin - 1]->fatherPinVector[0] = otherPin;
}

void input::setStatu(nts::Tristate state, std::size_t pin)
{
    if (pin != 1) {
        std::cout << "Invalid input pin number" << std::endl;
        return;
    }
    this->_pin[pin - 1]->state = state;
}


void input::dump() const
{
}
