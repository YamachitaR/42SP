/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:17:51 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/07/05 16:32:46 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _weapon(weapon)
{
	this->_name = name;
}

HumanA::~HumanA(void)
{
	return;
}

void HumanA::attack(void)
{
	std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
}
