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
        Bureaucrat ( void );

    public:
        ~Bureaucrat( void );
        Bureaucrat (Bureaucrat &src);
        Bureaucrat ( std::string name, int grade );
        Bureaucrat &operator= (Bureaucrat &src);
        
        std::string getName( void ) const;
        int getGrade( void );
        void increment( void );
        void decrement( void );

        class GradeTooHighException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream &operator<< (std::ostream& os, Bureaucrat &src);

#endif