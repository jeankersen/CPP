#include "Warlock.hpp"

Warlock::Warlock(std::string str1, std::string str2): name(str1), title(str2)
{
   // std::cout << "Constructor default" << std::endl;
    std::cout <<  getName() << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(void)
{

   // std::cout << "Desctructor called" << std::endl;
    std::cout << getName() << ": My job is done!" << std::endl;
}

std::string const & Warlock::getName(void) const
{
    return (this->name);
}

std::string const & Warlock::getTitle(void) const
{
    return (this->title);
}

void Warlock::setTitle(std::string const & str)
{
    this->title = str;
}

void Warlock::introduce(void) const 
{
    std::cout << getName() << ": I am " << getName() << ", " << getTitle() << std::endl;
}

Warlock & Warlock::operator=(Warlock const & rhs)
{
    this->name = rhs.name;
    this->title = rhs.title;
    return *this;
}

Warlock::Warlock (Warlock const &obj)
{
    *this = obj;
}

Warlock::Warlock()
{
    
}