#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP

#include "ASpell.hpp"

class Polymorph: public ASpell
{
    private:

    public:
        Polymorph();
        Polymorph( Polymorph const & src);
        Polymorph &operator= (Polymorph const &src);
        ~Polymorph();
        
        Polymorph *clone( void ) const;
};

#endif