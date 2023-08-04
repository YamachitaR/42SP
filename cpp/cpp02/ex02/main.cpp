/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 02:19:10 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/07/15 02:19:48 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

void example1(void)
{
	Fixed const a(7.50f);
	Fixed const b(7.25f);
	Fixed const c(7.25f);
	
	std::cout << "Value a = " << a << " Value b = " << b << " Value c = " << c << std::endl; 

	std::cout << "(a > b)=" << (a > b) << std::endl;
	std::cout << "(b > a)=" << (b > a) << std::endl;
	
	std::cout << "(a < b)=" << (a < b) << std::endl;
	std::cout << "(b < a)=" << (b < a) << std::endl;
	
	std::cout << "(a >= b)=" << (a >= b) << std::endl;
	std::cout << "(b >= a)=" << (b >= a) << std::endl;
	std::cout << "(c >= b)=" << (c >= b) << std::endl;
	std::cout << "(b >= c)=" << (b >= c) << std::endl;

	std::cout << "(a <= b)=" << (a <= b) << std::endl;
	std::cout << "(b <= a)=" << (b <= a) << std::endl;
	std::cout << "(c <= b)=" << (c <= b) << std::endl;
	std::cout << "(b <= c)=" << (b <= c) << std::endl;

	std::cout << "(a == b)=" << (a == b) << std::endl;
	std::cout << "(c == b)=" << (c == b) << std::endl;

	std::cout << "(a != b)=" << (a != b) << std::endl;
	std::cout << "(c != b)=" << (c != b) << std::endl;
}

void example2(void)
{
	Fixed  a(3.25f);
	Fixed  b(4.0f);
	
	std::cout << "Value a = " << a << " Value b = " << b << std::endl; 
	std::cout << "(a + b)=" << (a + b) << std::endl;
	std::cout << "(a - b)=" << (a - b) << std::endl;
	std::cout << "(b - a)=" << (b - a) << std::endl;
	std::cout << "(a * b)=" << (a * b) << std::endl;
	std::cout << "(a / b)=" << (a / b) << std::endl;
	std::cout << "(b / a)=" << (b / a) << std::endl;
	
	std::cout << "PDF: Give information" << std::endl;
	std::cout << "If you ever do a division by 0, it is acceptable that the program crashes" << std::endl;
}

void example3(void)
{
	Fixed a;
	Fixed b(2);

	std::cout << "Value a = " << a << " Value b = " << b  << std::endl; 
	std::cout << "++a=" << ++a << std::endl;
	std::cout << "++a=" << ++a << std::endl;
	std::cout << "++a=" << ++a << std::endl;

	std::cout << "--a=" << --a << std::endl;
	std::cout << "--a=" << --a << std::endl;
	std::cout << "--a=" << --a << std::endl;

	std::cout << "b++=" << b++ << std::endl;
	std::cout << "b++=" << b++ << std::endl;
	std::cout << "b++=" << b++ << std::endl;

	std::cout << "b--=" << b-- << std::endl;
	std::cout << "b--=" << b-- << std::endl;
	std::cout << "b--=" << b-- << std::endl;
	std::cout << "b=" << b << std::endl;
}

void example4(void)
{
	Fixed a(9);
	Fixed b(5);
	Fixed const c(7.25f);

	std::cout << "Value a = " << a << " Value b = " << b  << " Value c = " << c << std::endl; 
	std::cout << "min(a,b)="  << Fixed::min(a,b) << std::endl;
	std::cout << "max(a,b)="  << Fixed::max(a,b) << std::endl;
	std::cout << "min(c,b)="  << Fixed::min(c,b) << std::endl;
	std::cout << "max(c,b)="  << Fixed::max(c,b) << std::endl;
}


void pdf(void)
{
	std::cout << "===| PDF |===" << std::endl;
	
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;
}


int main(void) {

	std::cout << "===|comparison operators:|===" << std::endl;
	example1();

	std::cout << "===|4 arithmetic operators:|===" << std::endl;
	example2();
	
	std::cout << "===| increment/decrement|===" << std::endl;
	example3();
	
	std::cout << "===| max/min |===" << std::endl;
	example4();
	
	pdf();
	
	return 0;
}