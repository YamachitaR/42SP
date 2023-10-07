/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:19:58 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/04 22:01:50 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <iomanip>

int main(void)
{
	std::cout << "========|PDF|===========" << std::endl;
	int a = 2;
	int b = 3;
	
	::swap(a,b);
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	
	std::string c = "chaine1";
	std::string d = "chaine2";
	
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	
	std::cout << "========|END|===========" << std::endl;

	std::cout << "========|more test|===========" << std::endl;
	std::cout << std::fixed << std::setprecision(4);
	
	float e = 3.4;
	float f = 3.29999;
	
	::swap(e, f);
	std::cout << "e = " << e << ", f = " << f << std::endl;
	std::cout << "min( e, f ) = " << ::min( e, f ) << std::endl;
	std::cout << "max( e, f ) = " << ::max( e, f ) << std::endl;

	
	double h = 3.40;
	double i = 3.3999;
	
	::swap(h, i);
	std::cout << "h = " << h << ", i = " << i << std::endl;
	std::cout << "min( h, i ) = " << ::min( h, i ) << std::endl;
	std::cout << "max( h, i ) = " << ::max( h, i ) << std::endl;

	
	char j = 'a';
	char k = 'b';
	
	::swap(j, k);
	std::cout << "j = " << j << ", k = " << k << std::endl;
	std::cout << "min( j, k ) = " << ::min( j, k ) << std::endl;
	std::cout << "max( j, k ) = " << ::max( j, k ) << std::endl;
	
	return (0);	
}