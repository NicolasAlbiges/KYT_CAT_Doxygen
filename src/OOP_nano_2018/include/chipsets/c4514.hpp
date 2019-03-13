/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** c4514.hpp
*/

#ifndef C4514_HPP
    #define C4514_HPP

    /*Includes*/
    #include <string>
    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include "IComponent.hpp"
    #include "AComponent.hpp"

    class c4514: public AComponent
    {
        public:
        c4514(const std::string &value);
        ~c4514();

        nts::Tristate compute(std::size_t pin = 1);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;
    };
#endif /*C4514_HPP*/