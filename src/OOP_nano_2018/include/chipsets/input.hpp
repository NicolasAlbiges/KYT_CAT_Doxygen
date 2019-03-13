/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** input.hpp
*/

#ifndef INPUT_HPP
    #define INPUT_HPP

    /*Includes*/
    #include <string>
    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include "IComponent.hpp"
    #include "AComponent.hpp"

    class input: public AComponent
    {
        public:
        input(const std::string &value);
        ~input();

        nts::Tristate compute(std::size_t pin = 1);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

        void setStatu(nts::Tristate, std::size_t pin = 1);
    };
#endif /*INPUT_HPP*/