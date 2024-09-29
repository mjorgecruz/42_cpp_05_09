/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 22:52:57 by marvin            #+#    #+#             */
/*   Updated: 2024/09/28 22:52:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form ( void ): name("NoName"), reqGrade(0), execGrade(0)
{
    throw Form::UnnamedFormException();
}

Form::~Form( void )
{
    std::cout << "Form " << this->name << " got destroyed." << std::endl;
}

Form::Form (Form &src): name(src.name), isSigned(src.isSigned), reqGrade(src.reqGrade), execGrade(src.execGrade)
{}

Form::Form ( std::string name, int reqGrade, int execGrade ): name(name), reqGrade(reqGrade), execGrade(execGrade)
{
    if (reqGrade < 1 || execGrade < 1)
        throw Form::GradeTooHighException();
    else if (reqGrade > 150 || execGrade > 150)
        throw Form::GradeTooLowException();
    else
    {
        this->isSigned = false;
        std::cout << "Form " << this->name << " got created." << std::endl;
    }
}

Form & Form::operator= (Form &src)
{
    if (this == &src)
        return (*this);
    isSigned = src.isSigned;
    return (*this);
}

void Form::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->getReqGrade())
        throw Form::GradeTooLowException();
    else if (this->isSigned == true)
        throw Form::AlreadySignedException();
    else
        this->isSigned = true;
}

std::string Form::getName( void ) const
{
    return(this->name);
}

bool Form::getIsSigned( void ) const
{
    return (this->isSigned);
}

int Form::getReqGrade( void ) const
{
    return (this->reqGrade);
}

int Form::getExecGrade( void ) const
{
    return (this->execGrade);
}

std::ostream &operator<< (std::ostream& os, Form src)
{
    os << "Form " << src.getName() << ", signature: " << src.getIsSigned()<<", required grade: " << src.getReqGrade() << ", execution grade: " << src.getExecGrade() << std::endl;
    return (os);
}

const char*  Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high.");
}

const char*  Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low.");
}

const char*  Form::UnnamedFormException::what() const throw()
{
    return ("No name defined for form.");
}

const char*  Form::AlreadySignedException::what() const throw()
{
    return ("Form is already signed.");
}