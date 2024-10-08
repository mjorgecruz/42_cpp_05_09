/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:48:49 by masoares          #+#    #+#             */
/*   Updated: 2024/10/08 09:56:35 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template <typename T, typename F > void iter(T arr[], int size, F function)
{
    for (int i = 0; i < size; i++)
        function(arr[i]);
}

template <typename T> void swaping(T &value)
{
    value--;
}

#endif