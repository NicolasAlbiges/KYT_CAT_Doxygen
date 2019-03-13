/*
** EPITECH PROJECT, 2018
** cpp_nanotekspice
** File description:
** size_array.cpp
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cstring>
#include <thread>
#include <unistd.h>
#include <vector>

int size_of_array(std::string *tab)
{
    int nbr = 0;

    if (tab == nullptr)
        return 0;
    for (int ct = 0; tab[ct][0] != ' '; ct ++)
        nbr ++;
    return nbr;
}