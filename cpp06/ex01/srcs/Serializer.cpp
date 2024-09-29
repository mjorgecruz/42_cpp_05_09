/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 16:33:50 by marvin            #+#    #+#             */
/*   Updated: 2024/09/29 16:33:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    return (reinterpret_cast <uintptr_t> (ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
     return (reinterpret_cast <Data *> (raw));
}

