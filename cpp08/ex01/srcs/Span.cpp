/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:41:55 by masoares          #+#    #+#             */
/*   Updated: 2024/10/09 11:06:16 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Span.hpp"

Span::Span(){}
Span::~Span(){};
Span::Span(const Span &src)
{
    _size = src.size();
    _arr =  src._arr;
}
Span & Span::operator= (const Span &src)
{
    if(this == &src)
        return *this;
    _size = src.size();
    _arr =  src._arr;
    return (*this);
}

unsigned int Span::size() const
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
    if (_arr.size() < _size)
    {       
        _arr.push_back(number);
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
    std::sort(_arr.begin(), _arr.end());
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
    std::sort(_arr.begin(), _arr.end());
    longest = abs(*(_arr.end() - 1) - *(_arr.begin()));
    return longest;
}

void Span::addRange(std::vector<int> arr)
{
    if (this->vectorSize() + arr.size() > this->size())
        throw(Span::TooManyElementsException());
    _arr.insert(_arr.end(), arr.begin(), arr.end());
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