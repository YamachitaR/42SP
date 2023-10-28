/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 17:55:36 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/28 05:14:30 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"



int main(int argc, char **argv){

	if(!checkArgc(argc))
		return (1);
	
	if(!checkFile(argv[1]))
		return(1);
		
	BitcoinExchange obj;
	obj.exchange(argv[1]);

	

	return (0);
}