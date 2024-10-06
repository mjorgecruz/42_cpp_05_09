/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:31:25 by masoares          #+#    #+#             */
/*   Updated: 2024/10/04 11:14:32 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "RPN.hpp"

int main(int ac, char **av)
{
    int result;
    if (ac != 2)
    {
        std::cerr << "Error" << std::endl;
        return 0;
    }
    RPN calculator;
    if (RPN::parser(av[1]) == -1)
        return 0;
    calculator.add_to_queue(av[1]);
    result = calculator.calculate();
    if (result == -1)
        return 0;
    std::cout << result << std::endl;
}