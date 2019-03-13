/*
** EPITECH PROJECT, 2018
** OPP_nanotekspice_2018
** File description:
** cclock.hpp
*/

#ifndef CCLOCK_HPP
    #define CCLOCK_HPP

    /*Includes*/
    #include <string>
    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include "IComponent.hpp"
    #include "AComponent.hpp"

    class cclock: public AComponent
    {
        public:
        cclock(const std::string &value);
        ~cclock();

        nts::Tristate compute(std::size_t pin = 1);
        void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin);
        void dump() const;

        void loop();
    };
#endif /*CCLOCK_HPP*/