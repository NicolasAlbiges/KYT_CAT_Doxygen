/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** src/c4094.cpp
*/

#include "c4094.hpp"
#include "IComponent.hpp"

c4094::c4094(const std::string &value)
{
    _value = value;
    _type = "c4094";
    _nbOfPin = 16;
    _clock_size = 0;
    _old_clock = nts::UNDEFINED;
    this->_pin = std::vector<nts::pin_t *>(_nbOfPin);
    this->_pin[0] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[1] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1, -1});

    this->_pin[2] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1, -1});//CLOCK
    this->_pin[3] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1, -1});

    this->_pin[4] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[5] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1, -1});

    this->_pin[6] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1, -1});


    this->_pin[7] = new nts::pin_t(nullptr, nts::OTHER, nullptr, std::vector<int> {-1, -1});


    this->_pin[8] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1, -1});

    this->_pin[9] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[10] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1, -1});

    this->_pin[11] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[12] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1, -1});


    this->_pin[13] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[14] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1, -1});

    this->_pin[15] = new nts::pin_t(nullptr, nts::OTHER, nullptr, std::vector<int> {-1, -1});

}

c4094::~c4094()
{
}

nts::Tristate c4094::compute(std::size_t pin)
{
    std::vector<nts::Tristate> pin_state;
    int output_pin_nb[8] = {3, 4, 5, 6, 13, 12, 11, 10};
    pin -= 1;

    if (_pin[pin]->type == nts::OTHER)
        return (nts::UNDEFINED);
    if (_pin[pin]->type == nts::INPUT || _pin[pin]->type == nts::CLOCK) {
        if (_pin[pin]->father != nullptr)
            return (_pin[pin]->father->compute(_pin[pin]->fatherPinVector[0]));
        else if (_pin[pin]->father == nullptr)
            return (nts::UNDEFINED);
    }
    if (this->compute(3) == nts::TRUE && this->compute(15) == nts::FALSE) {
        for (int ct = 0; ct <= 8; ct ++)
            _pin[output_pin_nb[ct]]->state = nts::UNDEFINED;
        _pin[8]->state = _pin[11]->state;
        return (_pin[pin]->state);
    }
    if (this->compute(3) == nts::FALSE && this->compute(15) == nts::FALSE) {
        for (int ct = 0; ct <= 8; ct ++)
            _pin[output_pin_nb[ct]]->state = nts::UNDEFINED;
        _pin[9]->state = _pin[11]->state;
        return (_pin[pin]->state);
    }
    if (this->compute(3) == nts::TRUE && this->compute(15) == nts::TRUE && this->compute(1) == nts::FALSE) {
        _pin[8]->state = _pin[11]->state;
        return (_pin[pin]->state);
    }
    if (this->compute(3) == nts::TRUE && this->compute(15) == nts::TRUE && this->compute(1) == nts::TRUE && this->compute(2) == nts::FALSE) {
        _pin[3]->state = nts::FALSE;
        for (int ct = 1; ct < 8; ct ++)
            _pin[output_pin_nb[ct]]->state = _pin[output_pin_nb[ct - 1]]->state;
        _pin[8]->state = _pin[11]->state;
        return (_pin[pin]->state);
    }
    if (this->compute(3) == nts::TRUE && this->compute(15) == nts::TRUE && this->compute(1) == nts::TRUE && this->compute(2) == nts::TRUE) {
        _pin[3]->state = nts::TRUE;
        for (int ct = 1; ct < 8; ct ++) {
            _pin[output_pin_nb[ct]]->state = _pin[output_pin_nb[ct - 1]]->state;
        }
        _pin[8]->state = _pin[11]->state;
        return (_pin[pin]->state);
    }
    if (this->compute(3) == nts::FALSE && this->compute(15) == nts::TRUE && this->compute(1) == nts::TRUE && this->compute(2) == nts::TRUE) {
        _pin[9]->state = _pin[11]->state;
        return (_pin[pin]->state);
    }
    return (_pin[pin]->state);
}

void c4094::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    pin -= 1;
    this->_pin[pin]->father = &other;
    this->_pin[pin]->fatherPinVector[0] = otherPin;
}

void c4094::dump() const
{
//    std::cout << _value << std::endl;
}
