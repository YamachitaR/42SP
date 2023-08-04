/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 03:21:00 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/08/01 03:29:04 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void):Animal("Cat")
{
	std::cout << "Cat: Default constructor called" << std::endl;
}

Cat::Cat(std::string str):Animal(str)
{
	std::cout << "Cat: Constructor with parameter called" << std::endl;
}

Cat::Cat(Cat const &copy)
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
	}
	return (*this);
}

void Cat::makeSound(void) const
{
    std::cout << "Meow meow meow" << std::endl;
}