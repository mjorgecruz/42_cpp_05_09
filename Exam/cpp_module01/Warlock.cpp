

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

void Warlock::learnSpell(ASpell *spell)
{
    if (this->spells.find(spell->getName()) == this->spells.end())
    {
        spells[spell->getName()] = spell;
    }
}

void Warlock::forgetSpell(std::string spell)
{
    if(this->spells.find(spell) != this->spells.end())
    {
        this->spells.erase(this->spells.find(spell));
    }
}

void Warlock::launchSpell(std::string spell, ATarget &target)
{
    if(this->spells.find(spell) != this->spells.end())
    {
        ((this->spells.find(spell))->second)->launch(target);
    }
}