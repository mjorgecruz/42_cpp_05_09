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
    numbers = src.numbers;
    signals = src.signals;
}

RPN & RPN::operator=(RPN &src)
{
    numbers = src.numbers;
    signals = src.signals;
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
    int value;
    char signal;
    int result = 0;

    getline(X, partial_line, ' ');
    value = partial_line[0] - '0';
    if (value < 0 || value > 9)
    {
        std::cerr << "Error" << std::endl;
        return; 
    }
    result = value;

    while (getline(X, partial_line, ' '))
    {
        value = partial_line[0] - '0';
        signal = partial_line[0];
        if (signals.empty() && (value >= 0 && value <= 9))
        {
            this->numbers.push(value);
        }
        else if ((signal == '+' || signal == '-' || signal == '*' || signal == '/') && signals.size() < numbers.size())
        {
            this->signals.push(partial_line[0]);
        }
        else if (!signals.empty() && (value >= 0 && value <= 9))
        {
            try 
            {
                result = this->calculate(result);
            }
            catch( std::exception &e)
            {
                std::cerr << e.what() << std::endl;
                return;
            }
            this->numbers.push(value);
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return; 
        }
    }
    try 
    {
        result = this->calculate(result);
        std::cout << result << std::endl;
    }
    catch( std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return;
    }
}

int  RPN::calculate ( int result )
{
    int value = (this->numbers.front());
    this->numbers.pop();
    
    while (!numbers.empty())
    {
        if (signals.empty())
            throw RPN::UnbalanceNumbersSymbolsException();
        value = RPN::switcher(value, numbers.front(), signals.front());
        this->numbers.pop();
        this->signals.pop();
    }
    result = RPN::switcher(result, value, signals.front());
    this->signals.pop();
    if (!signals.empty())
    {
        throw RPN::UnbalanceNumbersSymbolsException();
    }
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