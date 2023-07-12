/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Check.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 17:39:47 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/07/12 14:18:37 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Check.hpp"

Check::Check(int argc, char **argv)
{
	_checkArgc(argc);
	_fileExist(argv[1]);
	if(std::string(argv[2]).empty() || std::string(argv[3]).empty())
	{
		std::cout << "Argument is empty!" << std::endl;
		exit(1);
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
		exit(1);
	}
}

void Check::_fileExist(char *file)
{
	std::ifstream fd;
	
	fd.open(file);
	if(fd.fail())
	{
		std::cout << "The file does not exist!" << std::endl;
		exit(1);
	}
	fd.close();
}
