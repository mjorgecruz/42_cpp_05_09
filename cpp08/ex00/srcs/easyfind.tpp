/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:41:55 by masoares          #+#    #+#             */
/*   Updated: 2024/10/04 11:12:20 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "easyfind.hpp"


template <typename T> unsigned int easyfind(T src, int x)
{
    typename T::iterator i = src.begin();
    for (i = src.begin(); i != src.end(); ++i)
        {
            if (*i == x)
            {
                int position = std::distance( src.begin(), i);
                return position;
            }
    }
    throw (OwnException::NotFoundException());
}

const char * OwnException::NotFoundException::what() const throw()
{
    return("Int not found");
};

