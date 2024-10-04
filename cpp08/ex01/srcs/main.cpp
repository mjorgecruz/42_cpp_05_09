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

#include "easyfind.hpp"

int main(void)
{
    std::vector <int> v;
    v.push_back(4);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    std::deque <int> dq;
    dq.push_back(4);
    dq.push_back(3);
    dq.push_back(2);
    dq.push_back(1);    
    std::list <int> ls;
    ls.push_back(4);
    ls.push_back(3);
    ls.push_back(2);
    ls.push_back(1);
    try
    {
        std::cout << ::easyfind(v, 2) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << ::easyfind(dq, 1) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {
        std::cout << ::easyfind(ls, 4) << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}