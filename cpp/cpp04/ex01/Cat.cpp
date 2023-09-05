/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 03:21:00 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/08/04 21:03:27 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

#include "Brain.hpp"

Cat::Cat(void):Animal()
{
	std::cout << "Cat: Default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(std::string str):Animal(str)
{
	std::cout << "Cat: Constructor with parameter type called" << std::endl;
	this->_brain = new Brain();
}

Cat::Cat(Cat const &copy):Animal()
{
	std::cout << "Cat: Copy constructor called" << std::endl;
	*this = copy;
}

Cat::~Cat(void)
{
	std::cout << "Cat: Destructor called" << std::endl;
}


Cat &Cat::operator=(Cat const &rhs)
{
	std::cout << "Cat: Copy assignment operator" << std::endl;

	if (this != &rhs)
	{
		this->_type = rhs._type;
		this->_brain = rhs._brain;
	}
	return (*this);
}

void Cat::makeSound(void) const
{
	std::cout << "meow meow meow meow!" << std::endl;
}

Brain *Cat::getBrain(void) const
{
	return(this->_brain);
}

void Cat::setBrain(Brain brain)
{
	this->_brain = &brain;
}
