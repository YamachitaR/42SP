/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Check.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:39:47 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/08/04 22:45:59 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Check.hpp"

Check::Check(int argc, char **argv)
{
	this->_ok = 1;
	
	_checkArgc(argc);
	if(this->_ok == 0)
		return ;
			
	_fileExist(argv[1]);
	if(this->_ok == 0)
		return ;

	if(std::string(argv[2]).empty() || std::string(argv[3]).empty())
	{
		std::cout << "Argument is empty!" << std::endl;
		this->_ok = 0;
	}
}

Check::~Check(void)
{
	return;
}

void Check::_checkArgc(int argc)
{
	if(argc !=  4)
	{
		std::cout << "Amount of argument is wrong!" << std::endl;
		this->_ok = 0;
	}
}

void Check::_fileExist(char *file)
{
	std::ifstream fd;
	
	fd.open(file);
	if(fd.fail())
	{
		std::cout << "The file does not exist!" << std::endl;
		this->_ok = 0;
	}
	else
		fd.close();
}

int Check::getOk(void)
{
	return (this->_ok);
}