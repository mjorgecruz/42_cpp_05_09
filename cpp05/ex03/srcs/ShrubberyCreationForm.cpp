/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 02:30:26 by marvin            #+#    #+#             */
/*   Updated: 2024/09/29 02:30:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <cstdlib>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm()
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src): AForm(src), target(src.target)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator= (ShrubberyCreationForm &src)
{
    if (this == &src)
        return (*this);
    target = src.target;
    return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    std::cout << "ShrubberyCreationForm " << this->getName() << " got created." << std::endl;  
}


void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
    try {
        beExecuted(executor);
        std::ofstream outfile((target + "_shrubbery").c_str());
        if (!outfile.is_open())
            throw AForm::IssueException();
        std::string directory = ".";
        std::string command = "tree " + directory + " > " + target + "_shrubbery";
        system(command.c_str());
    }
    catch (AForm::GradeTooHighException &e){
		std::cout << e.what() << std::endl;
        throw AForm::IssueException();
	}
	catch (AForm::GradeTooLowException &e){
		std::cout << e.what() << std::endl;
        throw AForm::IssueException();
	}
    catch (AForm::FormUnsignedException &e){
		std::cout << e.what() << std::endl;
        throw AForm::IssueException();
	}
}

