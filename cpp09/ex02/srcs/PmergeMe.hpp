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
#include <set>
#include <vector>
#include <algorithm>
#include <climits>
#include <string>
#include <sstream>

class PmergeMe
{   
    public:
        PmergeMe();
        ~PmergeMe();
        std::vector<int> vector_sort(int ac,char **av);
        void merge_sort_vector(unsigned int right, unsigned int left);
        void merge_vector(unsigned int left, unsigned int mid, unsigned int right);
        static bool compare (int const a[2], int const b[2]);

        std::set<int> set_sort(char **av);

    private:
        std::vector<int *> unsortedV;
        std::vector<int> sortedV;
        std::set<int> unsortedS;
        std::set<int> sortedS;

        PmergeMe(PmergeMe &src);
        PmergeMe &operator=(PmergeMe &src);

};


#endif