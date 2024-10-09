/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:57:07 by masoares          #+#    #+#             */
/*   Updated: 2024/10/09 10:35:54 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <list>
#include <algorithm>
#include <limits.h>
#include <cmath>
#include <ctime>
#include <iostream>

/*
template <typename T>
class MutantStack : public std::stack<T> {
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

    // Return the iterator to the beginning of the stack
    iterator begin() { return this->c.begin(); }
    // Return the iterator to the end of the stack
    iterator end() { return this->c.end(); }

    // Return the iterator to the beginning of the stack
    const_iterator cbegin() { return this->c.begin(); }
    // Return the iterator to the end of the stack
    const_iterator cend() { return this->c.end(); }

    // Return the iterator to the beginning of the stack
    reverse_iterator rbegin() { return this->c.rbegin(); }
    // Return the iterator to the end of the stack
    reverse_iterator rend() { return this->c.rend(); }

    // Return the iterator to the beginning of the stack
    const_reverse_iterator crbegin() { return this->c.rbegin(); }
    // Return the iterator to the end of the stack
    const_reverse_iterator crend() { return this->c.rend(); }
};

*/


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
                Iterator& operator++( int );
                Iterator& operator-- ( int );
                bool operator==(MutantStack<T>::Iterator const & src);
                bool operator!=(MutantStack<T>::Iterator const & src);
                
            private:
                MutantStack<T>& stack;
                unsigned int index;
                bool is_valid;
        };
        Iterator begin();
        Iterator end();
        class RIterator
        {
            private:
                RIterator();
                RIterator &operator= (RIterator &src);
            public:
                RIterator( const RIterator &src);
                ~RIterator();
                RIterator(MutantStack<T>& stack, unsigned int initial_index );
                RIterator(MutantStack<T>& stack); //for the .end function

                T& operator*();
                RIterator& operator++();
                RIterator& operator--();
                RIterator& operator++( int );
                RIterator& operator-- ( int );
                bool operator==(MutantStack<T>::RIterator const & src);
                bool operator!=(MutantStack<T>::RIterator const & src);
                
            private:
                MutantStack<T>& stack;
                unsigned int index;
                bool is_valid;
        };
        RIterator rbegin();
        RIterator rend();

        typedef typename MutantStack<T>::Iterator iterator;
        typedef typename MutantStack<T>::RIterator reverse_iterator;

};

#include "MutantStack.tpp"

#endif