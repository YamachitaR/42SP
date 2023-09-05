/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 22:37:09 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/08/04 21:03:03 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Dog.hpp"

Dog::Dog(void):Animal()
{
	std::cout << "Dog: Default constructor called" << std::endl;
	this->_type= "Dog";
	this->_brain = new Brain();
}

Dog::Dog(std::string str):Animal(str)
{
	std::cout << "Dog: Constructor with parameter type called" << std::endl;
	this->_brain = new Brain();
}

Dog::Dog(Dog const &copy):Animal()
{
	std::cout << "Dog: Copy constructor called" << std::endl;
	*this = copy;
}

Dog::~Dog(void)
{
	std::cout << "Dog: Destructor called" << std::endl;
	delete	this->_brain;
}


Dog &Dog::operator=(Dog const &rhs)
{
	std::cout << "Dog: Copy assignment operator" << std::endl;

	if (this != &rhs)
	{
		this->_type = rhs._type;
		this->_brain = rhs._brain;
	}
	return (*this);
}

void Dog::makeSound(void) const
{
	std::cout << "Woof woof woof!" << std::endl;
}

Brain *Dog::getBrain(void) const
{
	return(this->_brain);
}

void Dog::setBrain(Brain brain)
{
	this->_brain = &brain;
}
