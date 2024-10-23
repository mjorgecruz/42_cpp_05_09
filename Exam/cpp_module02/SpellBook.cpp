
#include "SpellBook.hpp"


SpellBook::SpellBook( SpellBook const & src)
{
    (void) src;
}

SpellBook &SpellBook::operator= (SpellBook const &src)
{
    (void) src;
    return *this;
}

SpellBook::SpellBook()
{

}

SpellBook::~SpellBook()
{

}

void SpellBook::learnSpell(ASpell* spell)
{
    if (spells.find(spell->getName()) == spells.end())
    {
        ASpell *temp = spell->clone();
        spells[spell->getName()] = temp;
    }
}

void SpellBook::forgetSpell(std::string const & spell)
{
    std::map<std::string, ASpell *>::iterator it = spells.find(spell);
    ASpell * temp = it->second;
    if (spells.find(spell) != spells.end())
    {
        delete temp;
        spells.erase(spells.find(spell));
    }

}

ASpell* SpellBook::createSpell(std::string const & spell)
{
    if (spells.find(spell) != spells.end())
    {
        return (spells.find(spell)->second);
    }
    else
        return NULL;
}