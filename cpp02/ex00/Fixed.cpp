/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 02:19:47 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/07/13 04:36:27 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixed_point = 0;
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;

	//this é um ponteiro implícito que aponta para o objeto atual em que um método está sendo executado. 
	//Ele é usado para acessar os membros (variáveis ou métodos) de um objeto dentro do próprio objeto.	
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixed_point = fixed.getRawBits();
	return(*this);
}

int Fixed::getRawBits(void)const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->_fixed_point);
}
		
void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawbits member function called" << std::endl;
	this->_fixed_point = raw;
}