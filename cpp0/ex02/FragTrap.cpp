/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:53:52 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/07/25 00:19:24 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void): ClapTrap()
{
	std::cout << "FragTrap: Default constructor called" << std::endl;
	this->_name = "FragTrap";
	this->_hitPoints = 100;
	this->_attackDamage = 30;
	this->_energyPoints = 100;
}

FragTrap::FragTrap(std::string name):FragTrap()
{
	std::cout << "FragTrap: Constructor with parameter name called" << std::endl;
	
	this->_name = name;
}

FragTrap::FragTrap(FragTrap const &fragtrap)
{
	std::cout << "FragTrap: Copy constructor called" << std::endl;
	*this = fragtrap;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap: Destructor called" << std::endl;
}


FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	std::cout << "FragTrap: Copy assignment operator" << std::endl;

	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_attackDamage = rhs._attackDamage;
		this->_energyPoints = rhs._energyPoints;
	}
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	if(this->_hitPoints > 0)
		std::cout << "FragTrap " << this->_name << " High Five" << std::endl;
	else
		std::cout << "FragTrap " << this->_name << " cannot High Five. Because " << this->_name << " is died." << std::endl;
}