#ifndef ATARGET_HPP
# define ATARGET_HPP

#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
    private:
        std::string type;

    public:
        ATarget();
        ATarget( ATarget const & src);
        ATarget &operator= (ATarget const &src);
        virtual ~ATarget();

        ATarget(std::string type );

        std::string getType( void ) const;

        virtual ATarget *clone( void ) const = 0;

        void getHitBySpell(ASpell const &spell) const;
};


#endif