/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:57:07 by masoares          #+#    #+#             */
/*   Updated: 2024/10/04 12:12:01 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <vector>

class Span
{
    private:
        std::vector <int> _arr;
        int _size;
        
        Span();
        ~Span();
        Span(Span &src);
        Span &operator= (Span &src);
        
    public:
        Span(int N);
        int size();
        void addNumber(int number);
        int shortestSpan( void );
        int longestSpan( void );

        Span& operator [](int i);
        
        
        class TooManyElementsException : std::exception
        {
            const char * what() const throw();
        };
        
        class NotEnoughNumbersException : std::exception
        {
            const char * what() const throw();
        };
};

#endif