/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 20:11:35 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/03 22:47:03 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.hpp"

void identify(Base* p)
{
	A *a = dynamic_cast<A*>(p);
	B *b = dynamic_cast<B*>(p);
	C *c = dynamic_cast<C*>(p);
	
	if(a)
		std::cout << "Pointer Type: A" << std::endl;
	else if(b)
		std::cout << "Pointer Type: B" << std::endl;
	else if(c)
		std::cout << "Pointer Type: C" << std::endl;
	else
		std::cout << "Not identified" << std::endl;
}

void identify(Base& p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout << "Reference Type: A" << std::endl;
	}catch(std::exception &e)
	{
		try
		{
			B b = dynamic_cast<B&>(p);
			std::cout << "Reference Type: B" << std::endl;
		}
		catch(std::exception &e)
		{
			try
			{
				C c = dynamic_cast<C&>(p);
				std::cout << "Reference Type: C" << std::endl;
			}catch(std::exception &e)
			{
				std::cout << "Not identified" << std::endl;
			}
				
		}
	}
}