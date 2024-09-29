/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:31:12 by marvin            #+#    #+#             */
/*   Updated: 2024/09/29 16:31:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>
#include <string>
#include <cstdio>
#include <iomanip>
        
struct Data
{
    int number;
};

typedef size_t uintptr_t;

#endif

/*
uintptr_t
It's an unsigned integer type exactly the size of a pointer.
Whenever you need to do something unusual with a pointer - like for example invert all bits you cast it to uintptr_t
and manipulate it as a usual integer number, then cast back.

"what it can be used for?"
Primarily for bitwise operations on pointers. Remember that in C++ one cannot perform bitwise operations on pointers.
Thus in order to do bitwise operations on pointers one would need to cast pointers to type uintptr_t and then perform
bitwise operations.
*/