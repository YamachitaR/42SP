/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 05:46:50 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/07/27 05:48:14 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void):WrongAnimal("WrongCat")
{
	std::cout << "WrongCat: Default constructor called" << std::endl;
	this->_brain = new Brain();
}

WrongCat::WrongCat(WrongCat const &copy):WrongAnimal()
{
	std::cout << "WrongCat: Copy constructor called" << std::endl;
	this->_brain = new Brain();
	*this = copy;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat: Destructor called" << std::endl;

	delete this->_brain;
}


WrongCat &WrongCat::operator=(WrongCat const &rhs)
{
	std::cout << "WrongCat: Copy assignment operator" << std::endl;

	if (this != &rhs)
	{
		this->_type = rhs._type;
		*this->_brain = *rhs._brain;
	}
	return (*this);
}

void WrongCat::makeSound(void) const
{
	std::cout << "WrongCat sound!" << std::endl;
}


Brain *WrongCat::getBrain(void) const
{
	return(this->_brain);
}

void WrongCat::setBrain(Brain brain)
{
	
	this->_brain = &brain;	
}	