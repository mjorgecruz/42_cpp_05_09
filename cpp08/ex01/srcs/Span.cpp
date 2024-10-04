/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:41:55 by masoares          #+#    #+#             */
/*   Updated: 2024/10/04 12:10:52 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Span.hpp"

Span::Span(){}
Span::~Span(){};
Span::Span(Span &src)
{
    
}
Span & Span::operator= (Span &src)
{
    _size = src.size();
    arr = new T[_size];
    *this = src;
}

Span::Span(int N)
{
}
void addNumber(int number)
{
    
}
int shortestSpan( void )
{
    
}
int longestSpan( void )
{
    
}

const char * Span::TooManyElementsException::what() const throw()
{
    return("No space left on array");
};

const char * Span::NotEnoughNumbersException::what() const throw()
{
    return("Not enough numbers stored, no span can be found");
};

