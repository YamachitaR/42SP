/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimalnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:41:50 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/08/01 20:44:10 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal: Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(std::string str):_type(str)
{
	std::cout << "WrongAnimal: Constructor with parameter called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &copy)
{
	std::cout << "WrongAnimal: Copy constructor called" << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal: Destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs)
{
	std::cout << "WrongAnimal: Copy assignment operator" << std::endl;

	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal WrongAnimal" << std::endl;
}

std::string WrongAnimal::getType(void)const
{
    return (this->_type);
}

void WrongAnimal::setType(std::string type)
{
    this->_type = type;
}