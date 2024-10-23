#include "Dummy.hpp"

Dummy::Dummy(): ATarget("Target Practice Dummy")
{}

Dummy::Dummy( Dummy const & src) : ATarget("Target Practice Dummy")
{
    if( this != &src)
        *this = src;
}

Dummy & Dummy::operator= (Dummy const &src)
{
    if( this != &src)
        *this = src;
    return *this;
}

Dummy::~Dummy()
{}

Dummy * Dummy::clone( void ) const
{
    Dummy *dolly = new Dummy();
    return dolly;
}