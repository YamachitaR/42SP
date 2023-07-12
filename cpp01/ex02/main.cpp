/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:48:41 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/07/05 16:35:39 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<iostream>

int main(void)
{
	std::string string =  "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "The memory address of the string variable:" << &string << std::endl;
	std::cout << "The memory address held by stringPTR:" << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF:" << &stringREF << std::endl;
	
	std::cout << "The value of the string variable:" << string << std::endl;
	std::cout << "The value pointed to by stringPTR:" << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF:" << stringREF << std::endl;
}