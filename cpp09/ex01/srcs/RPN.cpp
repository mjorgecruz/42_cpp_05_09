/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 02:55:32 by marvin            #+#    #+#             */
/*   Updated: 2024/10/06 02:55:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(RPN &src)
{
    data = src.data;
}

RPN & RPN::operator=(RPN &src)
{
    data = src.data;
    return *this;
}

int RPN::parser( std::string line )
{
    std::string partial_line;
    std::stringstream X(line);

    while (getline(X, partial_line, ' '))
    {
        //check for brackets and any other symbol
        if (partial_line[0] != '+' && partial_line[0] != '-' && partial_line[0] != '*' && partial_line[0] != '/' && partial_line[0] < '0' &&  partial_line[0] < '9')
        {
            std::cerr << "Error" << std::endl;
            return -1;
        }
        //check for decimals
        if (partial_line.size() > 1)
        {
            std::cerr << "Error" << std::endl;
            return -1;
        }
    }
    return 1;
}

void RPN::add_to_queue (std::string line)
{
    std::string partial_line;
    std::stringstream X(line);

    while (getline(X, partial_line, ' '))
    {
        this->data.push(partial_line[0]);
    }
}

int  RPN::calculate ( void )
{
    int value = (this->data.front()) - '0';
    if (value < 0 || value > 9)
    {
        std::cerr << "Error" << std::endl;
        return (-1); 
    }
    this->data.pop();
    int placeholder;
    char signal;
    while (!this->data.empty())
    {   
        placeholder = (this->data.front()) - '0';
        if (placeholder < 0 || placeholder > 9)
        {
            std::cerr << "Error" << std::endl;
            return (-1); 
        }
        this->data.pop();
        signal = this->data.front();
        if (signal != '+' && signal != '-' && signal != '*' && signal != '/')
        {
            std::cerr << "Error" << std::endl;
            return -1;
        }
        value = RPN::switcher(value, placeholder, signal);
        std::cout << value << std::endl;
        this->data.pop();
    }
    return value;
}

int RPN::switcher(int value, int placeholder, char signal)
{
    switch(signal)
    {
        case '*':
            value = value * placeholder;
            break;
        case '/':
            value = value / placeholder;
            break;
        case '+':
            value = value + placeholder;
            break;
        case '-':
            value = value - placeholder;
            break;
        break;
    }
    return (value);

}