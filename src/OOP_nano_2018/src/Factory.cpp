/*
** EPITECH PROJECT, 2018
** cpp_d06_2018
** File description:
** ex01/Factory.cpp
*/

#include "Factory.hpp"

Factory::Factory()
{
    _compCreatorPt["4001"] = &Factory::create4001;
    _compCreatorPt["4008"] = &Factory::create4008;
    _compCreatorPt["4011"] = &Factory::create4011;
    _compCreatorPt["4013"] = &Factory::create4013;
    _compCreatorPt["4017"] = &Factory::create4017;
    _compCreatorPt["4030"] = &Factory::create4030;
    _compCreatorPt["4040"] = &Factory::create4040;
    _compCreatorPt["4069"] = &Factory::create4069;
    _compCreatorPt["4071"] = &Factory::create4071;
    _compCreatorPt["4081"] = &Factory::create4081;
    _compCreatorPt["4094"] = &Factory::create4094;
    _compCreatorPt["4514"] = &Factory::create4514;
    _compCreatorPt["4801"] = &Factory::create4801;
    _compCreatorPt["2716"] = &Factory::create2716;
    _compCreatorPt["input"] = &Factory::createinput;
    _compCreatorPt["clock"] = &Factory::createclock;
    _compCreatorPt["true"] = &Factory::createtrue;
    _compCreatorPt["false"] = &Factory::createfalse;
    _compCreatorPt["output"] = &Factory::createoutput;
}

Factory::~Factory()
{
}

std::unique_ptr <nts::IComponent> Factory::createComponent(const std::string &type, const std::string &value)
{
    creatorPt pt = _compCreatorPt[type];
    return ((*this.*pt)(value));
}

std::unique_ptr<nts::IComponent> Factory::create4001(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p1(new c4001(value));
    return (p1);
}

std::unique_ptr<nts::IComponent> Factory::create4008(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p1(new c4008(value));
    return (p1);
}

std::unique_ptr<nts::IComponent> Factory::create4011(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p1(new c4011(value));
    return (p1);
}

std::unique_ptr<nts::IComponent> Factory::create4013(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p1(new c4013(value));
    return (p1);
}

std::unique_ptr<nts::IComponent> Factory::create4017(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p1(new c4017(value));
    return (p1);
}

std::unique_ptr<nts::IComponent> Factory::create4030(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p1(new c4030(value));
    return (p1);
}

std::unique_ptr<nts::IComponent> Factory::create4040(const std::string &value) const noexcept
{
   std::unique_ptr<nts::IComponent> p1(new c4040(value));
   return (p1);
}

std::unique_ptr<nts::IComponent> Factory::create4069(const std::string &value) const noexcept
{
   std::unique_ptr<nts::IComponent> p1(new c4069(value));
   return (p1);
}

std::unique_ptr<nts::IComponent> Factory::create4071(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p1(new c4071(value));
    return (p1);
}

std::unique_ptr<nts::IComponent> Factory::create4081(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p1(new c4081(value));
    return (p1);
}

std::unique_ptr<nts::IComponent> Factory::create4094(const std::string &value) const noexcept
{
   std::unique_ptr<nts::IComponent> p1(new c4094(value));
   return (p1);
}

std::unique_ptr<nts::IComponent> Factory::create4514(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p1(new c4514(value));
    return (p1);
}

std::unique_ptr<nts::IComponent> Factory::create4801(const std::string &value) const noexcept
{
    (void)value;
//    std::unique_ptr<nts::IComponent> p1(new c4801(value));
//    return (p1);
    return (nullptr);
}

std::unique_ptr<nts::IComponent> Factory::create2716(const std::string &value) const noexcept
{
    (void)value;
//    std::unique_ptr<nts::IComponent> p1(new c2716(value));
//    return (p1);
    return (nullptr);
}

std::unique_ptr<nts::IComponent> Factory::createinput(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p1(new input(value));
    return (p1);
}

std::unique_ptr<nts::IComponent> Factory::createclock(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p1(new cclock(value));
    return (p1);
}

std::unique_ptr<nts::IComponent> Factory::createtrue(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p1(new ctrue(value));
    return (p1);
}

std::unique_ptr<nts::IComponent> Factory::createfalse(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p1(new cfalse(value));
    return (p1);
}

std::unique_ptr<nts::IComponent> Factory::createoutput(const std::string &value) const noexcept
{
    std::unique_ptr<nts::IComponent> p1(new output(value));
    return (p1);
}