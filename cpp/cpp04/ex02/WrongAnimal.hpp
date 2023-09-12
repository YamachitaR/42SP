/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 05:32:11 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/07/27 05:35:55 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongAnimal_HPP
#define WrongAnimal_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;
		
	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const &copy);
		WrongAnimal(std::string str);
		~WrongAnimal(void);
		
		WrongAnimal &operator=(WrongAnimal const &rhs);

		std::string getType(void) const;
		void setType(std::string type);

		void makeSound(void) const;
};
#endif