/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replace.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 02:24:11 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/07/12 14:51:12 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replace.hpp"

Replace::Replace(char *s, char *s1, char *s2)
{
	std::string text;
	
	text = _readAll(s);
	_replace(text, std::string(s1), std::string(s2));
	_newFile(text, std::string(s) + ".replace");
}

Replace::~Replace(void)
{
	return;
}

std::string Replace::_readAll(char *file)
{
	std::ifstream fd;
	std::string text;
	std::string line;

	fd.open(file);
	while(std::getline(fd, line))
		text += line + "\n";	
	fd.close();
	if(text.empty())
	{
		std::cout << "The file is empty!" << std::endl;
		exit(1);
	}
	return (text);
}


void Replace:: _newFile(std::string s, std::string name)
{
	std::ofstream fd;
	
	fd.open(name);
	if(fd.fail())
	{
		std::cout << "Error creating file!" << std::endl;
		exit(1);
	}
	fd << s;
	fd.close();
}


void Replace::_replace(std::string &text, std::string old_str, std::string new_str)
{
	size_t position;
	
	if (old_str.compare(new_str) == 0)
	{
		std::cout << "Warning: Replacement arguments have same values!" << std::endl;
		return;
	}
	position = text.find(old_str);
	if(position == std::string::npos)
	{
		std::cout << "Warning:"<< old_str << " is not found!" << std::endl;
		return;
	}
	while(position != std::string::npos)
	{
		text = text.substr(0, position) + new_str + text.substr(position + old_str.length());
		position = text.find(old_str, position + new_str.length());
	}
}