/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 11:31:34 by masoares          #+#    #+#             */
/*   Updated: 2024/09/27 12:03:40 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Bureaucrat.hpp"

		
Bureaucrat::Bureaucrat ( void ): name("NoName")
{
	this->grade = 150;
	std::cout << "Bureaucrat " << this->name << " got killed." << std::endl;
}

Bureaucrat::~Bureaucrat( void )
{
	std::cout << "Bureaucrat " << this->name << " got killed." << std::endl;
}

Bureaucrat::Bureaucrat (Bureaucrat &src): name(src.name), grade(src.grade)
{}

Bureaucrat &Bureaucrat::operator= (Bureaucrat &src)
{
	if (this == &src)
		return (*this);
	grade = src.grade;
	return (*this);
}

Bureaucrat::Bureaucrat ( std::string name, int grade ): name(name)
{
		if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
		else
		{
			this->grade = grade;
			std::cout << "Bureaucrat " << this->name << " got created." << std::endl;
		}
}

std::string Bureaucrat::getName() const
{
	return(this->name);
}

int Bureaucrat::getGrade( void )
{
	return(this->grade);
}

void Bureaucrat::increment()
{
	int grade;
	grade = this->getGrade();
	if (grade == 1)
		throw Bureaucrat::GradeTooHighException();
	else
		grade--;
}

void Bureaucrat::decrement()
{
	int grade;
	grade = this->getGrade();
	if (grade == 150)
		throw Bureaucrat::GradeTooLowException();
	else
		grade++;
}

std::ostream&  operator<<(std::ostream& os, Bureaucrat src)
{
	os << src.getName()<< ", bureaucrat grade " << src.getGrade() << std::endl;
	return (os);
}

void Bureaucrat::signForm( Form &form )
{
	try{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(Form::GradeTooLowException &e){
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because ";
		std::cout << e.what() << std::endl;
	}
	catch(Form::AlreadySignedException &e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because ";
		std::cout << e.what() << std::endl;
	}
}

const char*  Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high.");
}

const char*  Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low.");
}