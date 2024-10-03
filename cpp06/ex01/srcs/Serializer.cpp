/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:33:50 by marvin            #+#    #+#             */
/*   Updated: 2024/10/03 18:30:34 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Serializer.hpp"

Serializer::Serializer()
{}

Serializer::~Serializer()
{}

Serializer::Serializer(Serializer &src)
{
    (void)src;
}

Serializer &Serializer::operator= (Serializer &src)
{
    (void)src;
    return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
    if (!ptr)
        return (0);
    return (reinterpret_cast <uintptr_t> (ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    if (!raw)
        return (NULL);
     return (reinterpret_cast <Data *> (raw));
}

