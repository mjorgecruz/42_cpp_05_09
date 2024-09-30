/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:57:07 by masoares          #+#    #+#             */
/*   Updated: 2024/09/30 15:26:49 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
class Array
{
    private:
        T *arr;
    
    public:
        Array( void );
        ~Array( void );
        Array(Array &src);
        Array &operator= (Array &src);

        T& operator [](unsigned int i);
        
        Array(unsigned int n);
        unsigned int size ( void );
        
        class DifferentArrDimensionsExcetion : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
        
};

#include "Array.tpp"

#endif