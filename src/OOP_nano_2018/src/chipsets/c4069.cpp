/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** src/c4069.cpp
*/

#include "c4069.hpp"
#include "IComponent.hpp"

c4069::c4069(const std::string &value)
{
    _value = value;
    _type = "c4069";
    _nbOfPin = 14;
    this->_pin = std::vector<nts::pin_t *>(_nbOfPin);

    this->_pin[0] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[1] = new nts::pin_t(&GateNOT, nts::OUTPUT, nullptr, std::vector<int> {0, 1});

    this->_pin[2] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[3] = new nts::pin_t(&GateNOT, nts::OUTPUT, nullptr, std::vector<int> {2, 3});

    this->_pin[4] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[5] = new nts::pin_t(&GateNOT, nts::OUTPUT, nullptr, std::vector<int> {4, 5});

    this->_pin[6] = new nts::pin_t(nullptr, nts::OTHER, nullptr, std::vector<int> {-1, -1});


    this->_pin[8] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[7] = new nts::pin_t(&GateNOT, nts::OUTPUT, nullptr, std::vector<int> {8, 7});

    this->_pin[10] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[9] = new nts::pin_t(&GateNOT, nts::OUTPUT, nullptr, std::vector<int> {10, 9});

    this->_pin[12] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[11] = new nts::pin_t(&GateNOT, nts::OUTPUT, nullptr, std::vector<int> {12, 11});


    this->_pin[13] = new nts::pin_t(nullptr, nts::OTHER, nullptr, std::vector<int> {-1, -1});
}

c4069::~c4069()
{
}

nts::Tristate c4069::compute(std::size_t pin)
{
    std::vector<nts::Tristate> pin_state;

    pin -= 1;
    if (_pin[pin]->type == nts::INPUT) {
        if (_pin[pin]->father != nullptr)
            return (_pin[pin]->father->compute(_pin[pin]->fatherPinVector[0]));
        else if (_pin[pin]->father == nullptr)
            return (nts::UNDEFINED);
    }
    if (_pin[pin]->func_op == nullptr)
        return (nts::UNDEFINED);
    for (auto &p: _pin[pin]->fatherPinVector) {
        if (_pin[p]->father == nullptr)
            pin_state.push_back(_pin[p]->state);
        else
            pin_state.push_back(_pin[p]->father->compute(_pin[p]->fatherPinVector[0]));
    }
    return (_pin[pin]->func_op(pin_state));
}

void c4069::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    pin -= 1;
    this->_pin[pin]->father = &other;
    this->_pin[pin]->fatherPinVector[0] = otherPin;
}

void c4069::dump() const
{
//    std::cout << _value << std::endl;
}
/*
std::string c4069::getValue() const
{
    return (_value);
}

std::vector<std::size_t> c4069::getValidPinNumber() const
{
    std::vector<std::size_t> valid_pin;

    for (size_t i = 0; i < _nbOfPin; i += 1) {
        if (_pin[i]->type != nts::OTHER)
            valid_pin.push_back(i);
    }
    return (valid_pin);
}

std::string c4069::getType() const
{
    return _type;
}*/