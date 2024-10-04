/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 12:15:03 by masoares          #+#    #+#             */
/*   Updated: 2024/10/04 12:06:41 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Convert.hpp"

int hasOnlyDigits(std::string str)
{
	int		i;

	i = 0;
    if (str[0] == '+' || str[0] == '-')
    {
        i++;
    }   
	while (str[i] != 0)
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int hasOneF(std::string str)
{
    int		i;

	i = 0;
    if (str[0] == '+' || str[0] == '-')
        i++; 
        
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

int hasOnePoint(std::string str)
{
    int		i;

	i = 0;
    if (str[0] == '+' || str[0] == '-')
        i++;
    
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

void convertDouble (std::string str, converter Converter)
{
    Converter.d = strtod(str.c_str(), NULL);
    Converter.c = static_cast<char>(Converter.d);
    Converter.i = static_cast<int>(Converter.d);
    Converter.f = static_cast<float>(Converter.d);
    if (errno == ERANGE)
    {
        std::cout << "num_char = " << "impossible" << std::endl;
        std::cout << "num_int = " << "impossible" << std::endl;
        std::cout << "num_float = " << "impossible" << std::endl;
        std::cout << "num_double = " << "impossible" << std::endl;
    }
    else
    {
        if (Converter.d < 255.0 && Converter.d > 0)
        {
            if (Converter.d <= 32 || Converter.d >=127)
                std::cout << "num_char = " << "Non displayable" << std::endl;
            else
                std::cout << "num_char = " << Converter.c << std::endl;
            std::cout << "num_int = " << Converter.i << std::endl;
            printFloat(Converter.f);
            printDouble(Converter.d);
        }
        else if (Converter.d <= static_cast<double>(INT_MAX) && Converter.d >= static_cast<double>(INT_MIN))
        {
            std::cout << "num_char = " << "impossible" << std::endl;
            std::cout << "num_int = " << Converter.i << std::endl;
            printFloat(Converter.f);
            printDouble(Converter.d);
        }
        else if ((Converter.d > static_cast<double>(FLT_MAX) || Converter.d < static_cast<double>(-FLT_MAX)) && Converter.d != INFINITY && Converter.d != -INFINITY)
        {
            std::cout << "num_char = " << "impossible" << std::endl;
            std::cout << "num_int = " << "impossible" << std::endl;
            std::cout << "num_float = " << "impossible" << std::endl;
            printDouble(Converter.d);
        }
        else
        {
            std::cout << "num_char = " << "impossible" << std::endl;
            std::cout << "num_int = " << "impossible" << std::endl;
            printFloat(Converter.f);
            printDouble(Converter.d);
        }
    }
}

void convertFloat(std::string str, converter Converter)
{
    Converter.f = strtof(str.c_str(), NULL);
    Converter.c = static_cast<char>(Converter.f);
    Converter.i = static_cast<int>(Converter.f);
    Converter.d = static_cast<double>(Converter.f);
    if (errno == ERANGE)
    {
        std::cout << "num_char = " << "impossible" << std::endl;
        std::cout << "num_int = " << "impossible" << std::endl;
        std::cout << "num_float = " << "impossible" << std::endl;
        std::cout << "num_double = " << "impossible" << std::endl;
    }
    else
    {
        if (Converter.f <= 255.0 && Converter.f > 0 )
        {
            if (Converter.d <= 32 || Converter.d >= 127)
                std::cout << "num_char = " << "Non displayable" << std::endl;
            else
                std::cout << "num_char = " << Converter.c << std::endl;
            std::cout << "num_char = " << Converter.c << std::endl;
            std::cout << "num_int = " << Converter.i << std::endl;
            printFloat(Converter.f);
            printDouble(Converter.d);
        }
        else if (Converter.f <= static_cast<float>(INT_MAX) && Converter.f >= static_cast<float>(INT_MIN))
        {
            std::cout << "num_char = " << "impossible" << std::endl;
            std::cout << "num_int = " << Converter.i << std::endl;
            printFloat(Converter.f);
            printDouble(Converter.d);
        }
        else
        {
            std::cout << "num_char = " << "impossible" << std::endl;
            std::cout << "num_int = " << "impossible" << std::endl;
            printFloat(Converter.f);
            printDouble(Converter.d);
        }
    }
}

void convertChar(std::string str, converter Converter)
{
    Converter.c = str[0];
    Converter.i = static_cast<int>(Converter.c);
    Converter.f = static_cast<float>(Converter.c);
    Converter.d = static_cast<double>(Converter.c);
    std::cout << "num_char = " << Converter.c << std::endl;
    std::cout << "num_int = " << Converter.i << std::endl;
    std::cout << "num_float = " << Converter.f << std::endl;
    std::cout << "num_double = " << Converter.d << std::endl;
}

void convertInt(std::string str, converter Converter)
{
    long temp = strtol(str.c_str(), NULL, 10);
    Converter.i = atoi(str.c_str());
    Converter.c = static_cast<char>(Converter.i);
    Converter.f = static_cast<float>(Converter.i);
    Converter.d = static_cast<double>(Converter.i);
    if (errno == ERANGE || temp > INT_MAX || temp < INT_MIN)
    {
        std::cout << "num_char = " << "impossible" << std::endl;
        std::cout << "num_int = " << "impossible" << std::endl;
        std::cout << "num_float = " << "impossible" << std::endl;
        std::cout << "num_double = " << "impossible" << std::endl;
    }
    else
    {
        if (Converter.i <= 255.0 && Converter.i >= 0)
        {
            if (Converter.i <= 32 || Converter.i >= 127)
                std::cout << "num_char = " << "Non displayable" << std::endl;
            else
                std::cout << "num_char = " << Converter.c << std::endl;
            std::cout << "num_int = " << Converter.i << std::endl;
            printFloat(Converter.f);
            printDouble(Converter.d);
        }
        else
        {
            std::cout << "num_char = " << "impossible" << std::endl;
            std::cout << "num_int = " << Converter.i << std::endl;
            printFloat(Converter.f);
            printDouble(Converter.d);
        }
    }
}

void printDouble(double db)
{
    if (db - std::floor(db) < 1e-7 && std::floor(db) < 1e5 && std::floor(db) > -1e5)
        std::cout << "num_double = " << db << ".0" << std::endl;
    else
        std::cout << "num_double = " << db << std::endl;
}

void printFloat(float fl)
{
    if (fl - std::floor(fl) < 1e-7 && std::floor(fl) < 1e5 && std::floor(fl) > -1e5)
        std::cout << "num_float = " << fl << ".0f" << std::endl;
    else
        std::cout << "num_float = " << fl << "f" << std::endl;
}

int check_type( std::string src)
{
    int type;
    
    if (src == "-inff" || src == "inff" || src == "+inff" || src == "nanf" )
        type = F;
    else if (src == "-inf" || src == "inf" ||src == "+inf" || src == "nan")
        type = D;
    else if (hasOnlyDigits(src))
        type = I;
    else if (src.size() == 1)
        type = C;
    else
    {
        if (hasOneF(src))
            type = F;
        else if (hasOnePoint(src))
            type = D;
        else
            type = N;
    }
    return type;
    
}