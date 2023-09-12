/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 05:32:11 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/08/31 02:37:21 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Animal_HPP
#define Animal_HPP

#include <iostream>

class Animal
{
	protected:
		std::string _type;
		
	public:
		Animal(void);
		Animal(Animal const &copy);
		Animal(std::string str);
		virtual ~Animal(void);
		
		Animal &operator=(Animal const &rhs);

		std::string getType(void) const;
		void setType(std::string type);

		virtual void makeSound(void) const;
};
#endif