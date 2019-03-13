#include "parse.hpp"
#include "error.hpp"
#include "Circuit.hpp"

void print_vector_debug(std::vector<std::string> vector)
{
    for (unsigned int ct = 0; ct != vector.size(); ct ++)
        std::cout << vector[ct] << std::endl;
}

void print_tab_debug(std::vector<std::string*> vector)
{
    for (unsigned int ct = 0; ct != vector.size(); ct ++) {
        for (int ctb = 0; vector[ct][ctb] != " "; ctb ++)
            std::cout << vector[ct][ctb] << "\t\t";
        std::cout << std::endl;
    }
}

void error_ac(Error &error, Parsing &parse)
{
    if (error.arguments(parse.get_ac()) == 84) {
            std::cout << "Not enought paramets, ./nanotekspice circuit_file.nts input_name=input_value\n";
            throw std::exception();
        }
}

void size_comps(Error &error, Parsing &parse)
{
    if (error.error_size_array(parse.get_chipsets_end(), 2) == 84
        || error.error_size_array(parse.get_links_end(), 4) == 84) {
        std::cout << "Not the good number of links or components \n";
        throw std::exception();
    }
}

void match_comp(Error &error, Parsing &parse)
{
    if (error.match_comp(parse.get_chipsets_end(), parse.get_links_end(), 0) == 84) {
        std::cout << "Not the good components in the links list \n";
        throw std::exception();
    }
    if (error.match_comp(parse.get_chipsets_end(), parse.get_links_end(), 2) == 84) {
        std::cout << "Not the good components in the links list \n";
        throw std::exception();
    }
}

void check_input(Error &error, Parsing &parse)
{
    if (error.error_size_array(parse.get_input(), 2) == 84) {
        std::cout << "Too much arguments, not type of 'input_name=input_value'\n";
        throw std::exception();
    }
    if (error.match_comp(parse.get_chipsets_end(), parse.get_input(), 0) == 84) {
        std::cout << "Not the good components in the input list \n";
        throw std::exception();
    }
    if (error.check_input(parse.get_chipsets_end(), parse.get_input()) == 84) {
        std::cout << "Not the good input comps in the input list \n";
        throw std::exception();
    }
}

void check_and_parse_file(int ac, Parsing &parse)
{
    Error error;

    error_ac(error, parse);
    parse.set_data(parse.get_av()[1]);
    if (error.file_name(parse.get_data()) == 84)
        throw std::exception();
    parse.parse();
    parse.parse_end();
    parse.change_input_links();
    size_comps(error, parse);
    match_comp(error, parse);
    error.check_same_comp(parse.get_chipsets_end());
    if (error.check_pin(parse.get_links_end()) == 84) {
        std::cout << "Not the good pin \n";
        throw std::exception();
    }
    parse.parse_input();
    check_input(error, parse);
    error.check_comp_names(parse.get_chipsets_end());
}

int main(int ac, char **av)
{
    Circuit circuit;
    Parsing parse(ac, av);

    try {
        check_and_parse_file(ac, parse);
        circuit.createComponents(parse.get_chipsets_end());
        circuit.createLinks(parse.get_links_end());
        circuit.setStates(parse.get_input());
    } catch (const std::exception &e) {
        return 84;
    }
    prompt(circuit);
    return (0);
}