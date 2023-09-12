/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:21:11 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/08/04 22:12:30 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>

PhoneBook::PhoneBook(void)
{
	this->_new = -1;
	this->_amount = 0;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

void PhoneBook::_message(int n)
{
	if(n == 0)
		std::cout << "Enter the first name:";
	else if	(n == 1)
		std::cout << "Enter the last name:";
	else if	(n == 2)
		std::cout << "Enter the nickname:";
	else if	(n == 3)
		std::cout << "Enter the phone number:";
	else
		std::cout << "Enter the darkest descret:";
}

int PhoneBook::_check(int n, std::string s)
{
	if(n == 0)
		return(_check_string(s));
	else if	(n == 1)
		return(_check_string(s));
	else if	(n == 2)
		return(_check_string(s));
	else if	(n == 3)
		return(_check_number(s));
	else
		return(_check_string(s));
	return (1);
}

int PhoneBook::_check_string(std::string s)
{	
	long unsigned int i;

	if(s == "")
		return (0);
	i = 0;
	while (s[i])
	{
		if(s[i] == '\t')
			s[i] = ' ';
		i ++;
	}
	i = 0;
	while (s[i] == ' ')
		i ++;
	if(i == s.length())
		return (0);
	return (1);
}

int PhoneBook::_check_number(std::string s)
{
	int i;
	
	if(_check_string(s) == 0)
		return (0);
	i = 0;
	while(s[i])
	{
		if(s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	PhoneBook::_atoi(std::string s)
{
	int i;
	int nbr;
	
	if(_check_number(s) == 0)
		return (-1);
	i = 0;
	nbr = 0;
	while(s[i])
	{
		nbr = nbr*10 + (s[i] - '0');
		i++;
	}
	return (nbr);
}

void PhoneBook::add(void)
{	
	std::string data[5];
	int	i;
	
	i = 0;
	std::cin.ignore();
	while(i < 5)
	{		
		_message(i);
		std::getline(std::cin, data[i]);
		i += _check(i, data[i]);
	}
	if( this->_new == -1 || this->_new == 8)
		this->_new = 0;
	this->_contacts[this->_new].setContact(data);
	if(this->_amount != 8)
		this->_amount++;
	this->_new++;
}

void PhoneBook::search(void)
{
	int i;
	std::string	input;
	
	if(this->_new == -1)
	{
		std::cout << "Phonebook has no contacts!" << std::endl;
		return ;
	}
	std::cout << "|Index     |First name|Last name |Nickname  |" << std::endl;
	i = 0;
	while( i < this->_amount)
	{
		std::cout << "|" << i + 1 << "         |";
		this->_contacts[i].printSearch();
		std::cout << std::endl;
		i ++;
	}
	while(1)
	{
		std::cout << "Enter index:";
		std::cin >> input;
		i = _atoi (input);
		if(i > 0 && i <= this->_amount)
			break;
		std::cout << input << ":Invalid index" << std::endl;
	}
	this->_contacts[i - 1].printContact();
}