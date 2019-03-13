/*
** EPITECH PROJECT, 2018
** cpp_nanoterkspice
** File description:
** Error.hpp
*/

#include "error.hpp"

Error::~Error()
{

}

Error::Error()
{
}

int Error::arguments(int ac)
{
    if (1 == ac)
        return 84;
    return 0;
}

int Error::file_name(std::string str)
{
    if (str == "ERROR")
        return 84;
    return 0;
}

int Error::Error_handling(std::string str)
{
    if (str.find(".chipsets:") == std::string::npos
    || str.find(".links:") == std::string::npos)
        return 84;
    return 0;
}

int Error::error_size_array(std::vector<std::string*> chipsets, unsigned int nbr)
{
    for (unsigned int ct = 0, ctb = 0; ct != chipsets.size(); ct ++)
        if ((ctb = size_of_array(chipsets[ct])) != nbr && ctb != 0)
            return 84;
    return 0;
}

int Error::check_comp(std::vector<std::string*> comps, std::string comp)
{
    for (unsigned int ct = 0; ct != comps.size(); ct ++) {
        if (comps[ct][0] != " " && (comps[ct][0].find(comp) != std::string::npos || comps[ct][1].find(comp) != std::string::npos))
            return 0;
    }
    return 84;
}

int Error::match_comp(std::vector<std::string*> comps, std::vector<std::string*> links, int ctb)
{
    for (unsigned int ct = 0; ct != links.size(); ct ++) {
        if (check_comp(comps, links[ct][ctb]) == 84)
            return 84;
    }
    return 0;
}

int Error::same_comp(std::vector<std::string*> comps, std::string comp, int index)
{
    for (unsigned int ct = 0; ct != comps.size(); ct ++) {
        if (comps[ct][0] != " " && (unsigned int)index != ct && comps[ct][1] == comp)
            return 84;
    }
    return 0;
}

int Error::check_same_comp(std::vector<std::string*> chipsets_fin)
{
    for (unsigned int ct = 0; ct != chipsets_fin.size(); ct ++) {
        if (chipsets_fin[ct][0] != " " && same_comp(chipsets_fin, chipsets_fin[ct][1], ct) == 84) {
            std::cout << chipsets_fin[ct][1] << std::endl;
            return 84;
        }
    }
    return 0;
}

int Error::check_input(std::vector<std::string*> comp, std::vector<std::string*> input)
{
    for (unsigned int ct = 0, b = 0; ct != input.size(); ct ++) {
        if (input[ct][1] != "1" && input[ct][1] != "0")
            return (84);
        for (unsigned int ctb = 0; ctb != comp.size(); ctb ++)
            if (comp[ctb][0] != " " && (((comp[ctb][0] == "input" && comp[ctb][1] == input[ct][0])) || (comp[ctb][0] == "clock" && comp[ctb][1] == input[ct][0])))
                b = 1;
        if (b == 0)
            return (84);
        b = 0;
    }
    return 0;
}

int Error::check_pin(std::vector<std::string*> links)
{
    for (unsigned int ct = 0; ct != links.size(); ct ++) {
        for (int ctb = 0; links[ct][0] != " " && links[ct][1][ctb] != '\0'; ctb ++)
            if (links[ct][1][ctb] != '-' && (links[ct][1][ctb] > '9' || links[ct][1][ctb] < '0'))
                return 84;
        for (int ctb = 0; links[ct][0] != " " && links[ct][3][ctb] != '\0'; ctb ++)
            if (links[ct][3][ctb] != '-' && (links[ct][3][ctb] > '9' || links[ct][3][ctb] < '0'))
                return 84;
        //APPELLER LA FONCTION POUR SAVOIR LE NOMBRE MAX DE PIN        
        // if (get_size(links[ct][0]) > atoi(links[ct][1].c_str()) || get_size(links[ct][2]) > atoi(links[ct][3].c_str())
        //     return 84;
    }
    return 0;
}

int Error::check_comp_names(std::vector<std::string*> comps)
{
    std::string comp[] = {"true", "false", "output", "clock", "input", "4001",
    "4008", "4011", "4013", "4017", "4030", "4040", "4069", "4071", "4081",
    "4094", "4503", "4512", "4514", "i4004", "mk4081", "END"};

    for (unsigned int ct = 0, b = 1; ct != comps.size(); ct ++) {
        for (int ctb = 0; comp[ctb] != "END"; ctb ++) {
            if (comps[ct][0] == comp[ctb])
                b = 0;
        }
        if (b == 1) {
            std::cerr << "Not the good comps in the comp list" << std::endl;
            throw std::exception();
        }
        b = 1;
    }
    return 0;
}

int Error::check_comp_names(std::vector<std::size_t> nbr_pins_src,
std::vector<std::size_t> nbr_pins_dest,
std::size_t pinSrc, std::size_t pinDest)
{
    for (unsigned int ct = 0; ct != nbr_pins_src.size(); ct ++) {
        if (pinSrc == (nbr_pins_src[ct] + 1))
            break;
        if ((ct + 1) == nbr_pins_src.size()) {
            std::cerr << "Not the good pin with the components" << std::endl;
            throw std::exception();
        }
    }
    for (unsigned int ct = 0; ct != nbr_pins_dest.size(); ct ++) {
        if (pinDest == (nbr_pins_dest[ct] + 1))
            break;
        if ((ct + 1) == nbr_pins_dest.size()) {
            std::cerr << "Not the good pin with the components" << std::endl;
            throw std::exception();
        }
    }
    return 0;
}