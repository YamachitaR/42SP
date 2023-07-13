/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 02:19:10 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/07/13 19:06:40 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

void example1(void)
{
	Fixed a;
	a.setRawBits(1);
	std::cout << a.getRawBits() << std::endl;
}


void pdf(void)
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );
	
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}



int main(void) {

	std::cout << "===|Example 1|==" << std::endl;
	example1();
	


	std::cout << std::endl << "===|PDF|==" << std::endl;
	pdf();
	
	return 0;
}