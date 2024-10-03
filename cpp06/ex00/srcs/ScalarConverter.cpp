/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:35:33 by marvin            #+#    #+#             */
/*   Updated: 2024/10/03 12:06:31 by masoares         ###   ########.fr       */
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

int has_only_digits(std::string str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int has_one_f(std::string str)
{
    int		i;

	i = 0;
    while (str[i] != 0)
	{
		if (!isdigit(str[i]))
        {
            if (str[i] == 'f')
            {
                if (str[i + 1] != 0)
                    return 0;
            }
            else
                return 0;
        }
		i++;
    }
    return 1;
}

int has_one_point(std::string str)
{
    int		i;

	i = 0;
    while (str[i] != 0)
	{
		if (!isdigit(str[i]))
        {
            if (str[i] == '.')
            {
                i++;
                while (str[i] != 0)
	            {
		            if (!isdigit(str[i]) && str[i] != 'f')
                    {
                        return 0;
                    }
                    i++;
                }
            }
            else
                return 0;
        }
		i++;
	}
    return 1;
}

void ScalarConverter::convert(std::string src)
{
    converter Converter;
    int type = 0;

    if (src == "-inff" || src == "inff" || src == "+inff" || src == "nanf" )
        type = F;
    else if (src == "-inf" || src == "inf" ||src == "+inf" || src == "nan")
        type = D;
    else if (has_only_digits(src))
        type = I;
    else if (src.size() == 1)
        type = C;
    else
    {
        if (has_one_f(src))
            type = F;
        else if (has_one_point(src))
            type = D;
        else
            type = N;
    }
    
    bool printed = false;
    
    switch (type)
    {
        case D:
            Converter.d = strtod(src.c_str(), NULL);
            if (errno == ERANGE)
            {
                std::cout << "num_char = " << "impossible" << std::endl;
                std::cout << "num_int = " << "impossible" << std::endl;
                std::cout << "num_float = " << "impossible" << std::endl;
                std::cout << "num_double = " << "impossible" << std::endl;
                printed = true;
            }
            else
            {
                if (Converter.d < 255.0 && Converter.d > 0 )
                {
                    Converter.c = static_cast<char>(Converter.d);
                    Converter.i = static_cast<int>(Converter.d);
                    Converter.f = static_cast<float>(Converter.d);
                    std::cout << "num_char = " << Converter.c << std::endl;
                    std::cout << "num_int = " << Converter.i << std::endl;
                    std::cout << "num_float = " << Converter.f << std::endl;
                    std::cout << "num_double = " << Converter.d << std::endl;
                    printed = true;
                }
                else if (Converter.d <= static_cast<double>(INT_MAX) && Converter.d >= static_cast<double>(INT_MIN))
                {
                    Converter.i = static_cast<int>(Converter.d);
                    Converter.f = static_cast<float>(Converter.d);
                    std::cout << "num_char = " << "impossible" << std::endl;
                    std::cout << "num_int = " << Converter.i << std::endl;
                    std::cout << "num_float = " << Converter.f << std::endl;
                    std::cout << "num_double = " << Converter.d << std::endl;
                    printed = true;
                }
                else if (Converter.d <= static_cast<double>(FLT_MAX) && Converter.d >= static_cast<double>(FLT_MIN))
                {
                    Converter.f = static_cast<float>(Converter.d);
                    std::cout << "num_char = " << "impossible" << std::endl;
                    std::cout << "num_int = " << "impossible" << std::endl;
                    std::cout << "num_float = " << Converter.f << std::endl;
                    std::cout << "num_double = " << Converter.d << std::endl;
                    printed = true;
                }
                else
                {
                    std::cout << "num_char = " << "impossible" << std::endl;
                    std::cout << "num_int = " << "impossible" << std::endl;
                    std::cout << "num_float = " << "impossible" << std::endl;
                    std::cout << "num_double = " << Converter.d << std::endl;
                    printed = true;
                }
                break;
            }
        case F:
            Converter.f = strtof(src.c_str(), NULL);
            if (errno == ERANGE)
            {
                std::cout << "num_char = " << "impossible" << std::endl;
                std::cout << "num_int = " << "impossible" << std::endl;
                std::cout << "num_float = " << "impossible" << std::endl;
                std::cout << "num_double = " << "impossible" << std::endl;
                break;
            }
            else
            {
                if (Converter.f < 255.0 && Converter.f > 0 )
                {
                    Converter.c = static_cast<char>(Converter.f);
                    Converter.i = static_cast<int>(Converter.f);
                    Converter.d = static_cast<double>(Converter.f);
                    std::cout << "num_char = " << Converter.c << std::endl;
                    std::cout << "num_int = " << Converter.i << std::endl;
                    std::cout << "num_float = " << Converter.f << std::endl;
                    std::cout << "num_double = " << Converter.d << std::endl;
                    printed = true;
                }
                else if (Converter.f <= static_cast<float>(INT_MAX) && Converter.f >= static_cast<float>(INT_MIN))
                {
                    Converter.i = static_cast<int>(Converter.f);
                    Converter.d = static_cast<double>(Converter.f);
                    std::cout << "num_char = " << "impossible" << std::endl;
                    std::cout << "num_int = " << Converter.i << std::endl;
                    std::cout << "num_float = " << Converter.f << std::endl;
                    std::cout << "num_double = " << Converter.d << std::endl;
                    printed = true;
                }
                else
                {
                    Converter.d = static_cast<double>(Converter.f);
                    std::cout << "num_char = " << "impossible" << std::endl;
                    std::cout << "num_int = " << "impossible" << std::endl;
                    std::cout << "num_float = " << Converter.f << std::endl;
                    std::cout << "num_double = " << Converter.d << std::endl;
                    printed = true;
                }
                break;
            }
        case C:
            Converter.c = src[0];
            Converter.i = static_cast<int>(Converter.c);
            Converter.f = static_cast<float>(Converter.c);
            Converter.d = static_cast<double>(Converter.c);
            std::cout << "num_char = " << Converter.c << std::endl;
            std::cout << "num_int = " << Converter.i << std::endl;
            std::cout << "num_float = " << Converter.f << std::endl;
            std::cout << "num_double = " << Converter.d << std::endl;
            printed = true;
            break;
            
        case I:
            Converter.i = strtol(src.c_str(), NULL, 16);
            if (errno == ERANGE || Converter.i > INT_MAX || Converter.i < INT_MIN)
            {
                std::cout << "num_char = " << "impossible" << std::endl;
                std::cout << "num_int = " << "impossible" << std::endl;
                std::cout << "num_float = " << "impossible" << std::endl;
                std::cout << "num_double = " << "impossible" << std::endl;
                break;
            }
            else
            {
                if (Converter.i < 255.0 && Converter.i > 0)
                {
                    Converter.c = static_cast<char>(Converter.i);
                    Converter.f = static_cast<float>(Converter.i);
                    Converter.d = static_cast<double>(Converter.i);
                    std::cout << "num_char = " << Converter.c << std::endl;
                    std::cout << "num_int = " << Converter.i << std::endl;
                    std::cout << "num_float = " << Converter.f << std::endl;
                    std::cout << "num_double = " << Converter.d << std::endl;
                    printed = true;
                }
                else
                {
                    Converter.f = static_cast<float>(Converter.i);
                    Converter.d = static_cast<double>(Converter.i);
                    std::cout << "num_char = " << "impossible" << std::endl;
                    std::cout << "num_int = " << Converter.i << std::endl;
                    std::cout << "num_float = " << Converter.f << std::endl;
                    std::cout << "num_double = " << Converter.d << std::endl;
                    printed = true;
                }
                break;
            }
        case N:
                std::cout << "num_char = " << "impossible" << std::endl;
                std::cout << "num_int = " << "impossible" << std::endl;
                std::cout << "num_float = " << "impossible" << std::endl;
                std::cout << "num_double = " << "impossible" << std::endl;
        break;
    }
}   