

#include "Warlock.hpp"

Warlock::Warlock(): name("noname"), title("notitle")
{}

Warlock::Warlock( Warlock const & src)
{
    name = src.getName();
    title = src.getTitle();
}

Warlock & Warlock::operator= (Warlock const &src)
{
    name = src.getName();
    title = src.getTitle();
    return *this;
}

Warlock::~Warlock()
{
    std::cout << name << ": My job here is done!" << std::endl;
}

Warlock::Warlock(std::string name, std::string title):  name(name), title(title)
{
    std::cout << name <<": This looks like another boring day." << std::endl;
}

std::string Warlock::getName(void) const
{
    return name;
}

std::string Warlock::getTitle (void) const
{
    return title;
}

void Warlock::setTitle( std::string const &title)
{
    this->title = title; 
}

void  Warlock::introduce() const
{
    std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}