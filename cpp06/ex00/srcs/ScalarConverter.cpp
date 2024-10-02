/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:35:33 by marvin            #+#    #+#             */
/*   Updated: 2024/10/02 16:33:22 by masoares         ###   ########.fr       */
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
                while (str[i] != 0)
	            {
                    
		            if (!isdigit(str[i]) && str[i] != 'f')
                    {
                        return 0;
                    }
                    i++;
                }
            }
        }
		i++;
	}
    return 1;
}

// int has_one_point(std::string str)
// {
//     int		i;

// 	i = 0;
//     while (str[i] != 0)
// 	{
// 		if (!isdigit(str[i]))
//         {
//             if (str[i] == '.')
//             {
//                 while (str[i] != 0)
// 	            {
                    
// 		            if (!isdigit(str[i]) && str[i] != 'f')
//                     {
//                         return 0;
//                     }
//                     i++;
//                 }
//             }
//         }
// 		i++;
// 	}
//     return 1;
// }

void ScalarConverter::convert(std::string src)
{
    converter Converter;
    std::string type;
    

    
    if (src.size() == 1)
    {
        if (has_only_digits(src) == 0)
        {
            type = "CHAR";

        }
        else
        {
            sscanf(src.c_str(), "%d", &Converter.i);
            Converter.c = static_cast<char> (Converter.i);
            Converter.f = static_cast<float> (Converter.i);
            Converter.d = static_cast<double>(Converter.i);
        }
    }
    else
    {
        if (has_only_digits(src))
        {
            sscanf(src.c_str(), "%d", &Converter.i);
            Converter.c = static_cast<char> (Converter.i);
            Converter.f = static_cast<float> (Converter.i);
            Converter.d = static_cast<double>(Converter.i);
        }
        if ()
    }
    
    switch (type)
    {
    case CHAR:
        Converter.c = src[0];
        Converter.i = static_cast<int>(Converter.c);
        Converter.f = static_cast<float>(Converter.c);
        Converter.d = static_cast<double>(Converter.c);
        /* code */
        break;
    
    default:
        break;
    }
    // Scan.scan[0] = sscanf(src.c_str(), "%c", &Scan.c);
    // Scan.scan[1] = sscanf(src.c_str(), "%i", &Scan.i);
    // Scan.scan[2] = sscanf(src.c_str(), "%f", &Scan.f);
    // Scan.scan[3] = sscanf(src.c_str(), "%lf", &Scan.d);

    // if (Scan.scan[0] && !Scan.scan[1] && src.size() == 1)
    // {
    //     Scan.i = static_cast<int>(Scan.c);
    //     Scan.f = static_cast<float>(Scan.c);
    //     Scan.d = static_cast<double>(Scan.c);
    // }
    // else if (Scan.scan[1] && has_only_digits(src))
    // {
    //     Scan.f = static_cast<float>(Scan.c);
    //     Scan.d = static_cast<double>(Scan.c);
    // }
    // else if (Scan.scan[2] && has_one_f(src))
    // {
        
    // }
    
    // if(sscanf(src.c_str(), "%c", &c) == 1) 
    // {
    //     if (src.size() == 1)
    //     {
    //         if (i < 32)
    //             std::cout << "num_char = " << "Non displayable" << std::endl;
    //         else
    //             std::cout << "num_char = " << src[0] << std::endl;
    //         std::cout << "num_int = " << static_cast<int>(c) << std::endl;
    //         std::cout << "num_float = " << static_cast<float>(c) << std::endl;
    //         std::cout << "num_double = " << static_cast<double>(c) << std::endl;
    //     }
    //     else
    //         std::cout << "num_char = " << "impossible" << std::endl;
    //         std::cout << "num_int = " << "impossible" << std::endl;
    //         std::cout << "num_float = " << "impossible" << std::endl;
    //         std::cout << "num_double = " << "impossible" << std::endl;       
    // }
    // else if (sscanf(src.c_str(), "%i", &i) == 1)
    // {
    //     if (i < 256)
    //     {
    //         if (i < 32)
    //             std::cout << "num_char = " << "Non displayable" << std::endl;
    //         else
    //             std::cout << "num_int = " << static_cast<char>(i) << std::endl;
    //         std::cout << "num_int = " << i << std::endl;
    //         std::cout << "num_float = " << static_cast<float>(i) << std::endl;
    //         std::cout << "num_double = " << static_cast<double>(i) << std::endl;
    //     }
    // }
    // else if (sscanf(src.c_str(), "%f", &f) == 1)
    // {
        
    // }
    // else if ()
    // // string -> char
    // if(sscanf(src.c_str(), "%d", &i) == 1 && i < 256)
    // {
    //     if (i >= 0 && i < 32)
    //         std::cout << "num_char = " << "Non displayable" << std::endl;
    //     else
    //     {
    //         c = i;
    //         std::cout << "num_char = " << c << std::endl;
    //     }
    // }
    // else
    // {
    //     if (src.size() == 1)
    //     {
    //         isChar = true;
    //         std::cout << "num_char = " << static_cast <char> (i) << std::endl;
    //     }
    //     else
    //         std::cout << "num_char = " << "impossible" << std::endl;
    // }

    // // string -> integer
    // if(sscanf(src.c_str(), "%d", &i) != 1 &&  isChar == false)
    //     std::cout << "num_int = " << "impossible" << std::endl;
    // else if (isChar == true)
    // {
    //     std::cout << "num_int = " << (int) (src.c_str())[0] << std::endl;
    // }
    // else
    //     std::cout << "num_int = " << i << std::endl;

    // // string -> float
    // if(sscanf(src.c_str(), "%f", &f) != 1)
    // {
    //     if (isChar == true)
    //         std::cout << "num_float = " << std::fixed << std::setprecision(1) << (float) (src.c_str())[0] << "f" << std::endl;
    //     else
    //         std::cout << "num_float = " << "impossible" << std::endl;
    // }
    // else
    //     std::cout << "num_float = " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
    
    // // string -> double
    // if(sscanf(src.c_str(), "%lf", &d) != 1)
    // {
    //     if (isChar == true)
    //         std::cout << "num_double = " << std::fixed << std::setprecision(1) << (double) (src.c_str())[0] << std::endl;
    //     else
    //         std::cout << "num_double = " << "impossible" << std::endl;
    // }
    // else
    //     std::cout << "num_double = " << d << std::endl;
    
}