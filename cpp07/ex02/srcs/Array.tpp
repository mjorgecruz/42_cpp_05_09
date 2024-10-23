/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:41:55 by masoares          #+#    #+#             */
/*   Updated: 2024/10/08 10:14:18 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Array.hpp"

template < typename T > Array<T>::Array( void )
{
    arr = new T[0];
    _size = 0;
};

template < typename T > Array<T>::~Array( void )
{
    delete[] arr;
};

template < typename T > Array<T>::Array( Array &src )
{
    _size = src.size();
    arr = new T[_size];
    *this = src;

};

template < typename T > Array<T>& Array<T>::operator= (Array &src)
{
    if (this == &src)
	    return (*this);
    unsigned int t = src.size();
    T *temp = new T[t];
    for(unsigned int i = 0; i < t; i++ )
    {
        temp[i] = src.arr[i];
    }
    delete[] this->arr;
    this->arr = temp;
    return(*this);
};

template < typename T > Array<T>::Array(unsigned int n)
{
    arr = new T[n];
    _size = n;
}
template < typename T > unsigned int Array<T>::size( void ) const
{
    return(_size);
}

template < typename T > T&  Array<T>::operator[](unsigned int i)
{
    if (i >= (this->size()))
         throw std::out_of_range("Index out of range");
    return this->arr[i];
}

template < typename T >
const T& Array<T>::operator [](unsigned int i) const
{
    if (i >= (this->size()))
         throw std::out_of_range("Index out of range");
    return this->arr[i];
}