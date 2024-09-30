/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 00:52:35 by marvin            #+#    #+#             */
/*   Updated: 2024/09/29 00:52:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm()
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src): AForm(src), target(src.target)
{}

PresidentialPardonForm &PresidentialPardonForm::operator= (PresidentialPardonForm &src)
{
    if (this == &src)
        return (*this);
    target = src.target;
    return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5), target(target)
{
    std::cout << "PresidentialPardonForm " << this->getName() << " got created." << std::endl;  
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
    try {
        beExecuted(executor);
        std::cout << this->target << "has been pardoned by Zaphod Beeblebrox." << std::endl;
    }
    catch (AForm::GradeTooHighException &e){
		std::cerr << e.what() << std::endl;
        throw AForm::IssueException();
	}
	catch (AForm::GradeTooLowException &e){
		std::cerr << e.what() << std::endl;
        throw AForm::IssueException();
	}
    catch (AForm::FormUnsignedException &e){
		std::cerr << e.what() << std::endl;
        throw AForm::IssueException();
	}
}