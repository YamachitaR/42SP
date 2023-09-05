/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 21:44:43 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/08/01 21:12:49 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(std::string str);
		WrongAnimal(WrongAnimal const &copy);
		~WrongAnimal(void);

		WrongAnimal &operator=(WrongAnimal const &rhs);

        void makeSound(void) const;

        std::string getType(void) const;
        void setType(std::string type);
    
    protected:
        std::string _type;
};

#endif

