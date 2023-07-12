/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 22:41:30 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/07/11 20:40:12 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	return;	
}

Harl::~Harl(void)
{
	return;
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl; 
}



void Harl::complain(std::string level)
{
	std::string list[4] = {"debug", "info", "warning", "error"};
	void (Harl:: *message[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	int i = 0;
	while(i < 4)
	{
		if(list[i].compare(level) == 0)
			(this->*message[i])();
		i++;
	}
	std::cout << "Invalid complain level!" << std::endl;
}