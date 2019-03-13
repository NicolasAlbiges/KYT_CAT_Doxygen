/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** src/c4008.cpp
*/

#include "c4008.hpp"
#include "IComponent.hpp"

c4008::c4008(const std::string &value)
{
    _value = value;
    _type = "c4008";
    _nbOfPin = 16;
    this->_pin = std::vector<nts::pin_t *>(_nbOfPin);
    this->_pin[0] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[1] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[2] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1, -1});

    this->_pin[4] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[5] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[3] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1, -1});

    this->_pin[6] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1, -1});
    
    this->_pin[7] = new nts::pin_t(nullptr, nts::OTHER, nullptr, std::vector<int> {-1, -1});
    this->_pin[8] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[9] = new nts::pin_t(&GateSUM, nts::OUTPUT, nullptr, std::vector<int> {5, 6});

    this->_pin[11] = new nts::pin_t(&GateSUM, nts::OUTPUT, nullptr, std::vector<int> {1, 2});
    this->_pin[12] = new nts::pin_t(&GateSUM, nts::OUTPUT, nullptr, std::vector<int> {14, 0});
    this->_pin[10] = new nts::pin_t(&GateSUM, nts::OUTPUT, nullptr, std::vector<int> {3, 4});

    this->_pin[13] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[14] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[15] = new nts::pin_t(nullptr, nts::OTHER, nullptr, std::vector<int> {-1, -1});
}

c4008::~c4008()
{
}

nts::Tristate c4008::compute(std::size_t pin)
{
    std::vector<nts::Tristate> pin_state;
    nts::Tristate Ci;
    int result = -1;

    pin -= 1;
    if (_pin[pin]->type == nts::INPUT) {
        if (_pin[pin]->father != nullptr)
            return (_pin[pin]->father->compute(_pin[pin]->fatherPinVector[0]));
        else if (_pin[pin]->father == nullptr)
            return (nts::UNDEFINED);
    }
    Ci = this->compute(9);
    for (std::size_t pin_act = 9; pin_act <= 12; pin_act += 1) {
        for (auto &p: _pin[pin_act]->fatherPinVector) {
            if (_pin[p]->father == nullptr)
                pin_state.push_back(_pin[p]->state);
            else
                pin_state.push_back(_pin[p]->father->compute(_pin[p]->fatherPinVector[0]));
        }
        pin_state.push_back(Ci);
        result = _pin[pin_act]->func_op(pin_state);
        switch(result) {
            case 0:
                _pin[pin_act]->state = nts::FALSE;
                _pin[13]->state = nts::FALSE;
                Ci = nts::FALSE;
                break;
            case 1:
                _pin[pin_act]->state = nts::TRUE;
                _pin[13]->state = nts::FALSE;
                Ci = nts::FALSE;
                break;
            case 2:
                _pin[pin_act]->state = nts::FALSE;
                _pin[13]->state = nts::TRUE;
                Ci = nts::TRUE;
                break;
            case 3:
                _pin[pin_act]->state = nts::TRUE;
                _pin[13]->state = nts::TRUE;
                Ci = nts::TRUE;
                break;
        }
        pin_state.clear();
    }
    return (_pin[pin]->state);
}

void c4008::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    pin -= 1;
    this->_pin[pin]->father = &other;
    this->_pin[pin]->fatherPinVector[0] = otherPin;
}

void c4008::dump() const
{
//    std::cout << _value << std::endl;
}