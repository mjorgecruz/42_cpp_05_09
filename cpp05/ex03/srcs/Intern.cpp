/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 03:22:22 by marvin            #+#    #+#             */
/*   Updated: 2024/09/29 03:22:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Intern.hpp"

Intern::Intern()
{}

Intern::~Intern()
{}

Intern::Intern(Intern &src)
{
    *this = src;
}

Intern &Intern::operator= (Intern &src)
{
    (void)src;
    return (*this);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
    if (formName == "ShrubberyCreationForm")
        return (new ShrubberyCreationForm(target));
    else if (formName == "RobotomyRequestForm")
        return (new RobotomyRequestForm(target));
    else if (formName == "PresidentialPardonForm")
        return (new PresidentialPardonForm(target));
    else
        throw Intern::InvalidFormNameException();
}

const char *Intern::InvalidFormNameException::what() const throw()
{
    return("Invalid name for Form");
}