/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 02:55:52 by marvin            #+#    #+#             */
/*   Updated: 2024/10/06 02:55:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <sstream>

class RPN
{   
    public:
        RPN();
        ~RPN();
        RPN(RPN &src);
        RPN &operator=(RPN &src);

        static int parser(std::string line);
        void add_to_deque(std::string line);
        int calculate ( int result );
        static int switcher (int value, int placeholder, char signal);

    private:
        std::deque<int> numbers;
        std::deque<int> signals;

};


#endif