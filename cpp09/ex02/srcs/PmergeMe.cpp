/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 02:55:32 by marvin            #+#    #+#             */
/*   Updated: 2024/10/06 02:55:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe(){}

PmergeMe::PmergeMe(PmergeMe &src)
{
    (void) src;
}

PmergeMe & PmergeMe::operator=(PmergeMe &src)
{
    (void) src;
    return *this;
}

std::vector<int> PmergeMe::vector_sort(char **av)
{
    int minimum = INT_MAX;
    int a;
    int b;
    int i = 1;
    //task 1: put bigger nums in a vector
    while(av[i])
    {
        if (!av[i + 1])
            break;
        a = atoi(av[i]);
        b = atoi(av[i + 1]);
        if (a > b)
        {
            sortedV.push_back(a);
            if (b < minimum)
            {
                if (minimum < INT_MAX)
                    unsortedV.push_back(minimum);
                minimum = b;
            }
            else
                unsortedV.push_back(b);
        }
        else
        {
            sortedV.push_back(b);
            if (a < minimum)
            {
                if (minimum < INT_MAX)
                    unsortedV.push_back(minimum);
                minimum = a;
            }
            else
                unsortedV.push_back(a);
        }
        i+=2;
    }
    if (av[i])
    {
        sortedV.push_back(atoi(av[i]));
    }

    //task 2: merge sort sortedV
    merge_sort_vector(0, sortedV.size() - 1);
    sortedV.insert(sortedV.begin(), minimum);

    //task3: insertion sort
    for (unsigned int i = 0; i < unsortedV.size(); i++)
    {
        sortedV.insert(std::lower_bound(sortedV.begin(), sortedV.end(), unsortedV[i]), unsortedV[i]);
        i++;
    }

    for (unsigned int i = 0; i < sortedV.size(); i++)
    {
        std::cout << sortedV[i] << std::endl;
    }
    return sortedV;
}

void PmergeMe::merge_sort_vector( unsigned int left, unsigned int right)
{
    if (left >= right)
        return;

    unsigned int mid = left + (right - left) / 2;
    merge_sort_vector( left, mid );
    merge_sort_vector( mid + 1, right);
    merge_vector(left, mid, right);
}

void PmergeMe::merge_vector(unsigned int left, unsigned int mid, unsigned int right)
{
    int space1 = mid - left + 1;
    int space2 = right - mid;

    std::vector<int> L(space1);
    std::vector<int> R(space2);

    for (int i = 0; i < space1; i++)
    {
        L[i] = sortedV[left + i];
    }
    for (int i = 0; i < space2; i++)
    {
        R[i] = sortedV[mid + 1 + i];
    }   

    int i = 0;
    int j = 0;
    int k = left;
    while (i < space1 && j < space2)
    {
        if (L[i] <= R[j])
        {
            sortedV[k] = L[i];
            i++;
        }
        else
        {
            sortedV[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < space1)
    {
        sortedV[k] = L[i];
        i++;
        k++;
    }
    while (j < space2)
    {
        sortedV[k] = R[j];
        j++;
        k++;
    }
}