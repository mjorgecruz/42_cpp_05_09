/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 00:52:35 by marvin            #+#    #+#             */
/*   Updated: 2024/10/01 11:19:51 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm()
{}

PresidentialPardonForm::~PresidentialPardonForm()
{}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src): AForm(src)
{}

PresidentialPardonForm &PresidentialPardonForm::operator= (PresidentialPardonForm &src)
{
    if (this == &src)
        return (*this);
    *this = src;
    return (*this);
}

PresidentialPardonForm::PresidentialPardonForm(std::string target): AForm("PresidentialPardonForm", 25, 5, target)
{
    std::cout << "PresidentialPardonForm " << this->getName() << " got created." << std::endl;  
}

void PresidentialPardonForm::beExecuted(Bureaucrat const & executor) const
{
    (void) executor;
    std::cout << this->getTarget() << "has been pardoned by Zaphod Beeblebrox." << std::endl;
}