/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:41:50 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/08/01 03:17:51 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void):_type("Animal")
{
	std::cout << "Animal: Default constructor called" << std::endl;
}

Animal::Animal(std::string str):_type(str)
{
	std::cout << "Animal: Constructor with parameter called" << std::endl;
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

void Animal::makeSound(void) const
{
    std::cout << "Animal Animal Animal" << std::endl;
}

std::string Animal::getType(void)const
{
    return (this->_type);
}

void Animal::setType(std::string type)
{
    this->_type = type;
}