/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:41:55 by masoares          #+#    #+#             */
/*   Updated: 2024/10/04 16:54:04 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "MutantStack.hpp"

MutantStack::MutantStack(){}
MutantStack::~MutantStack(){};
MutantStack::MutantStack(Span &src)
{
    _size = src.size();
    _arr =  src._arr;
}
MutantStack & MutantStack::operator= (MutantStack &src)
{
    _size = src.size();
    _arr =  src._arr;
    return (*this);
}

const char * MutantStack::TooManyElementsException::what() const throw()
{
    return("No space left on array");
};

const char * MutantStack::NotEnoughNumbersException::what() const throw()
{
    return("Not enough numbers stored, no span can be found");
};
