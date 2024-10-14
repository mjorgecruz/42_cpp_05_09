/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 02:55:52 by marvin            #+#    #+#             */
/*   Updated: 2024/10/06 02:55:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <sstream>
#include <cstdlib>
#include <iomanip>

class PmergeMe
{   
    public:
        PmergeMe();
        ~PmergeMe();

        std::vector<int> vector_sort(int ac,char **av);
        void merge_sort_vector_pairs(unsigned int right, unsigned int left);
        void merge_vector_pairs(unsigned int left, unsigned int mid, unsigned int right);
        void galloping_merge_vector(std::vector<int>& sortedV, int element);
        std::vector<int>::iterator lower_bound_vector(std::vector<int>::iterator begin, std::vector<int>::iterator end, int element);

        std::deque<int> set_sort(int ac, char **av);
        void merge_sort_set_pairs(unsigned int right, unsigned int left);
        void merge_set_pairs(unsigned int left, unsigned int mid, unsigned int right);
        void galloping_merge_set(std::deque<int>& sortedS, int element);
        std::deque<int>::iterator lower_bound_deque(std::deque<int>::iterator begin, std::deque<int>::iterator end, int element);




    private:
        std::vector<int> sortedV;
        std::deque<int> sortedS;
        std::vector<int *> unsortedV;
        std::deque<int *> unsortedS;

        PmergeMe(PmergeMe &src);
        PmergeMe &operator=(PmergeMe &src);

};

// template <typename T>
// class  PmergeMe
// {
//     private:
//         T sorted;
//         T unsorted;
    
//     public:
//         T set_sort(int ac, char **av);
//         void merge_sort_set_pairs(unsigned int right, unsigned int left);
//         void merge_set_pairs(unsigned int left, unsigned int mid, unsigned int right);
//         void galloping_merge_set(T& sortedS, int element);

// };

#endif