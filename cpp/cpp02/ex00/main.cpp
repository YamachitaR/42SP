/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 02:19:10 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/07/13 04:48:10 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

void example1(void)
{
	Fixed a;
	a.setRawBits(1);
	std::cout << a.getRawBits() << std::endl;
}

void example2(void)
{
	Fixed a;
	a.setRawBits(2);
	Fixed b( a );
	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	a.setRawBits(7);
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
}

void example3(void)
{
	Fixed b;
	b.setRawBits(3);
	Fixed c;

	c = b;
	
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	b.setRawBits(4);
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
}

void example4(void)
{
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;
	
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
}




int main(void) {

	std::cout << "===|Example 1|==" << std::endl;
	example1();
	
	std::cout << std::endl << "===|Example 2|==" << std::endl;
	example2();
	
	std::cout << std::endl << "===|Example 3|==" << std::endl;
	example3();

	std::cout << std::endl << "===|PDF|==" << std::endl;
	example4();
	
	return 0;
}