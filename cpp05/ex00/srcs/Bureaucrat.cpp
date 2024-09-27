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

        
Bureaucrat::Bureaucrat ( void )
{
    
}

Bureaucrat::~Bureaucrat( void )
{
    
}

Bureaucrat::Bureaucrat (Bureaucrat &src)
{

}

Bureaucrat & Bureaucrat::operator= (Bureaucrat &src)
{
    
}

std::string Bureaucrat::getName(Bureaucrat ) const
{

}

std::string Bureaucrat::getGrade( void ) const
{
    
}

int Bureaucrat::increment(std::string Name, int value)
{

}

int Bureaucrat::decrement(std::string Name, int value)
{
    
}

std::ostream& Bureaucrat::operator <<(std::ostream& os, Bureaucrat name)
{
    os << getName(name)<< ", bureaucrat grade" << getName().
}
