/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** c4069.hpp
*/

#ifndef C4069_HPP
    #define C4069_HPP

    /*Includes*/
    #include <string>
    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include "IComponent.hpp"
    #include "AComponent.hpp"

    class c4069: public AComponent
    {
        public:
        c4069(const std::string &value);
        ~c4069();

        nts::Tristate compute(std::size_t pin = 1);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;
    };
#endif /*C4069_HPP*/