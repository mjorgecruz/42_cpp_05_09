/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 00:34:27 by marvin            #+#    #+#             */
/*   Updated: 2024/10/01 11:10:03 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef ShrubberyCreationForm_HPP
# define ShrubberyCreationForm_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		ShrubberyCreationForm();
	public:
		~ShrubberyCreationForm();
		ShrubberyCreationForm(ShrubberyCreationForm &src);
		ShrubberyCreationForm &operator= (ShrubberyCreationForm &src);
		ShrubberyCreationForm(std::string target);
		virtual void beExecuted(Bureaucrat const & executor) const;
};

#endif

