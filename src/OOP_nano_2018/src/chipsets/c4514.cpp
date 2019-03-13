/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** src/c4514.cpp
*/

#include "c4514.hpp"
#include "IComponent.hpp"

static int c4514_tt[16][6] =
{
    {0, 0, 0, 0, 0, 10},
    {0, 0, 0, 0, 1, 8},
    {0, 0, 0, 1, 0, 9},
    {0, 0, 0, 1, 1, 7},
    {0, 0, 1, 0, 0, 6},
    {0, 0, 1, 0, 1, 5},
    {0, 0, 1, 1, 0, 4},
    {0, 0, 1, 1, 1, 3},
    {0, 1, 0, 0, 0, 17},
    {0, 1, 0, 0, 1, 16},
    {0, 1, 0, 1, 0, 19},
    {0, 1, 0, 1, 1, 18},
    {0, 1, 1, 0, 0, 13},
    {0, 1, 1, 0, 1, 12},
    {0, 1, 1, 1, 0, 15},
    {0, 1, 1, 1, 1, 14},
};

c4514::c4514(const std::string &value)
{
    _value = value;
    _type = "c4514";
    _nbOfPin = 24;
    this->_pin = std::vector<nts::pin_t *>(_nbOfPin);
    this->_pin[0] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1});
    this->_pin[1] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1});
    this->_pin[2] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1});

    this->_pin[3] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1});
    this->_pin[4] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1});
    this->_pin[5] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1});
    this->_pin[6] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1});
    this->_pin[7] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1});
    this->_pin[8] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1});
    this->_pin[9] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1});
    this->_pin[10] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1});

    this->_pin[11] = new nts::pin_t(nullptr, nts::OTHER, nullptr, std::vector<int> {-1});

    this->_pin[12] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1});
    this->_pin[13] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1});
    this->_pin[14] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1});
    this->_pin[15] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1});
    this->_pin[16] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1});
    this->_pin[17] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1});
    this->_pin[18] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1});
    this->_pin[19] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1});

    this->_pin[20] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1});
    this->_pin[21] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1});
    this->_pin[22] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1});

    this->_pin[23] = new nts::pin_t(nullptr, nts::OTHER, nullptr, std::vector<int> {-1});
}

c4514::~c4514()
{
}

nts::Tristate c4514::compute(std::size_t pin)
{
    std::vector<nts::Tristate> pin_state;
    nts::Tristate A;
    nts::Tristate B;
    nts::Tristate C;
    nts::Tristate D;
    nts::Tristate Inhibit;

    pin -= 1;

    if (_pin[pin]->type == nts::INPUT) {
        if (_pin[pin]->father != nullptr)
            return (_pin[pin]->father->compute(_pin[pin]->fatherPinVector[0]));
        else if (_pin[pin]->father == nullptr)
            return (nts::UNDEFINED);
    }
/*
    if (A == nts::UNDEFINED || B == nts::UNDEFINED || C == nts::UNDEFINED ||
    D == nts::UNDEFINED || Inhibit == nts::UNDEFINED || compute(1) == nts::UNDEFINED) {
*/    A = compute(2);
    B = compute(3);
    C = compute(21);
    D = compute(22);
    Inhibit = compute(23);
    if (A == nts::UNDEFINED || B == nts::UNDEFINED || C == nts::UNDEFINED ||
    D == nts::UNDEFINED || Inhibit == nts::UNDEFINED || compute(1) == nts::UNDEFINED) {
        _pin[pin]->state = nts::UNDEFINED;
        return (_pin[pin]->state);
    }
    if (compute(1) == nts::FALSE) {
        if (Inhibit == nts::FALSE) {
            _pin[pin]->state = nts::UNDEFINED;
            return (_pin[pin]->state);
        }
        _pin[pin]->state = nts::FALSE;
        return (_pin[pin]->state);
    } else if (compute(1) == nts::TRUE) {
        if (Inhibit == nts::TRUE) {
            for (int i = 0; i < 16; i += 1) {
                _pin[c4514_tt[i][5]]->state = nts::FALSE;
            }
            return (_pin[pin]->state);
        }
        for (int i = 0; i < 16; i += 1) {
            if (Inhibit == c4514_tt[i][0] && D == c4514_tt[i][1] &&
            C == c4514_tt[i][2] && B == c4514_tt[i][3] && A == c4514_tt[i][4])
                _pin[c4514_tt[i][5]]->state = nts::TRUE;
        }
    }
    return (_pin[pin]->state);
}

void c4514::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    pin -= 1;
    this->_pin[pin]->father = &other;
    this->_pin[pin]->fatherPinVector[0] = otherPin;
}

void c4514::dump() const
{
//    std::cout << _value << std::endl;
}