/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 22:02:44 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/07/04 15:42:54 by ryoshio-         ###   ########.fr       */
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
		Zombie(std::string name);
		~Zombie(void);
		void announce(void);
};
	Zombie* newZombie(std::string name);
	void randomChump(std::string name);

#endif 