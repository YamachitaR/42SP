/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:21:04 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/05/26 17:07:39 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Contact.hpp"
#include <iostream>

void Contact::setContact(std::string s[5])
{
	this->_first_name = s[0];
	this->_last_name = s[1];
	this->_nickname = s[2];
	this->_phone_numeber = s[3];
	this->_darkest_secret = s[4];
}

void Contact::printContact(void)
{
	std::cout << "First name:" << this->_first_name << std::endl;
	std::cout << "Last name:" << this->_last_name << std::endl;
	std::cout << "Nickname:" << this->_nickname << std::endl;
	std::cout << "Phone number:" << this->_phone_numeber << std::endl;
	std::cout << "Darkest secret:" << this->_darkest_secret << std::endl;
}

void Contact::_printDisplay(std::string s)
{
	int i;

	i = 0;
	while(i < 9)
	{
		if(i < s.length())
		{
			if(s[i] == '\t')
				std::cout << " ";
			else
				std::cout << char(s[i]);
		}
		else
			std::cout << " ";
		i ++;
	}
	if(10 == s.length())
		std::cout << char(s[9]) << "|";
	else if(10 < s.length())
		std::cout << ".|";
	else
		std::cout << " |";
}

void Contact::printSearch(void)
{
	_printDisplay(this->_first_name);
	_printDisplay(this->_last_name);
	_printDisplay(this->_nickname);
}
