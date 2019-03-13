/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** output.hpp
*/

#ifndef OUTPUT_HPP
    #define OUTPUT_HPP

    /*Includes*/
    #include <string>
    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include "IComponent.hpp"
    #include "AComponent.hpp"

    class output: public AComponent
    {
        public:
        output(const std::string &value);
        ~output();

        nts::Tristate compute(std::size_t pin = 1);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;
    };

#endif /*OUTPUT_HPP*/