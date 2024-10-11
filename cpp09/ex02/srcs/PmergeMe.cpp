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

std::vector<int> PmergeMe::vector_sort(int ac, char **av)
{
    int a;
    int b;
    unsigned int i = 1;
    int x[ac][2];

    //task 1: put bigger nums in a vector and add to vector
    while(av[i])
    {

        if (!av[i + 1])
            break;
        a = atoi(av[i]);
        b = atoi(av[i + 1]);
        if (a < b)
        {
            x[i][0] = a;
            x[i][1] = b;
        }
        else
        {
            x[i][0] = b;
            x[i][1] = a;
        }
        unsortedV.push_back(x[i]);
        i+=2;
    }
    merge_sort_vector(sortedV, unsortedV);

    if (av[i])
        sortedV.insert(std::lower_bound(sortedV.begin(), sortedV.end(), atoi(av[i])), atoi(av[i]));

    for (unsigned int i = 0; i < sortedV.size(); i++)
    {
        std::cout << sortedV[i] << std::endl;
    }
    return sortedV;
}


void PmergeMe::merge_sort_vector( std::vector<int> &sorted, std::vector<int *> left )
{
    if (left.size() == 0)
        return;
    if (left.size() == 1)
    {
        sorted.push_back(left[0][0]);
        sorted.push_back(left[0][1]);
        return;
    }

    std::vector<int> left_sorted;
    std::vector<int> right_sorted;
    std::vector<int *> left_pairs( left.begin(), left.begin() + left.size()/2);
    std::vector<int *> right_pairs( left.begin() + left.size()/2, left.end());

    merge_sort_vector(left_sorted, left_pairs);
    merge_sort_vector(right_sorted, right_pairs);
    merge_vector(left_sorted, right_sorted, sorted);
}

void PmergeMe::merge_vector(std::vector<int> left_sorted, std::vector<int> right_sorted, std::vector<int> &sorted)
{
  
    unsigned int i = 0;
    unsigned int j = 0;

    while (i < left_sorted.size() && j < right_sorted.size())
    {
        if (left_sorted[i] <= right_sorted[j])
        {
            sorted.push_back(left_sorted[i]);
            i++;
        }
        else
        {
            sorted.push_back(right_sorted[j]);
            j++;
        }
    }
    while (i < left_sorted.size())
    {
        sorted.push_back(left_sorted[i]);
        i++;
    }
    while (j < right_sorted.size())
    {
        sorted.push_back(right_sorted[j]);
        j++;
    }
}

// void PmergeMe::merge_sort_vector_pairs( unsigned int left, unsigned int right)
// {
//     if (left >= right)
//         return;

//     unsigned int mid = left + (right - left) / 2;
//     merge_sort_vector_pairs( left, mid );
//     merge_sort_vector_pairs( mid + 1, right);
//     merge_vector_pairs(left, mid, right);
// }

// void PmergeMe::merge_vector_pairs(unsigned int left, unsigned int mid, unsigned int right)
// {
//     int space1 = mid - left + 1;
//     int space2 = right - mid;

//     std::vector<int *> L(space1);
//     std::vector<int *> R(space2);

//     for (int i = 0; i < space1; i++)
//     {
//         L[i] = unsortedV[left + i];
//     }
//     for (int i = 0; i < space2; i++)
//     {
//         R[i] = unsortedV[mid + 1 + i];
//     }   

//     int i = 0;
//     int j = 0;
//     int k = left;
//     while (i < space1 && j < space2)
//     {
//         if (L[i][1] <= R[j][1])
//         {
//             unsortedV[k] = L[i];
//             i++;
//         }
//         else
//         {
//             unsortedV[k] = R[j];
//             j++;
//         }
//         k++;
//     }
//     while (i < space1)
//     {
//         unsortedV[k] = L[i];
//         i++;
//         k++;
//     }
//     while (j < space2)
//     {
//         unsortedV[k] = R[j];
//         j++;
//         k++;
//     }
// }

    // task 2: merge sort the pairs based on the bigger element
    //merge_sort_vector_pairs(0, unsortedV.size() - 1);


    // for (unsigned int i = 0; i < unsortedV.size(); i++)
    // {
    //     sortedV.push_back(unsortedV[i][0]);
    // }
    // for (unsigned int i = 0; i < unsortedV.size(); i++)
    // {
    //     sortedV.push_back(unsortedV[i][1]);
    // }
    // i = 0;


    // std::vector<int *> resortedV;
    // while(i < sortedV.size() - 1)
    // {
    //     a = *(&sortedV[i]);
    //     b = *(&sortedV[i + 1]);
    //     if (a < b)
    //     {
    //         x[i][0] = a;
    //         x[i][1] = b;
    //     }
    //     else
    //     {
    //         x[i][0] = b;
    //         x[i][1] = a;
    //     }
    //     resortedV.push_back(x[i]);
    //     i+=2;
    // }
    // merge_sort_vector_pairs(0, resortedV.size() - 1);
    // for (unsigned int i = 0; i < unsortedV.size(); i++)
    // {
    //     sortedV.push_back(unsortedV[i][0]);
    //     sortedV.push_back(unsortedV[i][1]);
    // }
    //task3: merge lower numbers of each pair then push_back the bigger (already sorted) numbers
    //merge_sort_vector(0, unsortedV.size() - 1);
    // for (unsigned int i = 0; i < unsortedV.size(); i++)
    // {
    //     sortedV.insert(std::lower_bound(sortedV.begin(), sortedV.end(), unsortedV[i][0]), unsortedV[i][0]);
    // }
    // for (unsigned int i = 0; i < unsortedV.size(); i++)
    // {
    //     sortedV.insert(std::lower_bound(sortedV.begin(), sortedV.end(), unsortedV[i][1]), unsortedV[i][1]);
    // }