/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:48:32 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/28 05:03:44 by ryoshio-         ###   ########.fr       */
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
#include <string>
#include <map>

struct Date;

class BitcoinExchange{
	private:
		std::map<std::string, float> _dataBase;
	
		bool _checkValueBitcoin(float value);
		bool _checkValue(std::string str, std::string price);
		bool _checkRangeDate(Date date);
		bool _initData(std::string str);
		float _calcValue(std::string date, float value);
		
	public: 
		BitcoinExchange(void); 	
		~BitcoinExchange(void); 	
		
		bool exchange(char *str);
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
bool isDate(Date date);

Date atd(std::string str);
Date today(void);

std::string strtrim(const std::string& str);

bool isInteger(std::string str);
bool isFloat(const std::string str);

bool errorMessage(std::string str);

#endif

