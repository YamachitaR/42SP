/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 05:46:54 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/07/27 05:49:21 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WrongCat_HPP
#define WrongCat_HPP

#include "WrongAnimal.hpp"
#include "Brain.hpp"

class WrongCat: public WrongAnimal
{
	private:
		Brain *_brain;
		
	public:
		WrongCat(void);
		WrongCat(WrongCat const &copy);
		~WrongCat(void);
		
		WrongCat &operator=(WrongCat const &rhs);

		void makeSound(void) const;

		Brain *getBrain(void) const;
		void setBrain(Brain brain);	
};
#endif

