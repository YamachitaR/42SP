/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 03:21:57 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/08/04 23:20:49 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"


void orthodox_canonical_form(void) 
{
	std::cout << "===|Orthodox Canonical Form!|===" << std::endl;	
	
	ClapTrap a("Ricardo");
	ClapTrap b( a );
	ClapTrap c;
	c = b;
	
	std::cout << "Name a:" << a.getName() << std::endl;
	std::cout << "Name b:" << b.getName() << std::endl;
	std::cout << "Name c:" << c.getName() << std::endl;
	
	std::cout << "Hit Pointer a:" << a.getHitPoints() << std::endl;
	std::cout << "Hit Pointer b:" << b.getHitPoints() << std::endl;
	std::cout << "Hit Pointer c:" << c.getHitPoints() << std::endl;

	std::cout << "Attack Damage a:" << a.getAttackDamage() << std::endl;
	std::cout << "Attack Damage b:" << b.getAttackDamage() << std::endl;
	std::cout << "Attack Damage c:" << c.getAttackDamage() << std::endl;

	std::cout << "Energy Points a:" << a.getEnergyPoints() << std::endl;
	std::cout << "Energy Points b:" << b.getEnergyPoints() << std::endl;
	std::cout << "Energy Points c:" << c.getEnergyPoints() << std::endl;
}


void test_get_set(void)
{
	std::string change_name;
	int change_hit;
	int change_attack;
	int change_energy;
	
	std::cout << "===|TEST: get and set|===" << std::endl;
	
	ClapTrap a;

	std::cout << "getName :" << a.getName() << std::endl;
	std::cout << "getHitPointer :" << a.getHitPoints() << std::endl;
	std::cout << "getAttackDamage:" << a.getAttackDamage() << std::endl;
	std::cout << "getEnergyPoints:" << a.getEnergyPoints() << std::endl;
	
	change_name = "Ricardo";
	change_hit = 90;
	change_attack = 25;
	change_energy = 96;
	
	a.setName(change_name);
	a.setAttackDamage(change_attack);
	a.setEnergyPoints(change_energy);
	a.setHitPoints(change_hit);
	
	std::cout << "After set (change value)" << std::endl;
	std::cout << "getName :" << a.getName() << std::endl;
	std::cout << "getHitPointer :" << a.getHitPoints() << std::endl;
	std::cout << "getAttackDamage:" << a.getAttackDamage() << std::endl;
	std::cout << "getEnergyPoints:" << a.getEnergyPoints() << std::endl;

	if(a.getName().compare(change_name) != 0)
		std::cout << "|Wrong get or set:name|" << std::endl;
	if(a.getAttackDamage() != change_attack)
		std::cout << "|Wrong get or set:Attack Damage|" << std::endl;
	if(a.getHitPoints() != change_hit)
		std::cout << "|Wrong get or set:Hit point|" << std::endl;
	if(a.getEnergyPoints() != change_energy)
		std::cout << "|Wrong get or set:Energy Point|" << std::endl;
	
	std::cout << "Changed to an incorrect value" << std::endl;

	change_hit = -90;
	change_attack = -25;
	change_energy = -96;
	
	a.setAttackDamage(change_attack);
	a.setEnergyPoints(change_energy);
	a.setHitPoints(change_hit);
	
	std::cout << "After set (change value)" << std::endl;
	std::cout << "getHitPointer :" << a.getHitPoints() << std::endl;
	std::cout << "getAttackDamage:" << a.getAttackDamage() << std::endl;
	std::cout << "getEnergyPoints:" << a.getEnergyPoints() << std::endl;
	
}

void test_attack(void)
{
	std::cout << "===|Test: method attack|===" << std::endl;
	ClapTrap a("Ricardo");
	ClapTrap b("42SP");

	std::cout << "=>Energy:" << a.getEnergyPoints() << std::endl;
	a.attack(b.getName());
	std::cout << "=>Energy after attack:" << a.getEnergyPoints() << std::endl;

	std::cout  << std::endl << "=>Change Damage" << std::endl;
	a.setAttackDamage(5);
	a.attack(b.getName());
	
	std::cout << std::endl << "=>Attack with energy:"  << std::endl;
	a.setEnergyPoints(0);
	a.attack(b.getName());

	std::cout  << std::endl << "=>Attack with hit points:" << std::endl;
	b.setHitPoints(0);
	b.attack(a.getName());
}

void test_take_damage(void)
{
	int damage;
	
	std::cout << "===|Test: method takeDamage|===" << std::endl;
	
	ClapTrap a("Ricardo");

	std::cout << std::endl << "=> Hit points: " << a.getHitPoints() <<std::endl;
	damage = 9;
	a.takeDamage(damage);
	std::cout << std::endl;
	
	damage = -9;
	std::cout << "=> putting incorrect value " << damage << std::endl;
	a.takeDamage(damage); 
	std::cout << std::endl;

	damage = 3;
	a.takeDamage(damage);
	std::cout << std::endl;
}

void test_beRepaired(void)
{
	std::cout << "===|Test: method beRepaired|===" << std::endl;
	
	ClapTrap a("Ricardo");
	std::cout << std::endl << "=> Hit points: " << a.getHitPoints() << std::endl;
	std::cout << "=> Energy points: " << a.getEnergyPoints() << std::endl;
	a.beRepaired(6);
	std::cout << "=> Hit points: " << a.getHitPoints() << std::endl;
	std::cout << "=> Energy points: " << a.getEnergyPoints() << std::endl;
	std::cout << std::endl;
	
	std::cout << std::endl << "=>Wrong Value " << std::endl;
	a.beRepaired(-6);
	std::cout << std::endl;

	std::cout << std::endl << "=>Died " << std::endl;
	a.setHitPoints(0);
	a.beRepaired(6);
	a.setHitPoints(10);
	std::cout << std::endl;

	std::cout << std::endl << "=> no energy" << std::endl;
	a.setEnergyPoints(0);
	a.beRepaired(6);
	std::cout << std::endl;
}

int main (void)
{
	orthodox_canonical_form(); 
	test_get_set( );
	test_attack();
	test_take_damage();
	test_beRepaired();
	
	return (0);
}