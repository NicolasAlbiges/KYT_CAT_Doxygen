/*
** EPITECH PROJECT, 2018
** cpp_nanoterkspice
** File description:
** parse.hpp
*/

#include "parse.hpp"

Parsing::~Parsing()
{

}

Parsing::Parsing(int ac, char **av)
{
    _ac = ac;
    _av = av;
}

void Parsing::set_data(std::string file_name)
{
    _data = read_file(file_name.c_str());
}

std::string Parsing::get_data() const
{
    return _data;
}

int Parsing::get_ac() const
{
    return _ac;
}

char **Parsing::get_av() const
{
    return _av;
}

std::vector<std::string> Parsing::get_chipsets() const
{
    return _chipsets;
}

std::vector<std::string> Parsing::get_links() const
{
    return _links;
}

std::vector<std::string*> Parsing::get_chipsets_end() const
{
    return _chipsets_fin;
}

std::vector<std::string*> Parsing::get_links_end() const
{
    return _links_fin;
}

std::vector<std::string*> Parsing::get_input() const
{
    return _input;
}

std::string Parsing::remove_comment(std::string str)
{
    if (str.find("#") != std::string::npos)
        return str.substr(0, str.find("#"));
    if (str.find("#") == 0)
        return " ";
    return str;
}

void Parsing::fill_vector_data(std::string str, int b)
{
    if (b == 1 && str.find(".links:") == std::string::npos
    && str.find(".chipsets:") == std::string::npos) {
        _chipsets.push_back(remove_comment(str));
        return;
    } else if (b ==2 && str.find(".links:") == std::string::npos
    && str.find(".chipsets:") == std::string::npos)
    _links.push_back(remove_comment(str));
}

int Parsing::parse()
{
    std::istringstream data = std::istringstream(_data);
    std::string str;
    int b = 0;

    while (getline(data, str)) {
        fill_vector_data(str, b);
        if (str.find(".chipsets:") != std::string::npos)
            b = 1;
        if (str.find(".links:") != std::string::npos)
            b = 2;
    }
    return 0;
}

void Parsing::parse_end()
{
    char sep[] = ": \t\0";
    std::string* tab;

    for (unsigned int ct = 0; ct != _chipsets.size(); ct ++) {
        tab = word_array(_chipsets[ct], sep);
        if (_chipsets[ct][0] != '#' && tab[0] != " ")
            _chipsets_fin.push_back(tab);
    }
    for (unsigned int ct = 0; ct != _links.size(); ct ++) {
        tab = word_array(_links[ct], sep);
        if (_links[ct][0] != '#' && tab[0] != " ")
            _links_fin.push_back(word_array(_links[ct], sep));
    }
}

void Parsing::change_input_links()
{
    char sep[] = "=";

    for (unsigned int ct = 0; ct != _chipsets_fin.size(); ct ++) {
        if ((_chipsets_fin[ct][0] == "input" 
        && _chipsets_fin[ct][1].find(')') != std::string::npos 
        && (_chipsets_fin[ct][1].find(')') + 1) == _chipsets_fin[ct][1].size()) 
        || (_chipsets_fin[ct][0] == "clock" 
        && _chipsets_fin[ct][1].find(')') != std::string::npos 
        && (_chipsets_fin[ct][1].find(')') + 1) == _chipsets_fin[ct][1].size())) {
            _input.push_back(word_array(_chipsets_fin[ct][1].substr(0, _chipsets_fin[ct][1].find('(')) + "=" + _chipsets_fin[ct][1].substr(_chipsets_fin[ct][1].find('(') + 1, _chipsets_fin[ct][1].find(')') - (_chipsets_fin[ct][1].find('(') + 1)), sep));
            _chipsets_fin[ct][1] = _chipsets_fin[ct][1].substr(0, _chipsets_fin[ct][1].find('('));
        }
    }
}

void Parsing::parse_input()
{
    char sep[] = "=";

    for (int ct = 2; ct != _ac; ct ++)
        _input.push_back(word_array(std::string(_av[ct]), sep));
}