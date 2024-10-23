

#include "ATarget.hpp"

ATarget::ATarget(): type("notype")
{}

ATarget::ATarget( ATarget const & src)
{
    if (&src == this)
        return;
    type = src.getType();
}
ATarget & ATarget::operator= (ATarget const &src)
{
    if (&src == this)
        return *this;
    type = src.getType();
    return *this;
}

ATarget::~ATarget()
{}

ATarget::ATarget(std::string type )
{
    this->type = type;
}

std::string ATarget::getType( void ) const
{
    return type;
}


void ATarget::getHitBySpell(ASpell const &spell) const
{
    std::cout << this->getType() << " has been " << spell.getEffects() << "!" << std::endl;
}