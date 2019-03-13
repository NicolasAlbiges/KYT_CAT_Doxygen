/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** cfalse.hpp
*/

#ifndef CFALSE_HPP
    #define CFALSE_HPP

    /*Includes*/
    #include <string>
    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include "IComponent.hpp"
    #include "AComponent.hpp"

    class cfalse: public AComponent
    {
        public:
        cfalse(const std::string &value);
        ~cfalse();

        nts::Tristate compute(std::size_t pin = 1);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;
    };
#endif /*CFALSE_HPP*/