/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:44:43 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/08/04 21:49:06 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	public:
		Animal(void);
		Animal(std::string str);
		Animal(Animal const &copy);
		virtual ~Animal(void);

		Animal &operator=(Animal const &rhs);

        virtual void makeSound(void) const;

        std::string getType(void) const;
        void setType(std::string type);
    
    protected:
        std::string _type;
};

#endif

