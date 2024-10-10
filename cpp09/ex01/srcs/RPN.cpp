/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 02:55:32 by marvin            #+#    #+#             */
/*   Updated: 2024/10/10 16:09:43 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "RPN.hpp"

RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(RPN &src)
{
    numbers = src.numbers;
}

RPN & RPN::operator=(RPN &src)
{
    numbers = src.numbers;
    return *this;
}

int RPN::parser( std::string line )
{
    std::string partial_line;
    std::stringstream X(line);

    while (getline(X, partial_line, ' '))
    {
        //check for brackets and any other symbol
        if (partial_line[0] != '+' && partial_line[0] != '-' && partial_line[0] != '*' && partial_line[0] != '/' && partial_line[0] < '0' &&  partial_line[0] > '9')
        {
            std::cerr << "Error" << std::endl;
            return -1;
        }
        //check for decimals
        if (partial_line.find(".") != std::string::npos || partial_line.find(",") != std::string::npos )
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
    std::stack<int> temp;
    int value;
    char signal;
    int result = 0;

    while (getline(X, partial_line, ' '))
    {
        value = atoi(partial_line.c_str());
        signal = partial_line[0];
        if (value == 0 && partial_line.size() == 1 &&(signal == '+' || signal == '-' || signal == '*' || signal == '/'))
        {
            if (numbers.size() < 2)
                throw RPN::UnbalanceNumbersSymbolsException();
            result = this->calculate( signal );
            numbers.push(result);
        }
        else if ((value >= -9 && value <= 9))
            numbers.push(value);
        else
        {
            std::cerr << "Error" << std::endl;
            return; 
        }
    }
    if (numbers.size() > 1)
        throw RPN::UnbalanceNumbersSymbolsException();
    std::cout << numbers.top() << std::endl;
}

int  RPN::calculate ( char signal )
{
    int result = 0;
    int value1 = numbers.top();
    this->numbers.pop();
    int value2 = numbers.top();
    this->numbers.pop();

    result = RPN::switcher(value2, value1, signal);
    return result;
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

const char * RPN::UnbalanceNumbersSymbolsException::what() const throw()
{
    return ("Error");
}