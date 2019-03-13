/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** src/AComponent.cpp
*/

#include "AComponent.hpp"

AComponent::AComponent()
{
    //_pin[0] = 0;
}

AComponent::~AComponent()
{
}

std::string AComponent::getValue() const
{
    return (_value);
}

std::vector<std::size_t> AComponent::getValidPinNumber() const
{
    std::vector<std::size_t> valid_pin;

    for (size_t i = 0; i < _nbOfPin; i += 1) {
        if (_pin[i]->type != nts::OTHER)
            valid_pin.push_back(i);
    }
    return (valid_pin);
}

std::string AComponent::getType() const
{
    return _type;
}