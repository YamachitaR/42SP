/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sample.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 01:49:23 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/04/25 19:29:24 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Sample.class.hpp"

Sample::Sample(void)
{
	std::cout << "Chama o construtor" << std::endl;
	this->foo = 42;
	std::cout << "this->foo:" << this->foo << std::endl;

	this->bar();
	return ;
}

Sample::~Sample(void)
{
	std:: cout << "Destruir o construtor " << std::endl;
	return ;
}

void Sample::bar(void)
{
	std:: cout << "Chamando o \"member fuction\" conhecido como portugues metodo  " << std::endl;
	return ;
}