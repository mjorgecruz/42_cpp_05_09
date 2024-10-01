/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 02:30:26 by marvin            #+#    #+#             */
/*   Updated: 2024/10/01 15:16:24 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ShrubberyCreationForm.hpp"
#include <cstdlib>

ShrubberyCreationForm::ShrubberyCreationForm(): AForm()
{}

ShrubberyCreationForm::~ShrubberyCreationForm()
{  
    std::cout << "ShrubberyCreationForm " << this->getName() << " got destroyed." << std::endl; 
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src): AForm(src)
{}

ShrubberyCreationForm &ShrubberyCreationForm::operator= (ShrubberyCreationForm &src)
{
    if (this == &src)
        return (*this);
    *this = src;
    return (*this);
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("ShrubberyCreationForm", 145, 137, target)
{
    std::cout << "ShrubberyCreationForm " << this->getName() << " got created." << std::endl;  
}


void ShrubberyCreationForm::beExecuted(Bureaucrat const & executor) const
{
    (void) executor;
    std::ofstream outfile((getTarget() + "_shrubbery").c_str());
    if (!outfile.is_open())
        throw std::exception();
    for (int i = 0; i < 3 ; i++)
    {
        outfile << 
        	"         v" << std::endl <<
			"        >X<" << std::endl <<
			"        AAA" << std::endl <<
			"        d$b" << std::endl <<
			"      .d\\$$b." << std::endl <<
			"    .d$i$$\\$$b." << std::endl <<
			"        d$b" << std::endl <<
			"        d$b" << std::endl <<
			"        d$b" << std::endl <<
            std::endl;
    }
    outfile.close();
    // std::string directory = ".";
    // std::string command = "tree " + directory + " > " + target + "_shrubbery";
    // system(command.c_str());
}

