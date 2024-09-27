#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{
    private:
        std::string const name;
        int grade;

    public:
        Bureaucrat ( void );
        ~Bureaucrat( void );
        Bureaucrat (Bureaucrat &src);
        Bureaucrat &operator= (Bureaucrat &src);
        
        std::string getName() const;
        std::string getGrade( void ) const;
        int increment(std::string Name, int value);
        int decrement(std::string Name, int value);
};

#endif