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

Bureaucrat::Bureaucrat ( std::string name, int grade ): name(name), grade(grade)
{}

std::string Bureaucrat::getName() const
{
    return(this->name);
}

int Bureaucrat::getGrade( void )
{
    return(this->grade);
}

int Bureaucrat::increment(Bureaucrat &src)
{
    int grade;
    grade = this->getGrade();
    try
    {
        if (grade == 1)
            throw Bureaucrat::GradeTooHighException();
        else
            grade--;
    }catch (Bureaucrat::GradeTooHighException &e){
        std::cout << e.what() << std::endl;
    }
}

int Bureaucrat::decrement(Bureaucrat &src)
{
    int grade;
    grade = this->getGrade();
    try
    {
        if (grade == 150)
            throw Bureaucrat::GradeTooLowException();
        else
            grade++;
    }catch (Bureaucrat::GradeTooLowException &e){
        std::cout << e.what() << std::endl;
    }
}

std::ostream& Bureaucrat::operator<<(std::ostream& os, Bureaucrat src)
{
    os << src.getName()<< ", bureaucrat grade" << src.getGrade().
}
