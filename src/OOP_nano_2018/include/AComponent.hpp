/*
** EPITECH PROJECT, 2018
** OOP_nanotekspice_2018
** File description:
** include/AComponent.hpp
*/

#ifndef ACOMPONENT_HPP
    #define ACOMPONENT_HPP

    /*Includes*/
    #include <string>
    #include <iostream>
    #include <algorithm>
    #include <memory>
    #include <vector>
    #include "IComponent.hpp"

    class AComponent: public nts::IComponent
    {
        public:
        AComponent();
        ~AComponent();

        std::string getValue() const;
        std::vector<std::size_t> getValidPinNumber() const;
        std::string getType() const;

        protected:
        std::string _value;
        std::string _type;
        std::size_t _nbOfPin;
        std::vector<nts::pin_t *> _pin;
    };

#endif /*ACOMPONENT_HPP*/