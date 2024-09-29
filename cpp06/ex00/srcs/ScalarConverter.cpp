/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:35:33 by marvin            #+#    #+#             */
/*   Updated: 2024/09/29 11:35:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{}

ScalarConverter::~ScalarConverter()
{}

ScalarConverter::ScalarConverter(ScalarConverter &src)
{
    (void)src;
}

ScalarConverter &ScalarConverter::operator= (ScalarConverter &src)
{
    (void)src;
    return (*this);
}


void ScalarConverter::convert(std::string src)
{

    char c;
    int i;
    float f;
    double d;
    bool isChar;

    isChar = false;
    
    // string -> char
    if(sscanf(src.c_str(), "%d", &i) != 1 && i < 256)
    {

        if (i >= 0 && i < 32)
            std::cout << "num_char = " << "Non displayable" << std::endl;
        else
        {
            c = i;
            std::cout << "num_char = " << c << std::endl;
        }
    }
    else
        if (src.size() == 1)
        {
            isChar = true;
            std::cout << "num_char = " << (src.c_str())[0] << std::endl;
        }
        else
            std::cout << "num_char = " << "impossible" << std::endl;

    // string -> integer
    if(sscanf(src.c_str(), "%d", &i) != 1 &&  isChar == false)
        std::cout << "num_int = " << "impossible" << std::endl;
    else if (isChar == true)
    {
        std::cout << "num_int = " << (int) (src.c_str())[0] << std::endl;
    }
    else
        std::cout << "num_int = " << i << std::endl;


    // string -> float
    if(sscanf(src.c_str(), "%f", &f) != 1)
        std::cout << "num_float = " << "impossible" << std::endl;
    else
        std::cout << "num_float = " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    
    // string -> double
    if(sscanf(src.c_str(), "%lf", &d) != 1)
        std::cout << "num_int = " << "impossible" << std::endl;
    else
        std::cout << "num_double = " << d << std::endl;
    
}