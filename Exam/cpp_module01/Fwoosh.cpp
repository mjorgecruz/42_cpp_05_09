

#include "Fwoosh.hpp"

Fwoosh::Fwoosh(): ASpell("Fwoosh", "fwooshed")
{}

Fwoosh::Fwoosh( Fwoosh const & src):  ASpell("Fwoosh", "fwooshed")
{
    if( this != &src)
        *this = src;
}

Fwoosh & Fwoosh::operator= (Fwoosh const &src)
{
    if( this != &src)
        *this = src;
    return *this;
}

Fwoosh::~Fwoosh()
{}

Fwoosh * Fwoosh::clone( void ) const
{
    Fwoosh *dolly = new Fwoosh();
    return dolly;
}