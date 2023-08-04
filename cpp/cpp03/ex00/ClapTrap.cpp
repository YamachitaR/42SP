/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 03:22:38 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/07/23 00:15:05 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void):_name("Default"),  _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name):_name(name),  _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "Constructor with parameter name called" << std::endl;
}


ClapTrap::ClapTrap(ClapTrap const &claptrap)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = claptrap;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "Destructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	std::cout << "Copy assignment operator" << std::endl;
	if (this != &rhs)
	{
		this->setName(rhs.getName());
		this->setAttackDamage(rhs.getAttackDamage());
		this->setEnergyPoints(rhs.getEnergyPoints());
		this->setHitPoints(rhs.getHitPoints());
	}
	return (*this);
}

std::string ClapTrap:: getName (void) const
{
	return (this->_name);
} 

void ClapTrap::setName(std::string const &name)
{
	this->_name = name; 
}


int ClapTrap::getHitPoints(void) const
{
	return (this->_hitPoints);
}

void ClapTrap::setHitPoints(int hitPoints)
{
	if(hitPoints >= 0)
		this->_hitPoints = hitPoints;
	else
		std::cout << "Value received is not valid, therefore it will not be changed." << std::endl;

		
}

int ClapTrap::getEnergyPoints(void) const
{
	return (this->_energyPoints);
}

void ClapTrap::setEnergyPoints(int points)
{
	if ( points >= 0)
		this->_energyPoints = points;
	else
		std::cout << "Value received is not valid, therefore it will not be changed." << std::endl;
}


int ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}

void ClapTrap::setAttackDamage(int attack)
{
	if( attack >= 0)
		this->_attackDamage = attack;
	else
		std::cout << "Value received is not valid, therefore it will not be changed." << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if(this->getEnergyPoints() > 0 && this->getHitPoints() > 0)
	{
		std::cout << "ClapTrap " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		this->setEnergyPoints(this->getEnergyPoints() - 1);
	}
	else
	{
		if (this->getHitPoints() <= 0)
			std::cout << "ClapTrap " << this->getName() << " cannot attack because "<< this->getName()  << " is dead." << std::endl;
		else
			std::cout << "ClapTrap "  << this->getName() << " cannot attack because "<< this->getName()  << " has no energy." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	int points;

	if(this->getHitPoints() <= 0)
	{
		std::cout <<  "ClapTrap "  << this->getName() << " is died!" << std::endl;
		return;
	}
	
	if ((int)amount < 0)
	{
		std::cout << "ClapTrap " << getName() << " received an invalid damage amount." << std::endl;	
		return;
	}	

	points = this->getHitPoints() - (int)amount;
	if (points <= 0)
		this->setHitPoints(0);
	else
		this->setHitPoints(points);
	std::cout << "ClapTrap "  << this->getName() << " took " << amount << " damage. Remaining hit points: " << this->getHitPoints() << std::endl;
	if (this->getHitPoints() == 0)
		std::cout <<  "ClapTrap "  << this->getName() << " died!" << std::endl;
		
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if((int)amount <= 0)
	{
		std::cout << "ClapTrap " << getName() << " received an invalid repair amount." << std::endl;
		return;
	}
	if (getHitPoints() <= 0)
		std::cout << "ClapTrap " << this->getName() << " cannot repair because "<< this->getName()  << " is dead." << std::endl;
	else if (getEnergyPoints() <= 0)
		std::cout << "ClapTrap "  << this->getName() << " cannot repair because "<< this->getName()  << " has no energy." << std::endl;
	else
	{
		this->setEnergyPoints(this->getEnergyPoints() - 1);
		this->setHitPoints(this->getHitPoints() + amount);
		std::cout << "ClapTrap " << this->getName() << " repairs " << amount << ", causing " << this->getHitPoints() << " hit points!" << std::endl;
	}
}