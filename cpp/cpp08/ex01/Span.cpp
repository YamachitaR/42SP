/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 02:50:41 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/13 19:50:04 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(void){
	std::cout << "Span: Default constructor called" << std::endl;
	this->_max = 0;
}

Span::Span(unsigned int n){
	std::cout << "Span: Constructor with parameter called" << std::endl;
	this->_max = n;
}

Span::Span(Span const &copy)
{
	std::cout << "Span: Copy constructor called" << std::endl;
	*this = copy;
}

Span::~Span(void){
	std::cout << "Span: Destructor called" << std::endl;
}

Span &Span::operator=(Span const &rhs){
	std::cout << "Span: Copy assignment operator" << std::endl;

	if (this != &rhs)
	{
		this->_max = rhs._max;
		this->_v = rhs._v;
	}
	return (*this);
}

void Span::addNumber(int value)
{
	if(this->_v.size() <  this->_max)
		this->_v.push_back(value);
	else
		throw std::runtime_error("The amount of element has been exceeded!");
} 

void Span::addMoreNumber(std::vector<int> value)
{
	unsigned i;

	i = 0;
	while(i < value.size())
	{
		this->addNumber(value[i]);
		i++;
	}
}

int Span::longestSpan(void)
{
	std::vector<int>::iterator min;
	std::vector<int>::iterator max;
	
	if(this->_v.size() < 2)
		throw std::runtime_error("Impossible to calculate as it needs to have at least two elements!");
	
	std::sort(this->_v.begin(), this->_v.end());

	min = this->_v.begin();
	max = this->_v.end() - 1;
	
	return(*max - *min);
}


int Span::shortestSpan(void)
{
	int smaller;
	unsigned  i;
	
	if(this->_v.size() < 2)
		throw std::runtime_error("Impossible to calculate as it needs to have at least two elements!");
	
	std::sort(this->_v.begin(), this->_v.end());

	smaller = this->_v[1] - this->_v[0];
	i = 2;
	while(i < this->_v.size()){
		if(this->_v[i] - this->_v[i-1]  < smaller)
			smaller = this->_v[i] - this->_v[i-1];
		i++;	
	}
	return(smaller);
} 