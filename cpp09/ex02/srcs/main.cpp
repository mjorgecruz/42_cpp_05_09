/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:31:25 by masoares          #+#    #+#             */
/*   Updated: 2024/10/07 11:48:55 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    (void) ac;
    PmergeMe test;
    std::vector<int> lala;

    lala = test.vector_sort(ac, av);

}