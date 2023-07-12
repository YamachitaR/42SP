/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 22:02:44 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/07/12 14:17:32 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP 
#define ZOMBIE_HPP

#include <iostream> 

class Zombie 
{
	private:
		std::string _name;
	
	public:
		Zombie(void);
		~Zombie(void);
		void setName(std::string name);
		void announce(void);
};
	Zombie* zombieHorde(int N, std::string name);

#endif 