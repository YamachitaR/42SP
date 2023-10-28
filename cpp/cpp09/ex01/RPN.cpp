/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 07:10:50 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/28 07:55:19 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {
	std::cout << "RPN: Default constructor called" << std::endl;
}

RPN::RPN(std::string input) {
	std::cout << "RPN: Constructor with parameter type called" << std::endl;
	std::cout << input;
}

RPN::RPN(RPN const &copy){
	std::cout << "RPN: Copy constructor called" << std::endl;
	*this = copy;
	
}

RPN::~RPN(void){
	std::cout << "RPN: Destructor called" << std::endl;
}

RPN& RPN::operator=(RPN const &rhs){
	std::cout << "RPN: Copy assignment operator" << std::endl;
	if (this != &rhs){
		std::cout << "imput";

	}
	return (*this);
}





bool checkArgc(const int argc){
	if(argc != 2)
		return (errorMessage("invalid number of arguments! \nExample: ./RPN \"1 2 +\" "));
	return (true);
}



bool errorMessage(std::string str){
	std::cout << "Error: " << str << std::endl;
	return(false);
}