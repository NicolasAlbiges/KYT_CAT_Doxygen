/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** src/c4040.cpp
*/

#include "c4040.hpp"
#include "IComponent.hpp"

c4040::c4040(const std::string &value)
{
    _value = value;
    _type = "c4040";
    _nbOfPin = 16;
    _clock_size = 0;
    _old_clock = nts::UNDEFINED;
    this->_pin = std::vector<nts::pin_t *>(_nbOfPin);
    this->_pin[0] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[1] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1, -1});

    this->_pin[2] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[3] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1, -1});

    this->_pin[4] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[5] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1, -1});

    this->_pin[6] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1, -1});


    this->_pin[7] = new nts::pin_t(nullptr, nts::OTHER, nullptr, std::vector<int> {-1, -1});


    this->_pin[8] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1, -1});

    this->_pin[10] = new nts::pin_t(nullptr, nts::RESET, nullptr, std::vector<int> {-1, -1});
    this->_pin[9] = new nts::pin_t(nullptr, nts::CLOCK, nullptr, std::vector<int> {-1, -1});

    this->_pin[11] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[12] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1, -1});


    this->_pin[13] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[14] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1, -1});

    this->_pin[15] = new nts::pin_t(nullptr, nts::OTHER, nullptr, std::vector<int> {-1, -1});

}

c4040::~c4040()
{
}

nts::Tristate c4040::compute(std::size_t pin)
{
    std::vector<nts::Tristate> pin_state;
    nts::Tristate clock_value;
    int output_pin_nb[12] = {8, 6, 5, 4, 2, 1, 3, 12, 11, 13, 14, 0};
    pin -= 1;

    if (_pin[pin]->type == nts::OTHER)
        return (nts::UNDEFINED);
    if (_pin[pin]->type == nts::CLOCK || _pin[pin]->type == nts::RESET) {
        if (_pin[pin]->father != nullptr)
            return (_pin[pin]->father->compute(_pin[pin]->fatherPinVector[0]));
        else if (_pin[pin]->father == nullptr)
            return (nts::UNDEFINED);
    }
    if (this->compute(11) == nts::TRUE) {
        _clock_size = 0;
    } else if (this->compute(11) == nts::FALSE) {
        clock_value = this->compute(10);
        if (clock_value == nts::UNDEFINED) {
            for (int ct = 0; ct != 16; ct ++) {
                if (_pin[ct]->type == nts::OUTPUT) {
                    _pin[ct]->state = nts::UNDEFINED;
                }
            }
            return (_pin[pin]->state);
        } else if (_old_clock == nts::TRUE && clock_value == nts::FALSE) {
            _clock_size += 1;
        }
        _old_clock = clock_value;
    }
    for (int ct = 0, tmp_clock = _clock_size; ct <= 11; ct ++) {
        if ((tmp_clock % 2) == 0)
            _pin[output_pin_nb[ct]]->state = nts::FALSE;
        else
            _pin[output_pin_nb[ct]]->state = nts::TRUE;
        tmp_clock = tmp_clock / 2;
    }
    return (_pin[pin]->state);
}

void c4040::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    pin -= 1;
    this->_pin[pin]->father = &other;
    this->_pin[pin]->fatherPinVector[0] = otherPin;
}

void c4040::dump() const
{
//    std::cout << _value << std::endl;
}
