/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 03:18:43 by marvin            #+#    #+#             */
/*   Updated: 2024/09/29 03:18:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

class Intern 
{
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

#endif