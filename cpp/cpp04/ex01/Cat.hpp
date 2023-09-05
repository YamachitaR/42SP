/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 03:21:06 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/08/01 03:22:02 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Cat_HPP
#define Cat_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain *_brain;

	public:
		Cat(void);
		Cat(std::string str);
		Cat(Cat const &copy);
		~Cat(void);

		Cat &operator=(Cat const &rhs);

        void makeSound(void) const;

		Brain *getBrain(void) const;
		void setBrain(Brain brain);
};

#endif
