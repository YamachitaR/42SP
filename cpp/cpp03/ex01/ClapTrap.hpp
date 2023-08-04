/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 03:22:43 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/07/23 01:57:32 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	protected:
		std::string _name;                                                                                         
		int _hitPoints; 
		int _energyPoints;
		int _attackDamage;
		
	public:
		ClapTrap(void);
		ClapTrap(ClapTrap const &claptrap);
		ClapTrap(std::string name);
		~ClapTrap(void);
		
		ClapTrap &operator=(ClapTrap const &rhs);

		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName (void) const;
		void setName(std::string const &name);
		
		int getHitPoints(void) const;
		void setHitPoints(int hitPoints);

		int getEnergyPoints(void) const;
		void setEnergyPoints(int points);

		int getAttackDamage(void) const;
		void setAttackDamage(int attack);
};

#endif