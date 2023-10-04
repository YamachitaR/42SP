/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:51:19 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/03 23:08:38 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data data("Ricardo");

	uintptr_t serialized = Serializer::serialize(&data);
	Data * deserialized = Serializer::deserialize(serialized);

	if(deserialized == &data)
		std::cout << "Serialize and deserialize worked!" << std::endl;
	else
		std::cout << "Serialize and deserialize failed!" << std::endl;

	std::cout << "deserialized->name:" << deserialized->name << std::endl;
	deserialized->name = "Leticia";
	std::cout << "After changing deserialized->name=Leticia, data.name:" << data.name << std::endl;
	 	
	return(0);
}