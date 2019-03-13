/*
** EPITECH PROJECT, 2018
** cpp_d06_2018
** File description:
** ex01/Circuit.hpp
*/

#ifndef CIRCUIT_HPP
    #define CIRCUIT_HPP

    /*Includes*/
    #include <string>
    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include "IComponent.hpp"
    #include "Factory.hpp"
    #include "input.hpp"
    #include "cclock.hpp"

    class Circuit
    {
        public:
        Circuit();
        ~Circuit();

        void compute();
        void dump() const;

        void createComponents(std::vector<std::string*> _chipsets_fin);
        void createLinks(std::vector<std::string*> _links_fin);
        void setStates(std::vector<std::string*> _input);

        void setSingleComponentState(std::string componentValue, std::string stateValue);
        void loopClock();

        private:
        std::vector<std::unique_ptr<nts::IComponent>> _components;
        //std::vector<nts::IComponent *> _components;
    };

#endif /*CIRCUIT_HPP*/