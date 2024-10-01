/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 03:18:43 by marvin            #+#    #+#             */
/*   Updated: 2024/10/01 14:12:43 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

class Intern 
{
    private:
        AForm *CreatePresidentialPardonForm(std::string target);
        AForm *CreateRobotomyRequestForm(std::string target);
        AForm *CreateShrubberyCreationForm(std::string target);
    
    public:
        Intern();
        ~Intern();
        Intern(Intern &src);
        Intern &operator= (Intern &src);

        AForm *makeForm(std::string formName, std::string target);
        
        class InvalidFormNameException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

typedef AForm *(Intern::*function)(std::string target);
#endif