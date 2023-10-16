/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 02:17:23 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/14 22:51:28 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void pdf (void)
{
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}

void exceptionShortLong(void)
{
	Span spanExceeded(1);
	spanExceeded.addNumber(2);
	
	try {
		spanExceeded.longestSpan();
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}

	try {
		spanExceeded.shortestSpan();
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
}

void exceptionAddNumber(void)
{
	Span spanExceeded(1);
	
	try {
		spanExceeded.addNumber(2);
		spanExceeded.addNumber(2);
	}
	catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
}

void test(void)
{
	unsigned i;
	Span sp = Span(15001);
	std::vector<int> v;

	i = 0;
	while(i < 15001){
		v.push_back(i*2);
		i++;
	}
	sp.addMoreNumber(v);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	v.push_back(i*2);
	try{
		sp.addMoreNumber(v);
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
}

void canonical(void){
	Span sp = Span(5);
	
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	Span copyConstructor(sp);
	
	std::cout << copyConstructor.shortestSpan() << std::endl;
	std::cout << copyConstructor.longestSpan() << std::endl;

	Span copyOperator;
	copyOperator = sp;
	
	std::cout << copyOperator.shortestSpan() << std::endl;
	std::cout << copyOperator.longestSpan() << std::endl;
	
}

int main(void){

	std::cout << "====|Test: PDF|===" << std::endl;
	pdf();
	std::cout << "====|END|===" << std::endl;

	std::cout << "====|Test: Exception Add Number|===" << std::endl;
	exceptionAddNumber();
	std::cout << "====|END|===" << std::endl;

	std::cout << "====|Test: Add More Number|===" << std::endl;
	test();
	std::cout << "====|END|===" << std::endl;
	
	std::cout << "====|Test: Canonical|===" << std::endl;
	canonical();
	
	return (0);
}

