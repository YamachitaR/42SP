/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:26:01 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/03 16:26:41 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <ctime>

void testInt(void)
{
	std::string numArray = "0123456789";
	std::string s;
	int i = 0;
	int j = 0;
	
	std::srand(std::time(0));
	std::cout << "======| Test Int |=====" << std::endl;
	while(j < 10){
		i = 0;
		if(rand()%2)
			s += "-"; 
		while(i < 7){
			s += numArray[rand()%9];
			i++;
		}
		std::cout << "-----------------------------"<< std::endl;
		std::cout << "Value  => " << s << std::endl;
		ScalarConverter::convert(s);
		s = "";
		j++;
	}
}

void testFloat(void)
{
	std::string numArray = "0123456789";
	std::string s;
	int i = 0;
	int j = 0;
	
	std::srand(std::time(0));
	std::cout << "======| Test Float |=====" << std::endl;
	while(j < 10){
		i = 0;
		if(rand()%2)
			s += "-"; 
		while(i < 7){
			s += numArray[rand()%9];
			i++;
		}
		s[rand()%7] = '.';
		s += "f";
		std::cout << "------------------------------"<< std::endl;
		std::cout << "Value  => " << s << std::endl;
		ScalarConverter::convert(s);
		s = "";
		j++;
	}
}


void testDouble(void)
{
	std::string numArray = "0123456789";
	std::string s;
	int i = 0;
	int j = 0;
	
	std::srand(std::time(0));
	std::cout << "======| Test Double |=====" << std::endl;
	while(j < 10){
		i = 0;
		if(rand()%2)
			s += "-"; 
		while(i < 7){
			s += numArray[rand()%9];
			i++;
		}
		s[rand()%7] = '.';
		std::cout << "-------------------"<< std::endl;
		std::cout << "Value  => " << s << std::endl;
		ScalarConverter::convert(s);
		s = "";
		j++;
	}
}

void testPseudo(void)
{
	std::string s; 
	std::cout << "======| Pseudo Literals |=====" << std::endl;
	
	s="+inff";
	std::cout << "Value  => " << s << std::endl;
	ScalarConverter::convert(s);
	std::cout << "-------------------"<< std::endl;
	s="-inff";
	std::cout << "Value  => " << s << std::endl;
	ScalarConverter::convert(s);
	std::cout << "-------------------"<< std::endl;
	s="nanf";
	std::cout << "Value  => " << s << std::endl;
	ScalarConverter::convert(s);
	std::cout << "-------------------"<< std::endl;
	s="+inf";
	std::cout << "Value  => " << s << std::endl;
	ScalarConverter::convert(s);
	std::cout << "-------------------"<< std::endl;
	s="-inf";
	std::cout << "Value  => " << s << std::endl;
	ScalarConverter::convert(s);
	std::cout << "-------------------"<< std::endl;
	s="nan";
	std::cout << "Value  => " << s << std::endl;
	ScalarConverter::convert(s);
	
}

int main (void)
{
	testInt();
	std::cout << "====|end|===" << std::endl;
	testFloat();
	std::cout << "====|end|===" << std::endl;
	testDouble();
	std::cout << "====|end|===" << std::endl;
	testPseudo();
}

