/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 03:12:11 by marvin            #+#    #+#             */
/*   Updated: 2024/09/29 03:12:11 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm()
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src): AForm(src), target(src.target)
{}

RobotomyRequestForm &RobotomyRequestForm::operator= (RobotomyRequestForm &src)
{
    if (this == &src)
        return (*this);
    target = src.target;
    return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 25, 5), target(target)
{
    std::cout << "RobotomyRequestForm " << this->getName() << " got created." << std::endl;  
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
    try {
        beExecuted(executor);
        if (rand() %2)
            std::cout << this->target << " has been robotomized successfully." << std::endl;
        else
            std::cout << this->target << " 's robotomy failed." << std::endl;
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