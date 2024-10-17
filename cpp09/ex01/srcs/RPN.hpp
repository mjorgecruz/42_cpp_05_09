/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 02:55:52 by marvin            #+#    #+#             */
/*   Updated: 2024/10/17 12:13:29 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#pragma once
#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <queue>
#include <stack>
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
        void add_to_queue(std::string line);
        double calculate ( char signal );
        static double switcher (double value, double placeholder, char signal);

        class UnbalanceNumbersSymbolsException : public std::exception
        {
            const char *what() const throw();
        };

    private:
        std::stack<double> numbers;
};


#endif