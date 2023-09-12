/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 05:46:50 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/09/08 02:09:36 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void):AAnimal()
{
	std::cout << "Cat: Default constructor called" << std::endl;
	this->_type = "Cat";
	this->_brain = new Brain();
}

Cat::Cat(Cat const &copy):AAnimal()
{
	std::cout << "Cat: Copy constructor called" << std::endl;
	this->_brain = new Brain(*copy._brain);
	*this = copy;
}

Cat::~Cat(void)
{
	std::cout << "Cat: Destructor called" << std::endl;
	delete this->_brain;
}

Cat &Cat::operator=(Cat const &rhs)
{
	std::cout << "Cat: Copy assignment operator" << std::endl;

	if (this != &rhs)
	{
		this->_type = rhs._type;
		this->_brain->setIdeas(rhs._brain->getIdeas());
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