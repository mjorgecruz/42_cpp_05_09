#ifndef SPELLBOOK_HPP
# define SPELLBOOK_HPP

#include "ASpell.hpp"
#include "Polymorph.hpp"
#include "Fwoosh.hpp"
#include "Fireball.hpp"
#include <map>

class SpellBook
{
    private:
        std::map<std::string, ASpell *> spells;
        SpellBook( SpellBook const & src);
        SpellBook &operator= (SpellBook const &src);

    public:
        SpellBook();
        ~SpellBook();

        void learnSpell(ASpell*);
        void forgetSpell(std::string const &);
        ASpell* createSpell(std::string const &);
};

#endif