/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** c4008.hpp
*/

#ifndef C4008_HPP
    #define C4008_HPP

    /*Includes*/
    #include <string>
    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include "IComponent.hpp"
    #include "AComponent.hpp"

    class c4008: public AComponent
    {
        public:
        c4008(const std::string &value);
        ~c4008();

        nts::Tristate compute(std::size_t pin = 1);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;
    };
#endif /*C4008_HPP*/