/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:57:07 by masoares          #+#    #+#             */
/*   Updated: 2024/10/08 10:14:30 by masoares         ###   ########.fr       */
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
        unsigned int _size;
    
    public:
        Array( void );
        ~Array( void );
        Array(Array &src);
        Array &operator= (Array &src);

        T& operator [](unsigned int i);
        const T& operator [](unsigned int i) const;
        
        Array(unsigned int n);
        unsigned int size ( void ) const;
          
};

#include "Array.tpp"

#endif