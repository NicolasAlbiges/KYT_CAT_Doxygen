/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** src/c4013.cpp
*/

#include "c4013.hpp"
#include "IComponent.hpp"

c4013::c4013(const std::string &value)
{
    _value = value;
    _type = "c4013";
    _nbOfPin = 14;
    _FF1 = new FlipFlop();
    _FF2 = new FlipFlop();
    this->_pin = std::vector<nts::pin_t *>(_nbOfPin);

    this->_pin[0] = new nts::pin_t(nullptr, nts::OUTPUT, _FF1, std::vector<int> {FlipFlop::FlipFlopPin::Q});
    this->_pin[1] = new nts::pin_t(nullptr, nts::OUTPUT, _FF1, std::vector<int> {FlipFlop::FlipFlopPin::_Q});
    this->_pin[2] = new nts::pin_t(nullptr, nts::INPUT, _FF1, std::vector<int> {FlipFlop::FlipFlopPin::CLOCK});
    this->_pin[3] = new nts::pin_t(nullptr, nts::INPUT, _FF1, std::vector<int> {FlipFlop::FlipFlopPin::RESET});
    this->_pin[4] = new nts::pin_t(nullptr, nts::INPUT, _FF1, std::vector<int> {FlipFlop::FlipFlopPin::DATA});
    this->_pin[5] = new nts::pin_t(nullptr, nts::INPUT, _FF1, std::vector<int> {FlipFlop::FlipFlopPin::SET});
    _FF1->setLink(FlipFlop::FlipFlopPin::CLOCK, *this, 3);
    _FF1->setLink(FlipFlop::FlipFlopPin::RESET, *this, 4);
    _FF1->setLink(FlipFlop::FlipFlopPin::DATA, *this, 5);
    _FF1->setLink(FlipFlop::FlipFlopPin::SET, *this, 6);

    this->_pin[6] = new nts::pin_t(nullptr, nts::OTHER, nullptr, std::vector<int> {-1, -1});

    this->_pin[7] = new nts::pin_t(nullptr, nts::INPUT, _FF2, std::vector<int> {FlipFlop::FlipFlopPin::SET});
    this->_pin[8] = new nts::pin_t(nullptr, nts::INPUT, _FF2, std::vector<int> {FlipFlop::FlipFlopPin::DATA});
    this->_pin[9] = new nts::pin_t(nullptr, nts::INPUT, _FF2, std::vector<int> {FlipFlop::FlipFlopPin::RESET});
    this->_pin[10] = new nts::pin_t(nullptr, nts::INPUT, _FF2, std::vector<int> {FlipFlop::FlipFlopPin::CLOCK});
    this->_pin[11] = new nts::pin_t(nullptr, nts::OUTPUT, _FF2, std::vector<int> {FlipFlop::FlipFlopPin::_Q});
    this->_pin[12] = new nts::pin_t(nullptr, nts::OUTPUT, _FF2, std::vector<int> {FlipFlop::FlipFlopPin::Q});
    _FF2->setLink(FlipFlop::FlipFlopPin::CLOCK, *this, 11);
    _FF2->setLink(FlipFlop::FlipFlopPin::RESET, *this, 10);
    _FF2->setLink(FlipFlop::FlipFlopPin::DATA, *this, 9);
    _FF2->setLink(FlipFlop::FlipFlopPin::SET, *this, 8);
    this->_pin[13] = new nts::pin_t(nullptr, nts::OTHER, nullptr, std::vector<int> {-1, -1});
}

c4013::~c4013()
{
}

nts::Tristate c4013::compute(std::size_t pin)
{
    pin -= 1;
    if (_pin[pin]->type == nts::INPUT) {
        if (_pin[pin]->father != nullptr)
            return (_pin[pin]->father->compute(_pin[pin]->fatherPinVector[0]));
        else if (_pin[pin]->father == nullptr)
            return (nts::UNDEFINED);
    }
    return (_pin[pin]->father->compute(_pin[pin]->fatherPinVector[0]));
}

void c4013::setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin)
{
    pin -= 1;
    this->_pin[pin]->father = &other;
    this->_pin[pin]->fatherPinVector[0] = otherPin;
}

void c4013::dump() const
{
//    std::cout << _value << std::endl;
}