/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 22:02:21 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/07/12 14:16:59 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main (void)
{
	Zombie *pointer;
	int n_zombie;
	int i;
	
	n_zombie = 10;
	pointer = zombieHorde(n_zombie, "Ricardo");
	i = 0;
	while(i < n_zombie)
	{
		pointer[i].announce();
		i ++;
	}
	delete[] pointer;
	return (0);
}