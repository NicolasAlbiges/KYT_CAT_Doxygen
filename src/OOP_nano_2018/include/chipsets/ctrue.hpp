/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** ctrue.hpp
*/

#ifndef CTRUE_HPP
    #define CTRUE_HPP

    /*Includes*/
    #include <string>
    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include "IComponent.hpp"
    #include "AComponent.hpp"

    class ctrue: public AComponent
    {
        public:
        ctrue(const std::string &value);
        ~ctrue();

        nts::Tristate compute(std::size_t pin = 1);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;
    };
#endif /*CTRUE_HPP*/