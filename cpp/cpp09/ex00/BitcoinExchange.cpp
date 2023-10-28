/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:48:20 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/27 21:34:20 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void){
	std::string s= "2022-08-09";
	
	if(_checkValueDate(s))
		std::cout << "BitcoinExchange: Default constructor called" << std::endl;
}

BitcoinExchange::~BitcoinExchange(void){
	std::cout << "BitcoinExchange: Destructor called" << std::endl;
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


bool BitcoinExchange::_checkValueDate(std::string str){
	size_t firstDash;
	size_t secondDash;
	std::string year;
	std::string month;
	std::string day;

	firstDash = str.find('-');
	if(firstDash == std::string::npos)
		return (errorMessage("The date is not format correct!"));
	year = str.substr(0, firstDash);
	
	secondDash = str.find('-', firstDash + 1);
	if(secondDash == std::string::npos)
		return (errorMessage("The date is not format correct!"));
	
	month = str.substr(firstDash + 1, secondDash - firstDash - 1);
	day = str.substr(secondDash + 1);

	if(!isInteger(year) || !isInteger(month) || !isInteger(day))
		return (errorMessage("Date has a strange character!"));
	
	if(!isDate(std::atoi(year.c_str()), std::atoi(month.c_str()), std::atoi(day.c_str())))
		return (errorMessage("The date does not exist!"));

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

Date atd(std::string str){
	Date date;

	date.year= -1;
	date.month = -1;
    date.day = -1;
	
	if(str.size() == 10)
		return (date);
	else{
        // Se a data não estiver no formato esperado, defina os valores como -1

    }
	return(date);
}

/* 
Data extrairValoresData(const std::string& data) {
    Data dataExtraida;

    if (data.size() == 10 && data[4] == '-' && data[7] == '-') {
        // Extrair o ano, mês e dia
        dataExtraida.ano = std::stoi(data.substr(0, 4));
        dataExtraida.mes = std::stoi(data.substr(5, 2));
        dataExtraida.dia = std::stoi(data.substr(8, 2));
    } else {
        // Se a data não estiver no formato esperado, defina os valores como -1
        dataExtraida.ano = -1;
        dataExtraida.mes = -1;
        dataExtraida.dia = -1;
    }

    return dataExtraida;
}
*/


bool checkArgc(const int argc){
	if(argc != 2)
		return (errorMessage("Wrong number of arguments.\n Usage: ./btc <file>"));
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

bool isDate(int year, int month, int day){
	int maxDay;
	
	if(!isMonth(month) || year < 0 || day < 1 || day > 31)
		return(false);
	
	if(month == 4 || month == 6 || month == 9 || month == 11)
		maxDay = 31;
	else if(month == 2){
		if(isLeapYear(year))
			maxDay = 29;
		else
			maxDay = 28;
	}
	else		
		maxDay = 30;
	
	if(day > maxDay)
		return(false);

		
	return(true);
}

bool isInteger(std::string str){
	size_t i;

	i = 0;
	while (i <  str.length()){
		if(!std::isdigit(str[i]))
			return (false);
		i ++;
	}
	return (true);
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