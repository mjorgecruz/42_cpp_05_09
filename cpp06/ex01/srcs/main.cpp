/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 17:04:39 by marvin            #+#    #+#             */
/*   Updated: 2024/09/29 17:04:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main ( void )
{
	Data *src;
	Data *out;
	uintptr_t ptr;

	src = new Data;
	src->number = 42;
	std::cout << "src_ptr:" << src << std::endl;
	std::cout << "src_number:" << src->number << std::endl;
	
	ptr = Serializer::serialize(src);
	std::cout << "ptr:" << ptr << std::endl;

	out = Serializer::deserialize(ptr);
	std::cout << "out_ptr:" << out << std::endl;
	std::cout << "out_number:" << out-> number << std::endl;

	delete src;
}