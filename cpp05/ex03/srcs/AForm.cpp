/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 22:52:57 by marvin            #+#    #+#             */
/*   Updated: 2024/09/28 22:52:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm ( void ): name("NoName"), reqGrade(0), execGrade(0)
{
    throw AForm::UnnamedAFormException();
}

AForm::~AForm( void )
{
    std::cout << "AForm " << this->name << " got destroyed." << std::endl;
}

AForm::AForm (AForm &src): name(src.name), isSigned(src.isSigned), reqGrade(src.reqGrade), execGrade(src.execGrade)
{}

AForm::AForm ( std::string name, int reqGrade, int execGrade ): name(name), reqGrade(reqGrade), execGrade(execGrade)
{
    if (reqGrade < 1 || execGrade < 1)
        throw AForm::GradeTooHighException();
    else if (reqGrade > 150 || execGrade > 150)
        throw AForm::GradeTooLowException();
    else
    {
        this->isSigned = false;
        std::cout << "AForm " << this->name << " got created." << std::endl;
    }
}

AForm & AForm::operator= (AForm &src)
{
    if (this == &src)
        return (*this);
    isSigned = src.isSigned;
    return (*this);
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() > this->getReqGrade())
        throw AForm::GradeTooLowException();
    else if (this->isSigned == true)
        throw AForm::AlreadySignedException();
    else
        this->isSigned = true;
}

void AForm::beExecuted(Bureaucrat const &bureaucrat) const
{
    if (bureaucrat.getGrade() > this->getExecGrade())
        throw AForm::GradeTooLowException();
    else if (this->isSigned == false)
        throw AForm::FormUnsignedException();
}

std::string AForm::getName( void ) const
{
    return(this->name);
}

bool AForm::getIsSigned( void ) const
{
    return (this->isSigned);
}

int AForm::getReqGrade( void ) const
{
    return (this->reqGrade);
}

int AForm::getExecGrade( void ) const
{
    return (this->execGrade);
}

std::ostream &operator<< (std::ostream& os, const AForm &src)
{
    os << "AForm " << src.getName() << ", signature: " << src.getIsSigned()<<", required grade: " << src.getReqGrade() << ", execution grade: " << src.getExecGrade() << std::endl;
    return (os);
}

const char*  AForm::GradeTooHighException::what() const throw()
{
    return ("Grade is too high.");
}

const char*  AForm::GradeTooLowException::what() const throw()
{
    return ("Grade is too low.");
}

const char*  AForm::UnnamedAFormException::what() const throw()
{
    return ("No name defined for AForm.");
}

const char*  AForm::AlreadySignedException::what() const throw()
{
    return ("AForm is already signed.");
}

const char*  AForm::FormUnsignedException::what() const throw()
{
    return ("AForm is not signed.");
}

const char*  AForm::IssueException::what() const throw()
{
    return ("");
}