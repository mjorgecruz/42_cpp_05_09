/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:31:25 by masoares          #+#    #+#             */
/*   Updated: 2024/10/14 16:07:47 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Error" << std::endl;
        return 0;
    }
    RPN calculator;
    if (av[1][0] == 0)
    {
        std::cerr << "Error" << std::endl;
        return 0;
    }
    if (RPN::parser(av[1]) == -1)
        return 0;
    try{
        calculator.add_to_queue(av[1]);
    }
    catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }
}