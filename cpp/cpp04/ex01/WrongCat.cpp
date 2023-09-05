/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 03:21:00 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/08/04 21:04:55 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void):WrongAnimal("Cat")
{
	std::cout << "WrongCat: Default constructor called" << std::endl;
}

WrongCat::WrongCat(std::string str):WrongAnimal(str)
{
	std::cout << "WrongCat: Constructor with parameter called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &copy):WrongAnimal( )
{
	std::cout << "WrongCat: Copy constructor called" << std::endl;
	*this = copy;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat: Destructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs)
{
	std::cout << "WrongCat: Copy assignment operator" << std::endl;

	if (this != &rhs)
	{
		this->_type = rhs._type;
	}
	return (*this);
}

void WrongCat::makeSound(void) const
{
    std::cout << "Meow meow meow" << std::endl;
}