/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/05 23:53:37 by marvin            #+#    #+#             */
/*   Updated: 2024/10/05 23:53:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <string>
#include <sstream>  

class BitcoinExchange
{   
    public:
        BitcoinExchange();
        ~BitcoinExchange();
        BitcoinExchange(BitcoinExchange &src);
        BitcoinExchange &operator=(BitcoinExchange &src);

        void dataParser (std::string file);
        void textParser(std::string doc);
        
        static time_t parseDateTime(const char* datetimeString);
        static int check_valid_date(struct tm tmStruct);
        static int is_leap_year(int year);


    private:
        std::map <time_t, float> data;

};


#endif