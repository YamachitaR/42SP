/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 19:19:12 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/04/25 19:20:09 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main (void)
{
	char	buff[512];

	std::cout << "Hello, world !"  << std::endl;

	std::cout << "Entre com uma palavra: ";
	std::cin >> buff;
	std::cout << "Sua entrada foi:[" << buff << "]" << std::endl;

	return (0);
}

/*
Notação 

-> cout seria um "printf"
-> cin seria um "read" que ler as coisas do terminal
-> Os operadores << e >> são operadores de fluxos 
-> endl funciona como '\n'
*/