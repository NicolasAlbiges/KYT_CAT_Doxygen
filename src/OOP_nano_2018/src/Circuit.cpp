/*
** EPITECH PROJECT, 2018
** cpp_d06_2018
** File description:
** ex01/Circuit.cpp
*/

#include "Circuit.hpp"
#include "error.hpp"

Circuit::Circuit()
{
}

Circuit::~Circuit()
{
}

void Circuit::compute()
{
    for (int i = 0, max = _components.size(); i < max; i += 1) {
        if (dynamic_cast<output *>(_components[i].get())) {
            _components[i]->compute(1);
        }
    }
    this->loopClock();
}

void Circuit::dump() const
{
    std::map<std::string, int> outputSorted;
    std::map<std::string, int>::iterator it;
    nts::IComponent *tmp_icomp;
    AComponent *tmp_acomp;

    for (int i = 0, max = _components.size(); i < max; i += 1) {
        tmp_icomp = _components[i].get();
        tmp_acomp = static_cast<AComponent *>(tmp_icomp);
        outputSorted[tmp_acomp->getValue()] = i;
    }
    for ( it = outputSorted.begin(); it != outputSorted.end(); it++ )
        _components[it->second]->dump();
}

void Circuit::createComponents(std::vector<std::string*> _chipsets_fin)
{
    Factory fac;

    for (size_t ct = 0; ct != _chipsets_fin.size(); ct ++) {
        _components.push_back(std::move(fac.createComponent(_chipsets_fin[ct][0], _chipsets_fin[ct][1])));
    }
}

void Circuit::createLinks(std::vector<std::string*> _links_fin)
{
    std::size_t pinSrc = 100;
    std::size_t pinDest = 100;
    std::unique_ptr<nts::IComponent> *chipsetSrc = nullptr;
    std::unique_ptr<nts::IComponent> *chipsetDest = nullptr;
    Error error;
    nts::IComponent *tmp_icomp = nullptr;
    AComponent *tmp_acomp = nullptr;
    AComponent *AchipsetSrc = nullptr;
    AComponent *AchipsetDest = nullptr;
    

    for (size_t ct = 0; ct != _links_fin.size(); ct ++) {
        pinSrc = std::stoi(_links_fin[ct][1]);
        pinDest = std::stoi(_links_fin[ct][3]);
        for (int i = 0, max = _components.size(); i < max; i += 1) {
            if (_components[i].get() == nullptr) {
                std::cout << "Invalid null component: Please check the factory." << std::endl;
                exit (84);
            }
            tmp_icomp = _components[i].get();
            tmp_acomp = static_cast<AComponent *>(tmp_icomp);
            if (tmp_acomp->getValue() == _links_fin[ct][0])
                chipsetSrc = &_components[i];
            else if (tmp_acomp->getValue() == _links_fin[ct][2])
                chipsetDest = &_components[i];
        }
        if (chipsetDest == nullptr || chipsetSrc == nullptr) {
            std::cerr << "createLinks: Can't found chipset to link" << std::endl;
            return;
        }
        tmp_icomp = chipsetSrc->get();
        AchipsetSrc = static_cast<AComponent *>(tmp_icomp);
        tmp_icomp = chipsetDest->get();
        AchipsetDest = static_cast<AComponent *>(tmp_icomp);
        error.check_comp_names(AchipsetSrc->getValidPinNumber(),
        AchipsetDest->getValidPinNumber(), pinSrc, pinDest);
//        std::cout << "createLinks: " << chipsetDest->get()->getValue() << "[" << pinDest << "] ";
//        std::cout << "and " << chipsetSrc->get()->getValue() << "[" << pinSrc << "]" << std::endl;
        if (AchipsetSrc->getType() == "output"
        || AchipsetDest->getType() == "intput"
        || AchipsetDest->getType() == "ctrue"
        || AchipsetDest->getType() == "cfalse") {
            //std::cout << "Link " << AchipsetDest->getValue() << " pin " << pinDest;
            //std::cout << " into " << AchipsetSrc->getValue() << " pin " << pinSrc << std::endl;
            chipsetSrc->get()->setLink(pinSrc, *chipsetDest->get(), pinDest);
        } else {
            //std::cout << "Link " << AchipsetSrc->getValue() << " pin " << pinSrc;
            //std::cout << " into " << AchipsetDest->getValue() << " pin " << pinDest << std::endl;
            chipsetDest->get()->setLink(pinDest, *chipsetSrc->get(), pinSrc);
        }
    }
}

void Circuit::setSingleComponentState(std::string componentValue, std::string stateValue)
{
    input *tmp;
    nts::IComponent *tmp_icomp;
    AComponent *tmp_acomp;

    for (int i = 0, max = _components.size(); i < max; i += 1) {
        tmp_icomp = _components[i].get();
        tmp_acomp = static_cast<AComponent *>(tmp_icomp);
        if (tmp_acomp->getValue() == componentValue &&
        stateValue == "0") {
            tmp = static_cast<input *>(tmp_acomp);
            tmp->setStatu(nts::Tristate::FALSE);
        } else if (tmp_acomp->getValue() == componentValue &&
        stateValue == "1") {
            tmp = static_cast<input *>(tmp_acomp);
            tmp->setStatu(nts::Tristate::TRUE);
        }
    }
}

void Circuit::setStates(std::vector<std::string*> _input)
{
    input *tmp;
    nts::IComponent *tmp_icomp;
    AComponent *tmp_acomp;

    for (size_t ct = 0; ct != _input.size(); ct ++) {
        for (int i = 0, max = _components.size(); i < max; i += 1) {
            tmp_icomp = _components[i].get();
            tmp_acomp = static_cast<AComponent *>(tmp_icomp);
            if (tmp_acomp->getValue() == _input[ct][0] &&
            _input[ct][1] == "0") {
                tmp = static_cast<input *>(_components[i].get());
                tmp->setStatu(nts::Tristate::FALSE);
            } else if (tmp_acomp->getValue() == _input[ct][0] &&
            _input[ct][1] == "1") {
                tmp = static_cast<input *>(_components[i].get());
                tmp->setStatu(nts::Tristate::TRUE);
            }
        }
    }
}

void Circuit::loopClock()
{
    cclock *tmp_clock;
    nts::IComponent *tmp_icomp;
    AComponent *tmp_acomp;

    for (int i = 0, max = _components.size(); i < max; i += 1) {
        tmp_icomp = _components[i].get();
        tmp_acomp = static_cast<AComponent *>(tmp_icomp);
        if (tmp_acomp->getType() == "cclock") {
            tmp_clock = static_cast<cclock *>(_components[i].get());
            tmp_clock->loop();
        }
    }
}