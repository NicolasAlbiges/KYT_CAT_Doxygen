#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <unordered_map>
#include "Circuit.hpp"

void display(Circuit &circuit)
{
    circuit.dump();
}

void my_exit(Circuit &circuit)
{
    exit(0);
}

void simulate(Circuit &circuit)
{
    circuit.compute();
}

void set_state(Circuit &circuit, std::string &input)
{
    std::string componentValue = input.substr(0, input.find("="));
    std::string stateValue = input.substr(input.find("=") + 1, input.size());

    circuit.setSingleComponentState(componentValue, stateValue);
}

void prompt(Circuit &circuit)
{
    std::string str;

    typedef void (*func)(Circuit &);
    std::unordered_map<std::string, func> func_map;
    func tmp;

    func_map["exit"] = my_exit;
    func_map["display"] = display;
    func_map["simulate"] = simulate;
    simulate(circuit);
    display(circuit);
    std::cout << "> ";
    while(getline(std::cin, str)) {
        tmp = (func)func_map[str];
        if (tmp)
            tmp(circuit);
        else
            set_state(circuit, str);
        std::cout <<"> ";
    }
    std::cout << std::endl;
}
