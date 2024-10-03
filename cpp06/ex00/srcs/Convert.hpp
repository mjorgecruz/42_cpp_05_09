/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:13:41 by masoares          #+#    #+#             */
/*   Updated: 2024/10/03 19:02:02 by masoares         ###   ########.fr       */
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

int hasOnlyDigits(std::string str);
int hasOneF(std::string str);
int hasOnePoint(std::string str);

void convertDouble (std::string str, converter Converter);
void convertFloat(std::string str, converter Converter);
void convertInt(std::string str, converter Converter);
void convertChar(std::string str, converter Converter);

void printDouble(double db);
void printFloat(float fl);

int check_type( std::string src);

#endif