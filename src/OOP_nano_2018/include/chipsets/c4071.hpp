/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** c4071.hpp
*/

#ifndef C4071_HPP
    #define C4071_HPP

    /*Includes*/
    #include <string>
    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include "IComponent.hpp"
    #include "AComponent.hpp"

    class c4071: public AComponent
    {
        public:
        c4071(const std::string &value);
        ~c4071();

        nts::Tristate compute(std::size_t pin = 1);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;
    };

#endif /*C4071_HPP*/