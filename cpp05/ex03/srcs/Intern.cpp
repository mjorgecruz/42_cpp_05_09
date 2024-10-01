/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 03:22:22 by marvin            #+#    #+#             */
/*   Updated: 2024/10/01 14:13:26 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/


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
    function all[] = {
		&Intern::CreateShrubberyCreationForm,
		&Intern::CreateRobotomyRequestForm,
		&Intern::CreatePresidentialPardonForm
    };

    std::string comparer[] = {
        "ShrubberyCreationForm",
        "RobotomyRequestForm",
        "PresidentialPardonForm"
    };

    for (unsigned long i = 0; i < comparer->length(); i++)
    {
        if (comparer[i] == formName)
        {
            return ((this->*all[i])(target));
        }
    }
    throw Intern::InvalidFormNameException();
}

const char *Intern::InvalidFormNameException::what() const throw()
{
    return("Invalid name for Form");
}

AForm *Intern::CreateShrubberyCreationForm(std::string target){
	return (new ShrubberyCreationForm(target));
}
AForm *Intern::CreateRobotomyRequestForm(std::string target){
	return (new RobotomyRequestForm(target));
}
AForm *Intern::CreatePresidentialPardonForm(std::string target){
	return (new PresidentialPardonForm(target));
}
