/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 05:04:28 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/09/07 05:55:55 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void):Animal()
{
	std::cout << "Dog: Default constructor called" << std::endl;
	this->_type= "Dog";
}

Dog::Dog(Dog const &copy):Animal()
{
	std::cout << "Dog: Copy constructor called" << std::endl;
	*this = copy;
}

Dog::~Dog(void)
{
	std::cout << "Dog: Destructor called" << std::endl;
}


Dog &Dog::operator=(Dog const &rhs)
{
	std::cout << "Dog: Copy assignment operator" << std::endl;

	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Woof woof woof!" << std::endl;
}