/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:31:25 by masoares          #+#    #+#             */
/*   Updated: 2024/10/04 16:15:38 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Span.hpp"

int main(void)
{
    Span values(10000);
    
    srand(time(NULL));
    
    try
    {
        values.shortestSpan();
        std::cout << values.shortestSpan()<< std::endl;
        std::cout << values.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    for (int i = 0; i < 5000; i++)
    {
        values.addNumber(rand());
    }
    try
    {
        std::cout << values[4000] << std::endl;
        std::cout << values.size() << std::endl;
        std::cout << values.vectorSize() << std::endl;
        std::cout << values[6000] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    for (int i = 0; i < 5000; i++)
    {
        values.addNumber(rand());
    }
    try
    {
        std::cout << values[9000] << std::endl;
        std::cout << values.size() << std::endl;
        std::cout << values.vectorSize() << std::endl;
        std::cout << values[10000] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        values.addNumber(rand());
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << values.longestSpan()<< std::endl;
        std::cout << values.shortestSpan()<< std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}