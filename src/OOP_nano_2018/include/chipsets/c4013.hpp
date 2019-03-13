/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** c4013.hpp
*/

#ifndef C4013_HPP
    #define C4013_HPP

    /*Includes*/
    #include <string>
    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include "IComponent.hpp"
    #include "FlipFlop.hpp"
    #include "AComponent.hpp"

    class c4013: public AComponent
    {
        public:
        c4013(const std::string &value);
        ~c4013();

        nts::Tristate compute(std::size_t pin = 1);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

        private:
        FlipFlop *_FF1;
        FlipFlop *_FF2;
    };
#endif /*C4013_HPP*/