/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 22:02:21 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/07/12 14:16:12 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
	Zombie *pointer;
	
	pointer = newZombie("Ricardo");
	pointer->announce();
	delete pointer;
	randomChump("42SP");
	return (0);
}