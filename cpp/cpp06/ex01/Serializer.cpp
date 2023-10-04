/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:46:02 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/03 17:09:01 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"


Serializer::Serializer(void){
	std::cout << "Serializer: Default constructor called" << std::endl;
}


Serializer::Serializer(Serializer const &copy)
{
	std::cout << "Serializer: Copy constructor called" << std::endl;
	*this = copy;
}

Serializer::~Serializer(void)
{
	std::cout << "Serializer: Destructor called" << std::endl;
}

Serializer &Serializer::operator=(Serializer const &rhs)
{
	std::cout << "Serializer: Copy assignment operator" << std::endl;

	if (this != &rhs)
	{
		(void)rhs; 
	}
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
	return(reinterpret_cast<uintptr_t>(ptr));	
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return(reinterpret_cast<Data*>(raw));
}