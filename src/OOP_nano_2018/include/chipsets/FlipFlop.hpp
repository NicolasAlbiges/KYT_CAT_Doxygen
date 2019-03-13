/*
** EPITECH PROJECT, 2018
** cpp_d06_2018
** File description:
** ex01/FlipFlop.hpp
*/

#ifndef FLIPFLOP_HPP
    #define FLIPFLOP_HPP

    /*Includes*/
    #include <string>
    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include "IComponent.hpp"
    #include "AComponent.hpp"

    class FlipFlop: public AComponent
    {
        public:
        FlipFlop();
        ~FlipFlop();

        enum FlipFlopPin {
            SET = 0,
            DATA = 1,
            RESET = 2,
            CLOCK = 3,
            Q = 4,
            _Q = 5,
        };

        nts::Tristate compute(std::size_t pin = 1);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

        private:
        nts::Tristate _old_clock;
    };
#endif /*FLIPFLOP_HPP*/