/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** src/createPin.cpp
*/

#include "IComponent.hpp"

nts::pin_s::pin_s(nts::op_func_pt func_op, nts::PinType type,
nts::IComponent *father, std::vector<int> fatherPinNb)
{
    this->father = father;
    this->state = nts::Tristate::UNDEFINED;
    this->computed = false;
    this->func_op = func_op;
    this->type = type;
    this->fatherPinVector = fatherPinNb;
}