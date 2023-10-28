/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:55:36 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/27 21:32:59 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"



int main(void){  // (int argc, char **argv){

	Date a =	atd("2055444493");

	std::cout << a.day <<std::endl;
/*
	if(!checkArgc(argc))
		return (1);
	
	if(!checkFile(argv[1]))
		return(1);
	
*/

	BitcoinExchange objeto;
	std::cout << isDate(2024,02,29) << std::endl;
	std::cout << isDate(2024,04,32) << std::endl;
	std::cout << isDate(2024,05,31) << std::endl;
	return (0);
}