/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:35:31 by marvin            #+#    #+#             */
/*   Updated: 2024/10/02 15:51:16 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdio>
#include <iomanip>
#include <limits>
#include <cstdlib>

enum type {
    C,
    I,
    F,
    D
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
    int i;
    float f;
    double d;
};

#endif