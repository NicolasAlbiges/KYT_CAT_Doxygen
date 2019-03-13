/*
** EPITECH PROJECT, 2018
** cpp_d06_2018
** File description:
** ex01/IComponent.hpp
*/

#ifndef ICOMPONENT_HPP
    #define ICOMPONENT_HPP

    /*Includes*/
    #include <string>
    #include <iostream>
    #include <algorithm>
    #include <memory>
    #include <vector>

    namespace nts
    {
        #define MGETFATHER(_pin, pin) _pin[pin]->father->compute(_pin[pin]->fatherPinVector[0])
        #define MCPTGATE(_pin, pin) (_pin[pin]->func_op(compute(_pin[pin]->fatherPinVector[0]),compute(_pin[pin]->fatherPinVector[1])))
        enum Tristate {
            UNDEFINED = (-true),
            TRUE = true,
            FALSE = false
        };

        enum Operation {
            GETSTATE,
            GETFATHER,
            AND,
            OR,
        };
        enum PinType {
            INPUT,
            OUTPUT,
            CLOCK,
            RESET,
            OTHER,
        };

        class IComponent
        {
            public:
            virtual ~IComponent () = default;
            public:
            virtual nts::Tristate compute(std::size_t pin = 1) = 0;
            virtual void setLink(std::size_t pin, nts::IComponent &other, std::size_t otherPin) = 0;
            virtual void dump() const = 0;

        };

        typedef nts::Tristate (*op_func_pt)(std::vector<nts::Tristate> &);

        typedef struct pin_s {

            pin_s(nts::op_func_pt func_op,
            nts::PinType type, nts::IComponent *father,
            std::vector<int> fatherPinVector);

            Tristate state;
            IComponent *father;
            Operation operation;
            bool computed;
            op_func_pt func_op;
            PinType type;
            std::vector<int> fatherPinVector;
        } pin_t;

    }

    nts::pin_t *create_pin(nts::op_func_pt func_op,
    nts::PinType type, nts::IComponent *father);

    nts::Tristate GateAND(std::vector<nts::Tristate> &);
    nts::Tristate GateNOR(std::vector<nts::Tristate> &);
    nts::Tristate GateSUM(std::vector<nts::Tristate> &);
    nts::Tristate GateNAND(std::vector<nts::Tristate> &);
    nts::Tristate GateXOR(std::vector<nts::Tristate> &);
    nts::Tristate GateOR(std::vector<nts::Tristate> &);
    nts::Tristate GateNOT(std::vector<nts::Tristate> &pin_state);

    char *nbr_base_to_str(unsigned long long nbr, char const *base, int i);

#endif /*ICOMPONENT_HPP*/