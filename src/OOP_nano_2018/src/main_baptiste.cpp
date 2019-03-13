/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** src/main.cpp
*/

#include "Circuit.hpp"
#include "c4081.hpp"
#include "c4013.hpp"
#include "c4001.hpp"
#include "c4008.hpp"
#include "c4011.hpp"
#include "c4030.hpp"
#include "input.hpp"
#include "output.hpp"


nts::Tristate GateSUM(std::vector<nts::Tristate> &pin_state);

int main()
{
    //c4001 *comp = new c4001("c4081");
    //c4081 *comp1 = new c4081("c4081_two");
    //c4008 *comp2 = new c4008("c4008");
    c4030 *comp3 = new c4030("c4030");
    input *i0 = new input("i0");
    input *i1 = new input("i1");
    input *i2 = new input("i2");
    input *i3 = new input("i3");
    input *i4 = new input("i4");
    output *o1 = new output("o1");

    i0->setStatu(nts::UNDEFINED);
    i1->setStatu(nts::FALSE);
    i2->setStatu(nts::FALSE);
    i3->setStatu(nts::TRUE);
    i4->setStatu(nts::TRUE);

    comp3->setLink(1, *i0, 1);
    comp3->setLink(2, *i1, 1);

    std::cout << "statu computed = " << comp3->compute(3) << std::endl;
    return 0;
}