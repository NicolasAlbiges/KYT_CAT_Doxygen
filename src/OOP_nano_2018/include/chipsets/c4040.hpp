/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** c4040.hpp
*/

#ifndef C4040_HPP
    #define C4040_HPP

    /*Includes*/
    #include <string>
    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include "IComponent.hpp"
    #include "AComponent.hpp"

    class c4040: public AComponent
    {
        public:
        c4040(const std::string &value);
        ~c4040();

        nts::Tristate compute(std::size_t pin = 1);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

        private:
        int _clock_size;
        nts::Tristate _old_clock;
    };
#endif /*C4040_HPP*/