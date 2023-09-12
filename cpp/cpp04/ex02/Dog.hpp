/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 05:05:07 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/09/08 02:00:37 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef Dog_HPP
#define Dog_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog: public AAnimal
{
	private:
		Brain *_brain;
		
	public:
		Dog(void);
		Dog(Dog const &copy);
		~Dog(void);
		
		Dog &operator=(Dog const &rhs);

		void makeSound(void) const;

		Brain *getBrain(void) const;
		void setBrain(Brain brain);	
};
#endif