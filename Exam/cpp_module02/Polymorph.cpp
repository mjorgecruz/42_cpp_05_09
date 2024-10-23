

#include "Polymorph.hpp"

Polymorph::Polymorph(): ASpell("Polymorph", "turned into a critter")
{}

Polymorph::Polymorph( Polymorph const & src):  ASpell("Polymorph", "turned into a critter")
{
    if( this != &src)
        *this = src;
}

Polymorph & Polymorph::operator= (Polymorph const &src)
{
    if( this != &src)
        *this = src;
    return *this;
}

Polymorph::~Polymorph()
{}

Polymorph * Polymorph::clone( void ) const
{
    Polymorph *dolly = new Polymorph();
    return dolly;
}