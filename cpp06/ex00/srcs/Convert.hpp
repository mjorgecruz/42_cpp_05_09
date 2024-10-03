/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:13:41 by masoares          #+#    #+#             */
/*   Updated: 2024/10/03 17:32:37 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef CONVERT_HPP
# define CONVERT_HPP
#include "ScalarConverter.hpp"

struct converter
{
    char c;
    long i;
    float f;
    double d;
};

int has_only_digits(std::string str);
int has_one_f(std::string str);
int has_one_point(std::string str);

void convertDouble (std::string str, converter Converter);
void convertFloat(std::string str, converter Converter);
void convertInt(std::string str, converter Converter);
void convertChar(std::string str, converter Converter);

void printDouble(double db);
void printFloat(float fl);

int check_type( std::string src);

#endif