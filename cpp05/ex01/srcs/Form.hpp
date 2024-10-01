/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 22:52:50 by marvin            #+#    #+#             */
/*   Updated: 2024/10/01 14:45:03 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private :
        std::string const name;
        bool isSigned;
        int const reqGrade;
        int const execGrade;
    
    public:
        Form ( void );
        ~Form( void );
        Form (Form &src);
        Form ( std::string name, int reqGrade, int execGrade );
        Form &operator= (Form &src);
        void beSigned(Bureaucrat &bureaucrat);

        std::string getName( void ) const;
        bool getIsSigned( void ) const;
        int getReqGrade( void ) const; 
        int getExecGrade( void ) const;

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
        class UnnamedFormException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
        class AlreadySignedException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };


};

std::ostream &operator<< (std::ostream& os, Form &src);

#endif