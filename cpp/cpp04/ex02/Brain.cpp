/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 05:17:34 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/09/08 02:09:20 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain: Default constructor called" << std::endl;
	Brain::setSameIdeas("intrusive thinking");
} 

Brain::Brain(std::string str)
{
	std::cout << "Brain: Constructor with parameter type called" << std::endl;
	Brain::setSameIdeas(str);
}

Brain::Brain(Brain const &copy)
{
	std::cout << "Brain: Copy constructor called" << std::endl;
	*this = copy;
}

Brain::~Brain(void)
{
	std::cout << "Brain: Destructor called" << std::endl;
}

Brain &Brain::operator=(Brain const &rhs)
{
	std::cout << "Brain: Copy assignment operator" << std::endl;

	if (this != &rhs)
	{
		this->setIdeas(rhs._ideas);
	}
	return (*this);
}

std::string Brain::getIdea(int i) const 
{
	if (i > -1 && i < 100)
		return (this->_ideas[i]);
	return (NULL);
}

void Brain::setIdea(int i, std::string str) 
{
	if (i > -1 && i < 100)
		this->_ideas[i] = str;
}

const std::string *Brain::getIdeas(void) const
{
	return (this->_ideas);
}

void Brain::setIdeas(const std::string *str) 
{
	int i = -1;
	while(++i < 100)
		this->_ideas[i] = str[i];
}





void Brain::setSameIdeas(std::string str)
{
	int i;
	
	i = 0;
	while(i < 100)
	{
		this->_ideas[i] = str;
		i++;
	}
}

void Brain::sayIdeas(void) const
{
	int i;
	
	i = 0;
	while(i < 100)
	{
		std::cout << this->_ideas[i] << std::endl;
		i++;
	}
}