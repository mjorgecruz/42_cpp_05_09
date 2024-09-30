/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:48:49 by masoares          #+#    #+#             */
/*   Updated: 2024/09/30 10:48:45 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>

template <typename T> void iter(T arr[], int size, void (*func)(T arr[], int))
{
    func(arr, size);
}

template <typename T> void iter(T arr[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        swap(arr[i], arr[size - 1 - i]);
    }
}