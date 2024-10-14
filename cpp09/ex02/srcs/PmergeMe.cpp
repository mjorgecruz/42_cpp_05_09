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
    merge_sort_vector_pairs(0, unsortedV.size() - 1);
    for (unsigned int i = 0; i < unsortedV.size(); i++)
    {
        sortedV.push_back(unsortedV[i][1]);
        galloping_merge_vector(sortedV, unsortedV[i][0]);
    }
    if (av[i])
        sortedV.insert(lower_bound_vector(sortedV.begin(), sortedV.end(), atoi(av[i])), atoi(av[i]));
    return sortedV;
}

void PmergeMe::galloping_merge_vector(std::vector<int>& sortedV, int element)
{
    int len = sortedV.size();
    int i = 1;
    while (i < len && sortedV[i] < element) {
        i *= 2;
    }
    int left = i / 2;
    int right = std::min(i, len);
    sortedV.insert(lower_bound_vector(sortedV.begin() + left, sortedV.begin() + right, element), element);
}

void PmergeMe::merge_sort_vector_pairs( unsigned int left, unsigned int right)
{
    if (left >= right)
        return;

    unsigned int mid = left + (right - left) / 2;
    merge_sort_vector_pairs( left, mid );
    merge_sort_vector_pairs( mid + 1, right);
    merge_vector_pairs(left, mid, right);
}

void PmergeMe::merge_vector_pairs(unsigned int left, unsigned int mid, unsigned int right)
{
    int space1 = mid - left + 1;
    int space2 = right - mid;

    std::vector<int *> L(space1);
    std::vector<int *> R(space2);

    for (int i = 0; i < space1; i++)
    {
        L[i] = unsortedV[left + i];
    }
    for (int i = 0; i < space2; i++)
    {
        R[i] = unsortedV[mid + 1 + i];
    }   

    int i = 0;
    int j = 0;
    int k = left;
    while (i < space1 && j < space2)
    {
        if (L[i][1] <= R[j][1])
        {
            unsortedV[k] = L[i];
            i++;
        }
        else
        {
            unsortedV[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < space1)
    {
        unsortedV[k] = L[i];
        i++;
        k++;
    }
    while (j < space2)
    {
        unsortedV[k] = R[j];
        j++;
        k++;
    }
}

std::vector<int>::iterator PmergeMe::lower_bound_vector(std::vector<int>::iterator begin, std::vector<int>::iterator end, int element)
{
    if (begin >= end)
        return begin;
    std::vector<int>::iterator it = begin + (end - begin) / 2;
    if (element == *it)
        return it;
    else if (element > *it)
        it = lower_bound_vector(it + 1, end, element);
    else
        it = lower_bound_vector(it, begin, element);
    return it;
}

std::deque<int> PmergeMe::set_sort(int ac, char **av)
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
        unsortedS.push_back(x[i]);
        i+=2;
    }
    merge_sort_set_pairs(0, unsortedS.size() - 1);
    for (unsigned int i = 0; i < unsortedS.size(); i++)
    {
        sortedS.push_back(unsortedS[i][1]);
        galloping_merge_set(sortedS, unsortedS[i][0]);
    }
    if (av[i])
        sortedS.insert(lower_bound_deque(sortedS.begin(), sortedS.end(), atoi(av[i])), atoi(av[i]));
    return sortedS;
}

void PmergeMe::galloping_merge_set(std::deque<int>& sortedS, int element)
{
    int len = sortedS.size();
    int i = 1;
    int prev = 0;
    int temp = 0;
    while (i < len && sortedS[i] < element) {
        temp = i;
        i = i + 2 * prev;
        prev = temp;
    }
    int left = i / 2;
    int right = std::min(i, len);
    sortedS.insert(lower_bound_deque(sortedS.begin() + left, sortedS.begin() + right, element), element);
}

void PmergeMe::merge_sort_set_pairs( unsigned int left, unsigned int right)
{
    if (left >= right)
        return;

    unsigned int mid = left + (right - left) / 2;
    merge_sort_set_pairs( left, mid );
    merge_sort_set_pairs( mid + 1, right);
    merge_set_pairs(left, mid, right);
}

void PmergeMe::merge_set_pairs(unsigned int left, unsigned int mid, unsigned int right)
{
    int space1 = mid - left + 1;
    int space2 = right - mid;

    std::deque<int *> L(space1);
    std::deque<int *> R(space2);

    for (int i = 0; i < space1; i++)
    {
        L[i] = unsortedS[left + i];
    }
    for (int i = 0; i < space2; i++)
    {
        R[i] = unsortedS[mid + 1 + i];
    }   

    int i = 0;
    int j = 0;
    int k = left;
    while (i < space1 && j < space2)
    {
        if (L[i][1] <= R[j][1])
        {
            unsortedS[k] = L[i];
            i++;
        }
        else
        {
            unsortedS[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < space1)
    {
        unsortedS[k] = L[i];
        i++;
        k++;
    }
    while (j < space2)
    {
        unsortedS[k] = R[j];
        j++;
        k++;
    }
}

std::deque<int>::iterator  PmergeMe::lower_bound_deque(std::deque<int>::iterator begin, std::deque<int>::iterator end, int element)
{
    if (begin >= end)
        return begin;
    std::deque<int>::iterator it = begin + (end - begin) / 2;
    if (element == *it)
        return it;
    else if (element > *it)
        it = lower_bound_deque(it + 1, end, element);
    else
        it = lower_bound_deque(it, begin, element);
    return it;
}

// void PmergeMe::merge_sort_vector( std::vector<int> &sorted, std::vector<int *> left, int pos)
// {

//     if (left.size() == 0)
//         return;
//     if (left.size() == 1)
//     {
//         sorted.insert(sorted.begin(), left[0][0]);
//         return;
//     }
//     std::vector<int> left_sorted;
//     std::vector<int> right_sorted;
//     std::vector<int *> left_pairs( left.begin(), left.begin() + left.size()/2);
//     std::vector<int *> right_pairs( left.begin() + left.size()/2, left.end());

//     merge_sort_vector(left_sorted, left_pairs);
//     merge_sort_vector(right_sorted, right_pairs);
//     merge_vector(left_sorted, right_sorted, sorted);
// }

// void PmergeMe::merge_vector(std::vector<int> left_sorted, std::vector<int> right_sorted, std::vector<int> &sorted)
// {
  
//     unsigned int i = 0;
//     unsigned int j = 0;

//     while (i < left_sorted.size() && j < right_sorted.size())
//     {
//         if (left_sorted[i] <= right_sorted[j])
//         {
//             sorted.push_back(left_sorted[i]);
//             i++;
//         }
//         else
//         {
//             sorted.push_back(right_sorted[j]);
//             j++;
//         }
//     }
//     while (i < left_sorted.size())
//     {
//         sorted.push_back(left_sorted[i]);
//         i++;
//     }
//     while (j < right_sorted.size())
//     {
//         sorted.push_back(right_sorted[j]);
//         j++;
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