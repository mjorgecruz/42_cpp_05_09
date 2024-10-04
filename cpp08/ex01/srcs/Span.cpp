/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:41:55 by masoares          #+#    #+#             */
/*   Updated: 2024/10/04 16:16:06 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Span.hpp"

Span::Span(){}
Span::~Span(){};
Span::Span(Span &src)
{
    _size = src.size();
    _arr =  src._arr;
}
Span & Span::operator= (Span &src)
{
    _size = src.size();
    _arr =  src._arr;
    return (*this);
}

unsigned int Span::size()
{
    return(_size);
}
unsigned int Span::vectorSize()
{
    return(_arr.size());
}

Span::Span(unsigned int N)
{
    _size = N;
}
void Span::addNumber(int number)
{
    if (_arr.size() == 0)
    {
        _arr.push_back(number);
        return;
    }
    std::vector<int>::iterator end = _arr.end();
    std::vector<int>::iterator it = _arr.begin();
    if (_arr.size() < _size)
    {       
        while (it != end)
        {
            if (*it > number)
            {
                _arr.insert(it, number);
                return;
            }
            it++;
        }
    }
    else
        throw Span::TooManyElementsException();
}
int Span::shortestSpan( void )
{
    long shortest = INT_MAX;
    int last = INT_MIN;
    
    if (_arr.size() < 2)
        throw Span::NotEnoughNumbersException();
    std::vector<int>::iterator it = _arr.begin();
    while (it != _arr.end())
    {
        if (shortest >= abs(*it - last))
            shortest = abs(*it - last);
        last = *it;
        it++;
    }
    return (shortest);
    
}
int Span::longestSpan( void )
{
    int longest;
    if (_arr.size() < 2)
        throw Span::NotEnoughNumbersException();
    longest = abs(*(_arr.end()) - *(_arr.begin()));
    return longest;
}

const char * Span::TooManyElementsException::what() const throw()
{
    return("No space left on array");
};

const char * Span::NotEnoughNumbersException::what() const throw()
{
    return("Not enough numbers stored, no span can be found");
};

int& Span::operator [](unsigned int i)
{
    if (i < 0 || i >= (this->vectorSize()))
         throw std::out_of_range("Index out of range");
    return this->_arr[i];
}