/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:41:55 by masoares          #+#    #+#             */
/*   Updated: 2024/10/04 16:54:04 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "MutantStack.hpp"

template < typename T > MutantStack<T>::MutantStack(){}

template < typename T > MutantStack<T>::~MutantStack()
{} 

template < typename T > MutantStack<T>::MutantStack(MutantStack<T> &src) : std::stack<T>(src)
{}

template < typename T > MutantStack<T> & MutantStack<T>::operator= (MutantStack<T> &src)
{}

template < typename T >  typename MutantStack<T>::Iterator MutantStack<T>::begin()
{
    Iterator result = Iterator(*this, 0);
    return result;
}

template < typename T >  typename MutantStack<T>::Iterator MutantStack<T>::end()
{
    Iterator result = Iterator(*this);
    return result;

}

template < typename T > T&  MutantStack<T>::at(unsigned int index)
{
    if (index >= this->size())
        throw std::out_of_range("Invalid Index");
    return *this[index];
}

//Iterator

template <typename T> MutantStack<T>::Iterator::Iterator(const Iterator& src)
    : stack(src.stack), index(src.index) {}

template < typename T > MutantStack<T>::Iterator::Iterator(MutantStack& stack, unsigned int initial_index ):
stack(stack), index(initial_index), is_valid(true)
{
    if (initial_index >= stack.size())
        is_valid = false;
}

template < typename T > MutantStack<T>::Iterator::Iterator(MutantStack& stack):
stack(stack), index(0), is_valid(false)
{}

template < typename T > MutantStack<T>::Iterator::~Iterator()
{}

template < typename T > T& MutantStack<T>::Iterator::operator*()
{
    if (!this->is_valid)
        throw std::out_of_range("Dereferencing Invalid Iterator");
    return stack.at(index);
}

template < typename T >  typename MutantStack<T>::Iterator& MutantStack<T>::Iterator::operator++()
{
    if (!this->is_valid)
        return *this;
    ++index;
    if (index >= stack.size())
        is_valid = false;
    return *this;
}

template < typename T >  typename MutantStack<T>::Iterator& MutantStack<T>::Iterator::operator--()
{
    if (!this->is_valid)
        return *this;
    --index;
    if (index >= stack.size())
        is_valid = false;
    return *this;
}

template < typename T >  bool MutantStack<T>::Iterator::operator==(MutantStack<T>::Iterator const & src)
{
    if ((this->is_valid == true && src.is_valid == true && this->stack == src.stack && this->index == src.index ) || (src.is_valid == false && this->is_valid == false))
        return true;
    return false;
}

template < typename T >  bool MutantStack<T>::Iterator::operator!=(MutantStack<T>::Iterator const & src)
{
    return !(*this == src);
}

/* 
Writing an Iterator
https://www.youtube.com/watch?v=fCNR9a_Vmls

*/