

#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <iostream>


class Warlock
{
    private:
        std::string name;
        std::string title;
        
        Warlock();
        Warlock( Warlock const & src);
        Warlock &operator= (Warlock const &src);
    
    public:
        ~Warlock();

        Warlock(std::string name, std::string title);

        std::string getName(void) const;
        std::string getTitle (void) const;

        void setTitle( std::string const &title);

        void introduce() const;

};


#endif
