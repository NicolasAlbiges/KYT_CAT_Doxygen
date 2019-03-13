/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** src/Gate.cpp
*/

#include "IComponent.hpp"

nts::Tristate GateAND(std::vector<nts::Tristate> &pin_state)
{
    int nb_undefined = 0;

    for (auto &p: pin_state) {
        nb_undefined += (p == nts::UNDEFINED) ? 1 : 0;
        if (p == nts::FALSE)
            return (nts::FALSE);
    }
    if (nb_undefined > 0)
        return (nts::UNDEFINED);
    return (nts::TRUE);
}

nts::Tristate GateOR(std::vector<nts::Tristate> &pin_state)
{
    for (auto &p: pin_state) {
        if (p == nts::TRUE)
            return (nts::TRUE);
    }
    return (nts::FALSE);
}

nts::Tristate GateNAND(std::vector<nts::Tristate> &pin_state)
{
    nts::Tristate rslt = GateAND(pin_state);

    if (rslt == nts::FALSE)
        return (nts::TRUE);
    else if (rslt == nts::TRUE)
        return (nts::FALSE);
    return (nts::UNDEFINED);
}


nts::Tristate GateNOR(std::vector<nts::Tristate> &pin_state)
{
    int nb_undefined = 0;

    for (auto &p: pin_state) {
        nb_undefined += (p == nts::UNDEFINED) ? 1 : 0;
        if (p == nts::TRUE)
            return (nts::Tristate::FALSE);
    }
    if (nb_undefined > 0)
        return (nts::UNDEFINED);
    return (nts::Tristate::TRUE);
}

nts::Tristate GateSUM(std::vector<nts::Tristate> &pin_state)
{
    short sum = 0;

    for (auto &p: pin_state) {
        if (p == nts::UNDEFINED)
            return (nts::UNDEFINED);
        if (p == nts::TRUE)
            sum += 1;
    }
    return ((nts::Tristate)sum);
}

nts::Tristate GateXOR(std::vector<nts::Tristate> &pin_state)
{
    if (pin_state[0] == nts::UNDEFINED || pin_state[1] == nts::UNDEFINED)
        return (nts::UNDEFINED);
    else if (pin_state[0] != pin_state[1])
        return (nts::TRUE);
    return (nts::FALSE);
}

nts::Tristate GateNOT(std::vector<nts::Tristate> &pin_state)
{
    if (pin_state[0] == nts::UNDEFINED)
        return (nts::UNDEFINED);
    if (pin_state[0] == nts::TRUE)
        return (nts::FALSE);
    else if (pin_state[0] == nts::FALSE)
        return (nts::TRUE);
    return (nts::UNDEFINED);
}
