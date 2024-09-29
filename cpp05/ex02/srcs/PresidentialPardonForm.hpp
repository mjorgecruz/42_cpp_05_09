/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 00:38:31 by marvin            #+#    #+#             */
/*   Updated: 2024/09/29 00:38:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PresidentialPardonForm_HPP
# define PresidentialPardonForm_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		std::string target;
    public:
        PresidentialPardonForm();
        ~PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm &src);
        PresidentialPardonForm &operator= (PresidentialPardonForm &src);
        PresidentialPardonForm(std::string target);

		virtual void execute(Bureaucrat const & executor) const;
};

#endif