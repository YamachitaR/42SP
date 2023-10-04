/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 15:59:29 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/03 16:26:29 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool checkArgc(int nbr)
{
	if(nbr != 2){
		std::cout << "./convert value" << std::endl;
		return (false);
	}
	return(true);
}

int main (int argc, char **argv){
	
	if(!checkArgc(argc))
		return (1); 
		
	ScalarConverter::convert(argv[1]);

	return (0);
}