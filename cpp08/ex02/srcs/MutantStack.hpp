/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:57:07 by masoares          #+#    #+#             */
/*   Updated: 2024/10/04 16:56:38 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <stack>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <ctime>
#include <iostream>


template <typename T> 
class MutantStack: public std::stack<T>
{
    private:
        MutantStack<T> &operator= (MutantStack<T> &src);
    public:
        MutantStack(MutantStack<T> &src);
        MutantStack();
        ~MutantStack();
        T& at(unsigned int index);

        class Iterator
        {
            private:
                Iterator();
                Iterator &operator= (Iterator &src);
            public:
                Iterator( const Iterator &src);
                ~Iterator();
                Iterator(MutantStack<T>& stack, unsigned int initial_index );
                Iterator(MutantStack<T>& stack); //for the .end function

                T& operator*();
                Iterator& operator++();
                Iterator& operator--();
                bool operator==(MutantStack<T>::Iterator const & src);
                bool operator!=(MutantStack<T>::Iterator const & src);
                
            private:
                MutantStack<T>& stack;
                unsigned int index;
                bool is_valid;
        };
        Iterator begin();
        Iterator end();

        typedef typename MutantStack<T>::Iterator iterator;

};

#include "MutantStack.tpp"

#endif