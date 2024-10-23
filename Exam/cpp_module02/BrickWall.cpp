#include "BrickWall.hpp"

BrickWall::BrickWall(): ATarget("Inconspicuous Red-brick Wall")
{}

BrickWall::BrickWall( BrickWall const & src) : ATarget("Inconspicuous Red-brick Wall")
{
    if( this != &src)
        *this = src;
}

BrickWall & BrickWall::operator= (BrickWall const &src)
{
    if( this != &src)
        *this = src;
    return *this;
}

BrickWall::~BrickWall()
{}

BrickWall * BrickWall::clone( void ) const
{
    BrickWall *dolly = new BrickWall();
    return dolly;
}