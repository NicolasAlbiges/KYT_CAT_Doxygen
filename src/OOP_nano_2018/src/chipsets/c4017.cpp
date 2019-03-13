/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** src/c4017.cpp
*/

#include "c4017.hpp"
#include "IComponent.hpp"

c4017::c4017(const std::string &value)
{
    _value = value;
    _type = "c4017";
    _nbOfPin = 16;
    _old_clock0 = nts::FALSE;
    _old_clock1 = nts::FALSE;
    _counter_value = 1;
    this->_pin = std::vector<nts::pin_t *>(_nbOfPin);
    this->_pin[2] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1});
    this->_pin[1] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1});
    this->_pin[3] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1});
    this->_pin[6] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1});
    this->_pin[9] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1});
    this->_pin[0] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1});
    this->_pin[4] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1});
    this->_pin[5] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1});
    this->_pin[8] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1});
    this->_pin[10] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1});

    this->_pin[11] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1});

    this->_pin[12] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1});
    this->_pin[13] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1});
    this->_pin[14] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1});

    this->_pin[7] = new nts::pin_t(nullptr, nts::OTHER, nullptr, std::vector<int> {-1});
    this->_pin[15] = new nts::pin_t(nullptr, nts::OTHER, nullptr, std::vector<int> {-1});
    reset();
    _pin[12]->state = nts::FALSE;
    _pin[13]->state = nts::FALSE;
}

c4017::~c4017()
{
}

nts::Tristate c4017::compute(std::size_t pin)
{
    std::vector<nts::Tristate> pin_state;
    int output_pin_nb[11] = {15, 2, 1, 3, 6, 9, 0, 4, 5, 8, 10};

    reset();
    pin -= 1;
    if (_pin[pin]->type == nts::INPUT) {
        if (_pin[pin]->father != nullptr)
            return (_pin[pin]->father->compute(_pin[pin]->fatherPinVector[0]));
        else if (_pin[pin]->father == nullptr)
            return (_pin[pin]->state);
    }
    if (this->compute(15) == nts::TRUE) {
        for (int i = 1; i < 11; i += 1)
            _pin[output_pin_nb[i]]->state = nts::FALSE;
        _pin[2]->state = nts::TRUE;
        _pin[11]->state = nts::TRUE;
        _counter_value = 1;
    } else if (this->compute(14) == nts::TRUE && _old_clock1 == nts::TRUE
    && this->compute(13) == nts::FALSE) {
        _counter_value += 1;
    } else if (_old_clock0 == nts::FALSE && this->compute(14) == nts::TRUE
    && this->compute(13) == nts::FALSE) {
        _counter_value += 1;
    }
    _old_clock1 = this->compute(13);
    _old_clock0 = this->compute(14);
    _counter_value = (_counter_value >= 11) ? 1 : _counter_value;
    _pin[11]->state = (_counter_value <= 6) ? nts::TRUE : nts::FALSE;
    _pin[output_pin_nb[_counter_value]]->state = nts::TRUE;
    return (_pin[pin]->state);
}

void c4017::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    pin -= 1;
    this->_pin[pin]->father = &other;
    this->_pin[pin]->fatherPinVector[0] = otherPin;
}

void c4017::dump() const
{
//    std::cout << _value << std::endl;
}

void c4017::reset()
{
    int output_pin_nb[10] = {2, 1, 3, 6, 9, 0, 4, 5, 8, 10};

    for (int i = 0; i < 10; i += 1)
        _pin[output_pin_nb[i]]->state = nts::FALSE;
}