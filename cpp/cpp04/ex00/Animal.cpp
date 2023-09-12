/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 05:32:16 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/09/08 02:04:15 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal: Default constructor called" << std::endl;
	this->_type= "Animal";
}

Animal::Animal(std::string str)
{
	std::cout << "Animal: Constructor with parameter type called" << std::endl;
	this->_type = str;
}

Animal::Animal(Animal const &copy)
{
	std::cout << "Animal: Copy constructor called" << std::endl;
	*this = copy;
}

Animal::~Animal(void)
{
	std::cout << "Animal: Destructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &rhs)
{
	std::cout << "Animal: Copy assignment operator" << std::endl;

	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

std::string Animal::getType(void) const
{
	return (this->_type);
}

void Animal::setType(std::string type)
{
	this->_type = type;
}

void Animal::makeSound(void) const
{
	std::cout << "ANIMAL SOUND!" << std::endl;
}
