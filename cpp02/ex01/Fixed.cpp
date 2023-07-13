/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 02:19:47 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/07/13 19:18:22 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixed_point = 0;
}

Fixed::Fixed(const int nbr)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point = nbr << _fractional_bits;
}

Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point = (int) roundf(nbr * (1 << this->_fractional_bits));
}

Fixed::Fixed(Fixed const &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
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

float Fixed::toFloat(void) const
{
	return (this->_fixed_point / float(1 << this->_fractional_bits));
}


int Fixed::toInt(void) const
{
	return(this->_fixed_point >> this->_fractional_bits);
}

std::ostream &operator<<(std::ostream &o, Fixed const &fixed)
{
	o << fixed.toFloat();
	return (o);
} 