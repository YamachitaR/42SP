/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 00:55:34 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/07/24 19:43:32 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void): ClapTrap()
{
	std::cout << "ScavTrap: Default constructor called" << std::endl;
	this->_name = "ScavTrap";
	this->_hitPoints = 100;
	this->_attackDamage = 20;
	this->_energyPoints = 50;
}

ScavTrap::ScavTrap(std::string name):ScavTrap()
{
	std::cout << "ScavTrap: Constructor with parameter name called" << std::endl;
	
	this->_name = name;
}

ScavTrap::ScavTrap(ScavTrap const &scavtrap)
{
	std::cout << "ScavTrap: Copy constructor called" << std::endl;
	*this = scavtrap;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap: Destructor called" << std::endl;
}


ScavTrap &ScavTrap::operator=(ScavTrap const &rhs)
{
	std::cout << "ScavTrap: Copy assignment operator" << std::endl;

	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_attackDamage = rhs._attackDamage;
		this->_energyPoints = rhs._energyPoints;
	}
	return (*this);
}





void ScavTrap::guardGate(void)
{
	if(this->_hitPoints > 0)
		std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
	else
		std::cout << "ScavTrap " << this->_name << " cannot guard Gate. Because " << this->_name << " is died." << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if(this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
	{
		std::cout << "ScavTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
	else
	{
		if (this->getHitPoints() <= 0)
			std::cout << "ScavTrap " << this->getName() << " cannot attack because "<< this->getName()  << " is dead." << std::endl;
		else
			std::cout << "ScavTrap "  << this->getName() << " cannot attack because "<< this->getName()  << " has no energy." << std::endl;
	}
}