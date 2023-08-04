/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 02:19:47 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/07/15 02:19:29 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
	this->_fixed_point = 0;
}

Fixed::Fixed(const int nbr)
{
	this->_fixed_point = nbr << _fractional_bits;
}

Fixed::Fixed(const float nbr)
{
	this->_fixed_point = (int) roundf(nbr * (1 << this->_fractional_bits));
}

Fixed::Fixed(Fixed const &copy)
{
	*this = copy;
}

Fixed::~Fixed(void)
{
	return;
}

Fixed &Fixed::operator=(Fixed const &fixed)
{
	this->_fixed_point = fixed.getRawBits();
	return(*this);
}

bool Fixed::operator>(Fixed const &fixed) const
{
	 return(this->_fixed_point > fixed.getRawBits());
}

bool Fixed::operator<(Fixed const &fixed) const
{
	 return(this->_fixed_point < fixed.getRawBits());
}

bool Fixed::operator>=(Fixed const &fixed) const
{
	 return(this->_fixed_point >= fixed.getRawBits());
}

bool Fixed::operator<=(Fixed const &fixed) const
{
	 return(this->_fixed_point <= fixed.getRawBits());
}

bool Fixed::operator==(Fixed const &fixed) const
{
	 return(this->_fixed_point == fixed.getRawBits());
}

bool Fixed::operator!=(Fixed const &fixed) const
{
	 return(this->_fixed_point != fixed.getRawBits());
}

Fixed Fixed::operator+(Fixed const &fixed) const
{
	return (Fixed(this->toFloat()+ fixed.toFloat()));
}

Fixed Fixed::operator-(Fixed const &fixed) const
{
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*(Fixed const &fixed) const
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(Fixed const &fixed) const
{
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

Fixed Fixed::operator-(void)
{	
	return (Fixed(-1*this->toFloat()));
}

Fixed Fixed::operator+(void)
{	
	return (Fixed(this->toFloat()));
}


Fixed Fixed::operator++(void)
{
	++this->_fixed_point;	
	return (Fixed(this->toFloat()));
}

Fixed Fixed::operator--(void)
{
	--this->_fixed_point;	
	return (Fixed(this->toFloat()));
}

Fixed Fixed::operator++(int)
{
	float  tmp;
	
	tmp =  this->toFloat();
	this->_fixed_point ++;	
	return (Fixed(tmp));
}

Fixed Fixed::operator--(int)
{
	float  tmp;
	
	tmp =  this->toFloat();
	this->_fixed_point --;	
	return (Fixed(tmp));
}

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	if(fixed1 < fixed2)
		return (fixed1);
	return(fixed2);
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	if(fixed1 > fixed2)
		return (fixed1);
	return(fixed2);
}

Fixed const &Fixed::min(Fixed const &fixed1, Fixed const &fixed2)
{
	if(fixed1 < fixed2)
		return (fixed1);
	return(fixed2);
}

Fixed const &Fixed::max(Fixed const &fixed1, Fixed const &fixed2)
{
	if(fixed1 > fixed2)
		return (fixed1);
	return(fixed2);
}

int Fixed::getRawBits(void)const
{
	return(this->_fixed_point);
}
		
void Fixed::setRawBits(int const raw)
{
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
