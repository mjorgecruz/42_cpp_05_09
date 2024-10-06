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

        class ConstIterator
        {
            private:
                ConstIterator();
                ConstIterator &operator= (ConstIterator &src);
            public:
                ConstIterator( const ConstIterator &src);
                ~ConstIterator();
                ConstIterator(const MutantStack<T>& stack, unsigned int initial_index );
                ConstIterator(const MutantStack<T>& stack); //for the .end function

                const T& operator*() const;
                ConstIterator& operator++();
                ConstIterator& operator--();
                ConstIterator& operator++( int );
                ConstIterator& operator-- ( int );
                bool operator==( const MutantStack<T>::ConstIterator& src) const;
                bool operator!=( const MutantStack<T>::ConstIterator & src) const;
                
            private:
                MutantStack<T> const & stack;
                unsigned int index;
                bool is_valid;
        };
        ConstIterator begin() const;
        ConstIterator end() const;

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

        class ConstRIterator
        {
            private:
                ConstRIterator();
                ConstRIterator &operator= (ConstRIterator &src);
            public:
                ConstRIterator( const ConstRIterator &src);
                ~ConstRIterator();
                ConstRIterator(const MutantStack<T>& stack, unsigned int initial_index );
                ConstRIterator(const MutantStack<T>& stack); //for the .end function

                const T& operator*() const;
                ConstRIterator& operator++();
                ConstRIterator& operator--();
                ConstRIterator& operator++( int );
                ConstRIterator& operator-- ( int );
                bool operator==( const MutantStack<T>::ConstRIterator& src) const;
                bool operator!=( const MutantStack<T>::ConstRIterator & src) const;
                
            private:
                MutantStack<T> const & stack;
                unsigned int index;
                bool is_valid;
        };
        ConstRIterator rbegin() const;
        ConstRIterator rend() const;



        typedef typename MutantStack<T>::Iterator iterator;
        typedef typename MutantStack<T>::ConstIterator const_iterator;
        typedef typename MutantStack<T>::RIterator reverse_iterator;
        typedef typename MutantStack<T>::ConstRIterator const_reverse_iterator;

};

#include "MutantStack.tpp"

#endif