/*
** EPITECH PROJECT, 2018
** cpp_rush3_2018
** File description:
** tools/cpp/readFile.cpp
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

std::string read_file(const char *file_name)
{
    std::ifstream myfile;
    std::ios_base::openmode mode = std::ios_base::in;
    std::string str;
    std::string data;

    myfile.open(file_name, mode);
    if (myfile.good() == false) {
        std::cerr << file_name << ": No such file or directory" << std::endl;
        return "ERROR";
    }
    while (getline(myfile, str)) {
        data = data + str;
        if (myfile.good())
            data = data + "\n";
    }
    myfile.close();
    return (data);
}