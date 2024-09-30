/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:41:55 by masoares          #+#    #+#             */
/*   Updated: 2024/09/30 16:30:13 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "Array.hpp"

template < typename T > Array<T>::Array( void )
{
    arr = new T[1];
};

template < typename T > Array<T>::~Array( void )
{
    delete[] arr;
};

template < typename T > Array<T>::Array( Array &src )
{
    unsigned int temp = src.size();
    arr = new T[temp];
    *this = src;

};

template < typename T > Array<T>& Array<T>::operator= (Array &src)
{
    if (this == &src)
	    return (*this);
    if (this->size() != src.size())
        throw Array::DifferentArrDimensionsExcetion();
    unsigned int temp = src.size();
    
    for(unsigned int i = 0; i < temp; i++ )
    {
        arr[i] = src.arr[i];
    }
    return(*this);
};

template < typename T > Array<T>::Array(unsigned int n)
{
    arr = new T[n];
}
template < typename T > unsigned int Array<T>::size( void )
{
    unsigned int c = 0;
    while (this->arr[c])
    {
   		c++;
    }
    return(c);
}

template < typename T > T&  Array<T>::operator[](unsigned int i)
{
    if (i < 0 || i > this->size())
        throw std::exception();
    return this->arr[i];
}

template < typename T >const char *Array<T>::DifferentArrDimensionsExcetion::what() const throw()
{
    return ("Arrays are of different dimenstions");
}