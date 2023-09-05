/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 22:37:04 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/08/01 03:17:14 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef Dog_HPP
#define Dog_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain *_brain;

	public:
		Dog(void);
		Dog(Dog const &copy);
		Dog(std::string str);
		~Dog(void);

		Dog &operator=(Dog const &rhs);

		void makeSound(void) const;

		Brain *getBrain(void) const;
		void setBrain(Brain brain);
};
#endif
