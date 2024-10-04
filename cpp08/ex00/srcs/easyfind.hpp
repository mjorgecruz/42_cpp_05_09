/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:57:07 by masoares          #+#    #+#             */
/*   Updated: 2024/10/04 11:03:17 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>

template <typename T> unsigned int easyfind (T src, int x);

class OwnException : std::exception
{
    public:
        class NotFoundException : public std::exception
        {
            public:
                virtual const char* what() const throw();
        };
};

#include "easyfind.tpp"
#endif