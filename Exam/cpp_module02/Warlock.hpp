

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>
#include "ASpell.hpp"
#include "ATarget.hpp"
#include "SpellBook.hpp"
#include <map>

class Warlock
{
    private:
        std::string name;
        std::string title;
        SpellBook spells;
        
        Warlock();
        Warlock( Warlock const & src);
        Warlock &operator= (Warlock const &src);
    
    public:
        ~Warlock();

        Warlock(std::string name, std::string title);

        std::string getName(void) const;
        std::string getTitle (void) const;

        void setTitle( std::string const &title);

        void introduce() const;

        void learnSpell(ASpell *spell);
        void forgetSpell(std::string spell);
        void launchSpell(std::string spell, ATarget &target);

};

#endif
