

#ifndef DUMMY_HPP
#define DUMMY_HPP

#include "ATarget.hpp"

class Dummy: public ATarget
{
    public:
        Dummy();
        Dummy( Dummy const & src);
        Dummy &operator= (Dummy const &src);
        ~Dummy();
        
        Dummy *clone( void ) const;


};

#endif