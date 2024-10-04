/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:57:07 by masoares          #+#    #+#             */
/*   Updated: 2024/10/04 16:48:53 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <ctime>
#include <iostream>

class Span
{
    private:
        std::vector <int> _arr;
        unsigned int _size;
        
        Span();
        Span(Span &src);
        Span &operator= (Span &src);
        
    public:
        ~Span();
        Span(unsigned int N);
        unsigned int size();
        void addNumber(int number);
        int shortestSpan( void );
        int longestSpan( void );
        unsigned int vectorSize( void );

        int& operator [](unsigned int i);
        void addRange(std::vector<int> arr);
        
        
        class TooManyElementsException : public std::exception
        {
            public:
                const char * what() const throw();
        };
        
        class NotEnoughNumbersException : public std::exception
        {
            public:
                const char * what() const throw();
        };
};

#endif