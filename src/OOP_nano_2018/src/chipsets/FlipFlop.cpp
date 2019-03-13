/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** src/FlipFlop.cpp
*/

#include "FlipFlop.hpp"
#include "IComponent.hpp"

FlipFlop::FlipFlop()
{
    _nbOfPin = 6;
    _old_clock = nts::UNDEFINED;
    this->_pin = std::vector<nts::pin_t *>(_nbOfPin);
    this->_pin[SET] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[DATA] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[RESET] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[CLOCK] = new nts::pin_t(nullptr, nts::INPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[Q] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1, -1});
    this->_pin[_Q] = new nts::pin_t(nullptr, nts::OUTPUT, nullptr, std::vector<int> {-1, -1});
}

FlipFlop::~FlipFlop()
{
}

nts::Tristate FlipFlop::compute(std::size_t pin)
{
//    std::cout << "recuperation du FF pin: " << pin << std::endl;
    if (pin >= _nbOfPin) {
        std::cout << "Can't compute pin" << std::endl;
        return (nts::UNDEFINED);
    }
    if (_pin[pin]->type == nts::INPUT) {
//        std::cout << "C'est un input" << std::endl;
        if (_pin[pin]->father != nullptr) {
//            std::cout << "Et il a un pere" << std::endl;
            return (_pin[pin]->father->compute(_pin[pin]->fatherPinVector[0]));
        } else if (_pin[pin]->father == nullptr) {
//            std::cout << "Et il n'a PAS de pere" << std::endl;
            return (nts::UNDEFINED);
        }
    }
    if (compute(RESET) == nts::TRUE && compute(SET) == nts::TRUE) {
        _pin[Q]->state = nts::TRUE;
        _pin[_Q]->state = nts::TRUE;
    } else if (compute(RESET) == nts::FALSE && compute(SET) == nts::TRUE) {
        _pin[Q]->state = nts::TRUE;
        _pin[_Q]->state = nts::FALSE;
    } else if (compute(RESET) == nts::TRUE && compute(SET) == nts::FALSE) {
        _pin[Q]->state = nts::FALSE;
        _pin[_Q]->state = nts::TRUE;
    } else if (_old_clock == nts::FALSE && this->compute(CLOCK) == nts::TRUE) {
        if (compute(DATA) == nts::FALSE && compute(RESET) == nts::FALSE
        && compute(SET) == nts::FALSE) {
            _pin[Q]->state = nts::FALSE;
            _pin[_Q]->state = nts::TRUE;
        } else if (compute(DATA) == nts::TRUE && compute(RESET) == nts::FALSE
        && compute(SET) == nts::FALSE) {
            _pin[Q]->state = nts::TRUE;
            _pin[_Q]->state = nts::FALSE;
        }
    } else if (_old_clock == nts::TRUE && this->compute(CLOCK) == nts::FALSE
    && compute(SET) == nts::FALSE && compute(RESET) == nts::FALSE) {
        _old_clock = compute(CLOCK);
        return (_pin[pin]->state);
    }
    _old_clock = compute(CLOCK);
    return (_pin[pin]->state);
}

/*
Pas de pin - 1 pour ce setLink car le paramètre 'pin' provient de
l'énumération FlipFlop::FlipFlopPin qui décris les numéros de pin selon leur
index dans le tableau de pin de la classe FlipFlop et non selon leur numéro
réel.
*/
void FlipFlop::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    if (pin >= _nbOfPin) {
        std::cout << "FlipFlop can't set link" << std::endl;
        return;
    }
    this->_pin[pin]->father = &other;
    this->_pin[pin]->fatherPinVector[0] = otherPin;
}

void FlipFlop::dump() const
{
    std::cout << "FlipFLop" << std::endl;
}

/*

    //_pin[Q]->state = (_pin[SET]->state == nts::TRUE) ? nts::TRUE : _pin[Q]->state;
    //_pin[_Q]->state = (_pin[RESET]->state == nts::TRUE) ? nts::TRUE : _pin[_Q]->state;
    if (_pin[CLOCK]->state == nts::TRUE && MGETFATHER(_pin, CLOCK) == nts::FALSE) {
        return (_pin[pin]->state);
    } else if (_pin[CLOCK]->state == nts::FALSE && MGETFATHER(_pin, CLOCK) == nts::TRUE) {
        if (_pin[DATA]->state == nts::FALSE && _pin[RESET]->state == nts::FALSE
        && _pin[SET]->state == nts::FALSE) {
            _pin[Q]->state = nts::FALSE;
            _pin[_Q]->state = nts::TRUE;
        } else if (_pin[DATA]->state == nts::TRUE &&
        _pin[RESET]->state == nts::FALSE && _pin[SET]->state == nts::FALSE) { 
            _pin[Q]->state = nts::TRUE;
            _pin[_Q]->state = nts::FALSE;
        }
    }*/