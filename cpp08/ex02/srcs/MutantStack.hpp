/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:57:07 by masoares          #+#    #+#             */
/*   Updated: 2024/10/04 16:56:38 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <vector>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <ctime>
#include <iostream>

template <typename T> 
class MutantStack:
{
    private:
        std::vector <int> _arr;
        unsigned int _size;
        
        MutantStack();
        MutantStack(MutantStack &src);
        MutantStack &operator= (MutantStack &src);
        
    public:
        ~MutantStack();
        static iterator

        
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