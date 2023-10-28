/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:48:32 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/27 21:17:45 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BitcoinExchange_HPP
#define BitcoinExchange_HPP

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype>
#include <ctime>

struct Date;

class BitcoinExchange{
	private:
		bool _checkValueBitcoin(float value);
		bool _checkValueDate(std::string str);
		bool _checkRangeDate(Date date);
		
	public: 
		BitcoinExchange(void); 	
		~BitcoinExchange(void); 	
};


struct Date {
    int year;
    int month;
    int day;
};


bool checkArgc(const int argc);
bool checkFile(const char  *file);

bool isLeapYear(const int year);
bool isMonth(const int month);
bool isDate(int year, int month, int day);
Date atd(std::string str);
Date today(void);

bool isInteger(std::string str);

bool errorMessage(std::string str);

#endif

