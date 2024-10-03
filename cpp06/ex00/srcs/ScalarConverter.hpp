/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:35:31 by marvin            #+#    #+#             */
/*   Updated: 2024/10/03 11:56:58 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdio>
#include <iomanip>
#include <limits.h>
#include <float.h>
#include <cstdlib>
#include <cerrno>

enum type {
    C,
    I,
    F,
    D,
    N
};

class ScalarConverter
{
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(ScalarConverter &src);
        ScalarConverter &operator= (ScalarConverter &src);
    public:
        static void convert(std::string src);
};

struct converter
{
    char c;
    long i;
    float f;
    double d;
};

#endif