/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:41:55 by masoares          #+#    #+#             */
/*   Updated: 2024/10/09 10:49:05 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "easyfind.hpp"


template <typename T> unsigned int easyfind(T src, int x)
{
    typename T::iterator i = std::find(src.begin(), src.end(), x);
    if (i != src.end())
    {
        int position = std::distance( src.begin(), i);
        return position;
    }
    throw (std::out_of_range("Number not found"));
}


