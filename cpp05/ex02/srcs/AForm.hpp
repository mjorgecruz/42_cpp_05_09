/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 22:52:50 by marvin            #+#    #+#             */
/*   Updated: 2024/09/28 22:52:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef AForm_HPP
# define AForm_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private :
        std::string const name;
        bool isSigned;
        int const reqGrade;
        int const execGrade;
        std::string target;
    
    public:
        AForm ( void );
        virtual ~AForm( void );
        AForm (AForm &src);
        AForm ( std::string name, int reqGrade, int execGrade, std::string target);
        AForm &operator= (AForm &src);
        void beSigned(Bureaucrat &bureaucrat);
        virtual void beExecuted(Bureaucrat const &bureaucrat ) const = 0;

        std::string getName( void ) const;
        bool getIsSigned( void ) const;
        int getReqGrade( void ) const; 
        int getExecGrade( void ) const;
        std::string getTarget( void ) const;

        void execute(Bureaucrat const & executor) const;

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
        class UnnamedAFormException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class AlreadySignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class FormUnsignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class IssueException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };



};

std::ostream &operator<< (std::ostream& os, AForm &src);

#endif