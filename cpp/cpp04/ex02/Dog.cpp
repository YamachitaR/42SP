/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 05:04:28 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/09/08 02:00:19 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void):AAnimal()
{
	std::cout << "Dog: Default constructor called" << std::endl;
	this->_type= "Dog";
	this->_brain = new Brain();
}

Dog::Dog(Dog const &copy):AAnimal()
{
	std::cout << "Dog: Copy constructor called" << std::endl;
	this->_brain = new Brain();
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
		this->_brain->setIdeas(rhs._brain->getIdeas());
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