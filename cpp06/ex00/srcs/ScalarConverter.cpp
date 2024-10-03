/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:35:33 by marvin            #+#    #+#             */
/*   Updated: 2024/10/03 16:39:15 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
    converter Converter;
    int type = check_type(src);
    switch (type)
    {
        case D:
            convertDouble(src, Converter);
            break;
        case F:
            convertFloat(src, Converter);
            break;
        case C:
            convertChar(src, Converter);
            break;
        case I:
            convertInt(src, Converter);
            break;
        case N:
                std::cout << "num_char = " << "impossible" << std::endl;
                std::cout << "num_int = " << "impossible" << std::endl;
                std::cout << "num_float = " << "impossible" << std::endl;
                std::cout << "num_double = " << "impossible" << std::endl;
        break;
    }
}   