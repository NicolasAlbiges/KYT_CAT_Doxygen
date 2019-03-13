/*
** EPITECH PROJECT, 2018
** cpp_nanoterkspice
** File description:
** Error.hpp
*/

#ifndef ERROR_HPP
#define ERROR_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <exception>
#include <vector>

class Error
{
    public:
        Error();
        ~Error();
        int Error_handling(std::string str);
        int arguments(int ac);
        int error_size_array(std::vector<std::string*> chipsets, unsigned int nbr);
        int check_comp(std::vector<std::string*> comps, std::string comp);
        int match_comp(std::vector<std::string*> comps, std::vector<std::string*> links, int ctb);
        int same_comp(std::vector<std::string*> comps, std::string comp, int index);
        int check_same_comp(std::vector<std::string*> chipsets_fin);
        int check_pin(std::vector<std::string*> links);
        int check_input(std::vector<std::string*> comp, std::vector<std::string*> input);
        int file_name(std::string str);
        int check_comp_names(std::vector<std::string*> links);
        int check_comp_names(std::vector<std::size_t> nbr_pins_src,
        std::vector<std::size_t> nbr_pins_dest,
        std::size_t pinSrc, std::size_t pinDest);

    protected:
        int _status;
        
};

int size_of_array(std::string *tab);


#endif