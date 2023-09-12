/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 05:32:16 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/09/08 01:58:39 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << "AAnimal: Default constructor called" << std::endl;
	this->_type= "AAnimal";
}

AAnimal::AAnimal(std::string str)
{
	std::cout << "AAnimal: Constructor with parameter type called" << std::endl;
	this->_type = str;
}

AAnimal::AAnimal(AAnimal const &copy)
{
	std::cout << "AAnimal: Copy constructor called" << std::endl;
	*this = copy;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal: Destructor called" << std::endl;
}


AAnimal &AAnimal::operator=(AAnimal const &rhs)
{
	std::cout << "AAnimal: Copy assignment operator" << std::endl;

	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

std::string AAnimal::getType(void) const
{
	return (this->_type);
}

void AAnimal::setType(std::string type)
{
	this->_type = type;
}
