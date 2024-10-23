

#ifndef ASPELL_HPP
# define ASPELL_HPP

#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
    private:
        std::string name;
        std::string effects;
    public:
        ASpell();
        ASpell( ASpell const & src);
        ASpell &operator= (ASpell const &src);
        virtual ~ASpell();

        ASpell(std::string name, std::string effects);

        std::string getName( void ) const;
        std::string getEffects( void ) const;

        virtual ASpell *clone( void ) const = 0;

        void launch( ATarget const & target);
};


#endif
