/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checker.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 15:31:32 by masoares          #+#    #+#             */
/*   Updated: 2024/10/03 15:33:00 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

int check_type( std::string src)
{
    int type;
    
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
    return type;
    
}