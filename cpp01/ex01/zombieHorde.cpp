/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 22:02:31 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/07/12 14:17:45 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"


Zombie* zombieHorde( int N, std::string name )
{
	int i;
	Zombie	*pointer;

	pointer = new Zombie[N];
	i = 0;
	while(i < N)
	{
		pointer[i].setName(name);
		i ++;
	}
	return pointer;
}