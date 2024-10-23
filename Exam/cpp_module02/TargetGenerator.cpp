
#include "TargetGenerator.hpp"


TargetGenerator::TargetGenerator( TargetGenerator const & src)
{
    (void) src;
}

TargetGenerator &TargetGenerator::operator= (TargetGenerator const &src)
{
    (void) src;
    return *this;
}

TargetGenerator::TargetGenerator()
{

}

TargetGenerator::~TargetGenerator()
{

}

void TargetGenerator::learnTargetType(ATarget* target)
{
    if (targets.find(target->getType()) == targets.end())
    {
        ATarget *temp = target->clone();
        targets[target->getType()] = temp;
    }
}

void TargetGenerator::forgetTargetType(std::string const & target)
{
    std::map<std::string, ATarget *>::iterator it = targets.find(target);
    ATarget * temp = it->second;
    if (targets.find(target) != targets.end())
    {
        delete temp;
        targets.erase(targets.find(target));
    }

}

ATarget* TargetGenerator::createTarget(std::string const & target)
{
    if (targets.find(target) != targets.end())
    {
        return (targets.find(target)->second);
    }
    else
        return NULL;
}