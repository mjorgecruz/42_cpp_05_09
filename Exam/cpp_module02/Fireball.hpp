#ifndef FIREBALL_HPP
# define FIREBALL_HPP

#include "ASpell.hpp"

class Fireball: public ASpell
{
    private:

    public:
        Fireball();
        Fireball( Fireball const & src);
        Fireball &operator= (Fireball const &src);
        ~Fireball();
        
        Fireball *clone( void ) const;
};

#endif