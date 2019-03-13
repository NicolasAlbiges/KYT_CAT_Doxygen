/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** c4017.hpp
*/

#ifndef C4017_HPP
    #define C4017_HPP

    /*Includes*/
    #include <string>
    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include "IComponent.hpp"
    #include "AComponent.hpp"

    class c4017: public AComponent
    {
        public:
        c4017(const std::string &value);
        ~c4017();

        nts::Tristate compute(std::size_t pin = 1);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

        void reset();

        private:
        nts::Tristate _old_clock0;
        nts::Tristate _old_clock1;
        int _counter_value;
    };
#endif /*C4017_HPP*/