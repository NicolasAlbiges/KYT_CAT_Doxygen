/*
** EPITECH PROJECT, 2018
** cpp_nanoterkspice
** File description:
** parse.hpp
*/

#ifndef PARSE_HPP
#define PARSE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include "Circuit.hpp"

class Parsing
{
    public:
        Parsing(int ac, char **av);
        ~Parsing();
        void set_data(std::string file_name);
        void file();
        int get_ac() const;
        char** get_av() const;
        void fill_vector_data(std::string str, int b);
        int parse();
        std::vector<std::string> get_links() const;
        std::vector<std::string> get_chipsets() const;
        std::vector<std::string*> get_chipsets_end() const;
        std::vector<std::string*> get_links_end() const;
        std::vector<std::string*> get_input() const;
        void parse_end();
        void parse_input();
        void change_input_links();
        std::string get_data() const;
        void sort_link();
        std::string get_name_comp(std::string name);
        std::string remove_comment(std::string str);


    protected:
        int _ac;
        char **_av;
        std::string _data;
        std::vector<std::string> _chipsets;
        std::vector<std::string> _links;
        std::vector<std::string*> _chipsets_fin;
        std::vector<std::string*> _links_fin;
        std::vector<std::string*> _input;
        
};

std::string read_file(const char *file_name);
int size_of_array(std::string *tab);
std::string* word_array(std::string str, char *sep);

void prompt(Circuit &circuit);

#endif