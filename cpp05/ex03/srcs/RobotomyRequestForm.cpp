/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 03:12:11 by marvin            #+#    #+#             */
/*   Updated: 2024/10/01 12:23:03 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(): AForm()
{}

RobotomyRequestForm::~RobotomyRequestForm()
{}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src): AForm(src)
{}

RobotomyRequestForm &RobotomyRequestForm::operator= (RobotomyRequestForm &src)
{
    if (this == &src)
        return (*this);
    *this = src;
    return (*this);
}

RobotomyRequestForm::RobotomyRequestForm(std::string target): AForm("RobotomyRequestForm", 72, 45, target)
{
    std::cout << "RobotomyRequestForm " << this->getName() << " got created." << std::endl;  
}

void RobotomyRequestForm::beExecuted(Bureaucrat const & executor) const
{
    srand(time(NULL));
    (void) executor;
    if (rand() %2)
    {
        std::cout << this->getTarget() << " Brrrrrr." << std::endl;
        std::cout << this->getTarget() << " has been robotomized successfully." << std::endl;
    }
    else
        std::cout << this->getTarget() << " 's robotomy failed." << std::endl;
}