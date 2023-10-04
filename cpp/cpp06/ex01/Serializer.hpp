/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 14:45:56 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/03 22:53:13 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Serializer_HPP
#define Serializer_HPP

#include "data.hpp"
#include <iostream>
#include <stdint.h>

class Serializer
{
	private:
		Serializer(void);
		Serializer (const Serializer &copy);
		~Serializer(void);
		
		Serializer &operator= (Serializer const &rhs);
	
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif