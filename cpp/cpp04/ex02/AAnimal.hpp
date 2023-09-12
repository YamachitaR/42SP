/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 05:32:11 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/09/08 01:55:25 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AAnimal_HPP
#define AAnimal_HPP

#include <iostream>

class AAnimal
{
	protected:
		std::string _type;
		
	public:
		AAnimal(void);
		AAnimal(AAnimal const &copy);
		AAnimal(std::string str);
		virtual ~AAnimal(void);
		
		AAnimal &operator=(AAnimal const &rhs);

		std::string getType(void) const;
		void setType(std::string type);

		virtual void makeSound(void) const = 0;
};
#endif