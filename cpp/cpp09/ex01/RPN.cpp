/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 07:10:50 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/28 22:02:02 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void) {
	std::cout << "RPN: Default constructor called" << std::endl;
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
		
	}
	return (*this);
}

bool RPN::_isOperator(const std::string& token) {
    return token == "+" || token == "-" || token == "*" || token == "/";
}

double RPN::_operation(double nbr1, double nbr2, std::string const &token){
	if (token == "+") {
        return (nbr1 + nbr2);
    } else if (token == "-") {
        return (nbr1 - nbr2);
    } else if (token == "*") {
        return (nbr1 * nbr2);
    } else if (token == "/") {
        if (nbr2 != 0.0) {
            return (nbr1 / nbr2);
        } else {
            throw std::runtime_error("Error: Division by zero.");
        }
    }
    throw std::runtime_error("Error: not found operator.");
}



double RPN::calculation(const std::string& str) {
    std::stack<double> stack;
    std::istringstream iss(str);
    std::string token;
	double nbr1;
	double nbr2;
	double result;

    while (iss >> token) {
        if (_isOperator(token)) {
            if (stack.size() < 2) {
                 throw std::runtime_error("Error");
            }
            nbr2 = stack.top();
            stack.pop();
            
			nbr1 = stack.top();
            stack.pop();
			
            result = _operation(nbr1, nbr2, token);
            stack.push(result);
        } else {
			if(!isFloat(token))
				 throw std::runtime_error("Error");
				 
            nbr1 = atof(token.c_str());
            stack.push(nbr1);
        }
    }

    if (stack.size() != 1) {
    	throw std::runtime_error("Error");
    }

    return stack.top();
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

bool isInteger(std::string str){
	size_t i;

	i = 0;
	
	if(str.empty())
		return(false);
		
	if(str[i] == '+' || str[i] == '-'){
		i ++;
		if(!std::isdigit(str[i]))
			return (false);
		i ++;
	}
		
	while (i <  str.length()){
		if(!std::isdigit(str[i]))
			return (false);
		i ++;
	}
	return (true);
}

bool isFloat(const std::string str){
	size_t i;
	int point;

	if(isInteger(str))
		return(true);
	
	if(str.empty())
		return(false);
	
	i = 0;
	if(str[i] == '+' || str[i] == '-'){
		i ++;
		if(!std::isdigit(str[i]))
			return (false);
		i ++;
	}
	point = 0; 	
	while (i <  str.length()){
		if(str[i] == '.' ){
			point ++;
			i ++;
		}
		if(!std::isdigit(str[i])){
			return (false);
		}
		i ++;
	}
	
	if(point > 1){
		return (false);
	}
	
	return(true);
}