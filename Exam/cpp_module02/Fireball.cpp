

#include "Fireball.hpp"

Fireball::Fireball(): ASpell("Fireball", "burnt to a crisp")
{}

Fireball::Fireball( Fireball const & src):  ASpell("Fireball", "burnt to a crisp")
{
    if( this != &src)
        *this = src;
}

Fireball & Fireball::operator= (Fireball const &src)
{
    if( this != &src)
        *this = src;
    return *this;
}

Fireball::~Fireball()
{}

Fireball * Fireball::clone( void ) const
{
    Fireball *dolly = new Fireball();
    return dolly;
}