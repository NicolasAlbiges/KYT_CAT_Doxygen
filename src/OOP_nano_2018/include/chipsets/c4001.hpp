/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** c4001.hpp
*/

#ifndef C4001_HPP
    #define C4001_HPP

    /*Includes*/
    #include <string>
    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include "AComponent.hpp"
    #include "IComponent.hpp"

    class c4001: public AComponent
    {
        public:
        c4001(const std::string &value);
        ~c4001();

        nts::Tristate compute(std::size_t pin = 1);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;
    };
#endif /*C4001_HPP*/