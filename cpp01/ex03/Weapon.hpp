/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:16:36 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/07/06 23:09:37 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HTPP
#define WEAPON_HTPP

#include <iostream> 
#include <string>

class Weapon
{
	private:
		std::string _type;

	public:
		Weapon(std::string type);
		~Weapon(void);

		const std::string &getType(void);
		void setType(std::string type);	 
};

#endif