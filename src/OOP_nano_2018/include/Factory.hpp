/*
** EPITECH PROJECT, 2018
** cpp_d06_2018
** File description:
** ex01/Factory.hpp
*/

#ifndef FACTORY_HPP
    #define FACTORY_HPP

    /*Includes*/
    #include <string>
    #include <iostream>
    #include <algorithm>
    #include <vector>
    #include <memory>
    #include <map>
    #include <unordered_map>
    #include "IComponent.hpp"

    #include "input.hpp"
    #include "output.hpp"
    #include "ctrue.hpp"
    #include "cfalse.hpp"
    #include "cclock.hpp"
    #include "c4001.hpp"
    #include "c4008.hpp"
    #include "c4011.hpp"
    #include "c4013.hpp"
    #include "c4030.hpp"
    #include "c4071.hpp"
    #include "c4081.hpp"
    #include "c4069.hpp"
    #include "c4040.hpp"
    #include "c4094.hpp"
    #include "c4017.hpp"
    #include "c4514.hpp"

    class Factory
    {
        public:
        Factory();
        ~Factory();

        typedef std::unique_ptr<nts::IComponent> (Factory::*creatorPt)(const std::string &) const;
        std::unique_ptr <nts::IComponent> createComponent(const std::string &type, const std::string &value);

        private:
        std::unique_ptr<nts::IComponent> create4001(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4008(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4011(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4013(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4017(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4030(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4040(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4069(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4071(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4081(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4094(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4514(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create4801(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> create2716(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> createinput(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> createclock(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> createtrue(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> createfalse(const std::string &value) const noexcept;
        std::unique_ptr<nts::IComponent> createoutput(const std::string &value) const noexcept;

        std::unordered_map<std::string, creatorPt> _compCreatorPt;
    };
#endif /*FACTORY_HPP*/