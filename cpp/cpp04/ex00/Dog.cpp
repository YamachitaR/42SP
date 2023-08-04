/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 22:37:09 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/08/01 03:18:26 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void):Animal("Dog")
{
	std::cout << "Dog: Default constructor called" << std::endl;
}

Dog::Dog(std::string str):Animal(str)
{
	std::cout << "Dog: Constructor with parameter called" << std::endl;
}

Dog::Dog(Dog const &copy)
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
    std::cout << "Au au au au au" << std::endl;
}
