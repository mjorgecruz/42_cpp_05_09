/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 10:31:25 by masoares          #+#    #+#             */
/*   Updated: 2024/10/17 12:04:32 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "PmergeMe.hpp"

int main(int ac, char **av)
{
    (void) ac;
    PmergeMe test;
    std::vector<int> lala;
    std::deque<int> lolo;
    std::vector<int> numbers;
    if (ac == 1)
    {
        std::cerr << "Error" << std::endl;
        return -1;
    }
    for (int i = 1; i < ac; i++)
    {
        for(int j = 0; av[i][j]; j++)
        {
            if (!isdigit(av[i][j]))
            {
                std::cerr << "Error" << std::endl;
                return -1;
            }
        }
        if (((std::string)av[i]).empty())
        {
            std::cerr << "Error" << std::endl;
            return -1;
        }
            
    }
    if (ac == 2)
    {
        std::cout << "Before " << av[1] << std::endl;
        std::cout << "After  " << av[1] << std::endl;
        std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector :" << std::fixed << std::setprecision(5) << 0.00000 << " us" << std::endl;
        std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque  :" << std::fixed << std::setprecision(5) << 0.00000 << " us" << std::endl;
        return 0;
    }
    for (int i = 1; i < ac; i++)
    {
        numbers.push_back(std::strtol(av[i], NULL, 10));
        if (numbers[i - 1] < 0)
        {
            std::cerr << "Error" << std::endl;
            return -1;
        }   
    }    
    std::sort(numbers.begin(), numbers.end());
    for(unsigned int i = 0; i < numbers.size() - 1; i++)
    {
        if (numbers[i] == numbers[i + 1])
        {
            std::cerr << "Error" << std::endl;
            return -1;
        }
    }

    clock_t start, end;
    std::cout << "Before ";
    for (int i = 1; i < ac; i++)
          std::cout << av[i] << " " ;
    std::cout << std::endl;
    std::cout << "After  ";

    start = clock();
    lala = test.vector_sort(ac, av);
    end =  clock();
    float time_taken = end - start;
    for (unsigned int i = 0; i < lala.size(); i++)
    {
        std::cout << lala[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector :" << std::fixed << std::setprecision(5) << time_taken << " us" << std::endl;
    
    start = clock();
    lolo = test.set_sort(ac, av);
    end = clock(); 
    time_taken = end - start;
    std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque :" << std::fixed << std::setprecision(5) << time_taken << " us" << std::endl;

}