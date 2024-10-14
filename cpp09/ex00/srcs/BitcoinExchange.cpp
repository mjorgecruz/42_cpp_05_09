/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masoares <masoares@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 11:41:55 by masoares          #+#    #+#             */
/*   Updated: 2024/10/14 16:18:36 by masoares         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{

}

BitcoinExchange::~BitcoinExchange()
{

}

BitcoinExchange::BitcoinExchange(BitcoinExchange &src)
{
    (void)src;
}

BitcoinExchange & BitcoinExchange::operator=(BitcoinExchange &src)
{
    (void) src;
    return *this;
}

void   BitcoinExchange::dataParser(std::string doc)
{
    std::string line;
    std::string partial;
    time_t date;
    float   rate;

    std::ifstream file(doc.c_str());
    if (file.is_open())
    {
        while(getline(file, line))
        {
            if (line.find("date") != std::string::npos)
                continue;

            //getting date in int format
            std::stringstream X(line);
            getline(X, partial, ',');
            date = parseDateTime(partial.c_str());

            if (date == -1)
                continue;
            getline(X, partial, ',');
            rate = strtof(partial.c_str(), NULL);
            this->data[date] = rate;
        }
    }
    
}

void BitcoinExchange::textParser(std::string doc)
{
    std::string line;
    std::string partial_date;
    std::string partial_value;

    time_t date;
    float value;

    std::ifstream file(doc.c_str());
    if (file.is_open())
    {
        while(getline(file, line))
        {
            if (line.find("date") != std::string::npos ||  line.empty())
                continue;

            //getting date in int format
            std::stringstream X(line);
            getline(X, partial_date, '|');
            date =  BitcoinExchange::parseDateTime(partial_date.c_str());
            if (date == -1)
                continue;
            getline(X, partial_value, '|');
            value = strtof(partial_value.c_str(), NULL);
            if (value == 0 && partial_value != "0" && partial_value != "+0" && partial_value != "-0")
                std::cerr << "Error: not a number." << std::endl;
            else if (value < 0)
                std::cerr << "Error: not a positive number." << std::endl;
            else if (value > 1000.0)
                std::cerr << "Error: too large a number." << std::endl;
            else
            {
                std::map<time_t, float>::iterator it = data.lower_bound(date);
                /*The function returns an iterator pointing to the key in the map container which is equivalent to k passed in the parameter.
                 In case k is not present in the map container, the function returns an iterator pointing to the immediate next element which is just greater than k.*/
                if (it == data.begin())
                {
                    std::cerr << "Error: data not available." << std::endl;
                    continue;
                }
                it--;
                partial_date.erase(std::remove_if(partial_date.begin(), partial_date.end(), isspace), partial_date.end());
                std::cout << partial_date << "=> " << value << " = " << it->second * value << std::endl;
            }
        }
    }
    else
    {
        std::cerr << "Error: could not open file" << std::endl;
        return;
    }
}

// function to parse a date or time string.
time_t BitcoinExchange::parseDateTime(const char* datetimeString)
{
    struct tm tmStruct;
    int year;
    if (std::sscanf(datetimeString, "%d-%d-%d ", &year, &tmStruct.tm_mon, &tmStruct.tm_mday) != 3)
    {
        std::cerr << "Error: bad input =>" << datetimeString << std::endl;
        return (-1);
    }
    tmStruct.tm_mon-=1;
    tmStruct.tm_year = year - 1900;
    tmStruct.tm_hour = 0;
    tmStruct.tm_min = 0;
    tmStruct.tm_sec = 0;

    if(check_valid_date(tmStruct))
    {
        return mktime(&tmStruct);
    }
    else
    {
        std::cerr << "Error: bad input =>" << datetimeString << std::endl;
        return (-1);
    }
}

int BitcoinExchange::check_valid_date(struct tm tmStruct)
{
    int year = 1900 + tmStruct.tm_year;
    if (tmStruct.tm_mon < 0 || tmStruct.tm_mon > 11)
        return 0;
    if (tmStruct.tm_mday < 1 || tmStruct.tm_mday > 31)
        return 0;
    if (tmStruct.tm_mon == 3 || tmStruct.tm_mon == 5 || tmStruct.tm_mon == 8 || tmStruct.tm_mon == 10)
    {
        if (tmStruct.tm_mday < 1 || tmStruct.tm_mday > 30)
            return 0;
    }
    if (tmStruct.tm_mon == 1)
    {
        if (is_leap_year(year))
        {
            if (tmStruct.tm_mday < 1 || tmStruct.tm_mday > 29)
                return 0;
        }
        else
        {
            if (tmStruct.tm_mday < 1 || tmStruct.tm_mday > 28)
                return 0;
        }
    }
    return 1;
}

int BitcoinExchange::is_leap_year(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 4 == 0 && year % 100 == 0 && year % 400 == 0))     
        return 1;
    return 0;
}