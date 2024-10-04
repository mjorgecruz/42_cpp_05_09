/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:48:49 by masoares          #+#    #+#             */
/*   Updated: 2024/10/04 16:50:20 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T> void swap(T& x, T& y)
{
    T z = x;
    x = y;
    y = z;
}

template <typename T> T min(T x, T y)
{
    if (x < y)
        return (x);
    else
        return (y);
}

template <typename T> T max(T x, T y)
{
    if (x > y)
        return (x);
    else
        return (y);
}

#endif