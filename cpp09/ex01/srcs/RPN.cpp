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

void RPN::add_to_deque (std::string line)
{
    std::string partial_line;
    std::stringstream X(line);
    int value;
    char signal;
    //int placeholder;
    int result = 0;

    getline(X, partial_line, ' ');
    std::cout << partial_line << std::endl;
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
        if (signals.empty() && (value > 0 && value < 9))
        {
            this->numbers.push_back(value);
            std::cout << value << std::endl;
        }
        else if (signal == '+' && signal == '-' && signal == '*' && signal == '/' && signals.size() < numbers.size())
        {
            this->signals.push_back(partial_line[0]);
            std::cout << partial_line[0] << std::endl;
        }
        else if (!signals.empty() && (value >= 0 && value <= 9))
        {
            std::cout << std::endl;
            result = this->calculate(result);
            this->numbers.push_back(value);
        }
        else
        {
            std::cerr << "Error" << std::endl;
            return; 
        }
    }
    std::cout << result << std::endl;
}

int  RPN::calculate ( int result )
{
    int value = (this->numbers.front());
    this->numbers.pop_front();
    
    while (!numbers.empty())
    {
        value = RPN::switcher(value, numbers.front(), signals.back());
        this->numbers.pop_front();
        this->signals.pop_back();
    }
    result = RPN::switcher(result, value, signals.back());
    this->signals.pop_back();

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

/*while(getline(X, partial_line, ' '))
        {
            std::cout << partial_line << std::endl;
            value = partial_line[0] - '0';
            if (value < 0 || value > 9)
            {
                this->signals.push_back(partial_line[0]);
                break;
            }
            this->numbers.push_back(value);
        }
        if (errno = EOF)
        {
            std::cerr << "Error" << std::endl;
            break;
        }
        while(getline(X, partial_line, ' '))
        {
            signal = partial_line[0];
            if (signal != '+' && signal != '-' && signal != '*' && signal != '/')
            {
                placeholder = partial_line[0] - '0';
                break;
            }
            this->signals.push_back(signal);
            if (signals.size() > numbers.size())
            {
                std::cerr << "Error" << std::endl;
                return; 
            }
        }
        if (signals.size() != numbers.size())
        {
            std::cerr << "Error" << std::endl;
            return; 
        }
        result = this->calculate(result);
        if (errno = EOF)
            break;
        this->numbers.push_back(placeholder);*/