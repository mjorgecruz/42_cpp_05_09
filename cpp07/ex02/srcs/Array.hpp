/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 10:57:07 by masoares          #+#    #+#             */
/*   Updated: 2024/09/30 12:04:30 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include <iostream>

template <typename T>
class Array
{
    private:
        T arr[];
    
    public:
        Array( void );
        ~Array( void );
        Array(Array &src);
        Array &operator= (Array &src);
        
        Array(unsigned int n);
        int size ( void );
        
};