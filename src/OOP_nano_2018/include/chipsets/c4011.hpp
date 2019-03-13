/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** c4011.hpp
*/

#ifndef C4011_HPP
    #define C4011_HPP

    /*Includes*/
    #include <string>
    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include "IComponent.hpp"
    #include "AComponent.hpp"

    class c4011: public AComponent
    {
        public:
        c4011(const std::string &value);
        ~c4011();

        nts::Tristate compute(std::size_t pin = 1);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;
    };
#endif /*C4011_HPP*/