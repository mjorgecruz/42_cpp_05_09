/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 09:55:48 by masoares          #+#    #+#             */
/*   Updated: 2024/09/30 10:53:26 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include   "whatever.hpp"
#include   "iter.hpp"

int main( void ) 
{
    int int_arr[4] = {1, 2, 3, 4};
    ::iter<int>(int_arr, 4);

    for (int i = 0; i < 4; i++)
    {
        std::cout << int_arr[i] << " "; 
    }
    std::cout << std::endl;
    
    return 0;
}