/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:48:20 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/28 05:43:22 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void){
	_initData("data.csv");
	std::cout << "BitcoinExchange: Default constructor called" << std::endl;
}

BitcoinExchange::~BitcoinExchange(void){
	std::cout << "BitcoinExchange: Destructor called" << std::endl;
}

bool BitcoinExchange::_initData(std::string str){
	std::ifstream	ifs;
	size_t 			pos;
	std::string		date, value, line;
	
	if(!checkFile(str.c_str()))
		return(errorMessage("data.csv ???"));

	ifs.open(str.c_str());
	
	while (std::getline(ifs, line)){
		pos	= line.find(',');
		date = line.substr(0, pos);
		value = line.substr(pos + 1);
		float rate = atof(value.c_str());
		this->_dataBase[date] = rate;
    }
	
	ifs.close();
	return (true);
}


bool BitcoinExchange::_checkValueBitcoin(float value){
	if(value < 0){
		std::cout << "Error: not a positive number." << std::endl;
		return (false);
	}
	if(value > 1000){
		std::cout << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);	
}

bool BitcoinExchange::_checkValue(std::string str, std::string price){
	Date date;

	date = atd(str);

	if(date.day == -1 || date.month == -1 || date.year == -1)
		return (errorMessage("The date format is not correct"));

	if(!isDate(date))
		return (errorMessage("The date does not exist."));

	if(!_checkRangeDate(date))
		return (errorMessage("The date is out of range."));

	if(!isFloat(price))
		return (errorMessage("The value is not correct"));
	
	if(!_checkValueBitcoin(atof(price.c_str())))
		return (false);
		
	return(true);
}

bool BitcoinExchange::_checkRangeDate(Date date){
	Date now = today();
	
	if(date.year < 2008 || date.year > now.year)
		return(false);
	
	if((date.year == 2008 && date.month < 10) || (date.year == 2008 && date.month == 10 && date.day != 31))
		return(false);
	
	if (date.year == now.year){
		if(date.month > now.month)
			return (false);
		if(date.month == now.month){
			if(date.day > now.day)
				return(false);
		}
	}
	return(true);
}

float	BitcoinExchange::_calcValue(std::string date, float value){
	std::map<std::string, float>::iterator	it;
	std::map<std::string, float>::iterator	next;
	
	it = _dataBase.find(date);
	if (it != _dataBase.end())
		return (it->second * value);
		
	it = _dataBase.begin();
	while ( it != _dataBase.end()){
		next = it;
		next++;
		if (((date >= it->first) && (next == _dataBase.end())) || ((date >= it->first) && (date < next->first)))
			return (it->second * value);
		it ++;
	}
	return (-1);
}

bool BitcoinExchange:: exchange(char *str){
	std::ifstream	ifs;
	size_t			pos;
	std::string		date, value, line;
	
	if(!checkFile(str))
		return(errorMessage("input file???"));

	ifs.open(str);
	
	std::getline(ifs, line);
	if (line != "date | value")
		return(errorMessage("Invalid format header."));
		
	while (std::getline(ifs, line)){
		if (line.find("|") == std::string::npos || line.empty())
			std::cout << "Error: bad input => " << line << std::endl;
		else
		{
			pos = line.find('|');
			date = strtrim(line.substr(0, pos));
			value = strtrim(line.substr(pos + 1));
			
			if(!_checkValue(date, value))
				continue;
			std::cout.precision(2);	
			std::cout << date << " => " << atof(value.c_str()) << " = " << _calcValue(date, atof(value.c_str())) << std::endl;
		}
	}
	return(true);
}






Date atd(std::string str){
	Date date;

	date.year = -1;
	date.month = -1;
    date.day = -1;
	
	if (str[4] != '-' && str[7] != '-') 
		return (date);
    if(isInteger(str.substr(0, 4)))
		date.year = std::atoi(str.substr(0, 4).c_str());
	if(isInteger(str.substr(5, 2)))
		date.month = std::atoi(str.substr(5, 2).c_str());
	if(isInteger(str.substr(8, 2)))
		date.day = std::atoi(str.substr(8, 2).c_str());
	return(date);
}



bool checkArgc(const int argc){
	if(argc != 2)
		return (errorMessage("could not open file.\nUsage: ./btc <file>"));
	return (true);
}

bool checkFile(const char  *file){
	std::ifstream fd;
	
	fd.open(file);
	if(fd.fail())
		return(errorMessage("Not found file"));

	if(fd.peek()==EOF){
		fd.close();
		return(errorMessage("file is empty"));
	}
	
	fd.close();
	
	return(true);
}


bool isLeapYear(const int year){
	if(year % 4 == 0 && year % 100 != 0)
		return(true);
	if(year % 400 == 0)
		return(true);
	return(false);
}

bool isMonth(const int month){
	if(month < 1 || month > 12)
		return(false);
	return(true); 
}

bool isDate(Date date){
	int maxDay;
	
	if(!isMonth(date.month) || date.year < 0 || date.day < 1 || date.day > 31)
		return(false);
	
	if(date.month == 4 || date.month == 6 || date.month == 9 || date.month == 11)
		maxDay = 31;
	else if(date.month == 2){
		if(isLeapYear(date.year))
			maxDay = 29;
		else
			maxDay = 28;
	}
	else		
		maxDay = 30;
	
	if(date.day > maxDay)
		return(false);
	
	return(true);
}

bool isInteger(std::string str){
	size_t i;

	i = 0;
	
	if(str.empty())
		return(false);
		
	while (i <  str.length()){
		if(!std::isdigit(str[i]))
			return (false);
		i ++;
	}
	return (true);
}

bool isFloat(const std::string str){
	size_t i;
	int point;

	if(isInteger(str))
		return(true);
	
	if(str.empty())
		return(false);
		
	i = 0;
	if(str[i] == '+' || str[i] == '-'){
		i ++;
		if(!std::isdigit(str[i]))
			return (false);
		i ++;
	}
	point = 0; 	
	while (i <  str.length()){
		if(str[i] == '.' )
			point ++;
		if(!std::isdigit(str[i]))
			return (false);
		i ++;
	}

	if(point > 1)
		return (false);
		
	return(true);
}




Date today(void)
{
	time_t	timeUnix; 
	tm*		localTime;
	
	Date day;

	timeUnix = time(0);
	localTime = localtime(&timeUnix);
	day.day = localTime->tm_mday;
	day.month = localTime->tm_mon + 1; 
	day.year = localTime->tm_year + 1900;

	return (day);
}


bool errorMessage(std::string str){
	std::cout << "Error: " << str << std::endl;
	return(false);
}

std::string strtrim(const std::string& str) {
    size_t start;
    size_t end;

	start = 0;
	end =  str.size();

	if(end == 0)
		return ("NULL");
	
    while (start < end && std::isspace(str[start])) {
        start++;
    }

	while (end > start && str[end - 1] == '\n'){
        end--;
    }
    while (end > start && std::isspace(str[end - 1])) {
        end--;
    }
    return str.substr(start, end - start);
}