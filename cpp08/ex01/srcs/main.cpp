/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:31:25 by masoares          #+#    #+#             */
/*   Updated: 2024/10/09 12:20:38 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Span.hpp"

int main(void)
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    Span values(10000);
    
    srand(time(NULL));
    std::vector<int> arr;
    for (int i = 0; i < 1000; i++)
    {
        arr.push_back(rand());
    }
    try
    {
        values.addRange(arr);
        std::cout << values.shortestSpan()<< std::endl;
        std::cout << values.longestSpan() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        for (int i = 0; i < 5000; i++)
        {
            values.addNumber(rand());
        }
        std::cout << values[4000] << std::endl;
        std::cout << values.size() << std::endl;
        std::cout << values.vectorSize() << std::endl;
        std::cout << values[6000] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        for (int i = 0; i < 5000; i++)
        {
            values.addNumber(rand());
        }
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