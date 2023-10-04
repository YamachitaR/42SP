/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testIdentify.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 21:34:50 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/03 22:10:20 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.hpp"


void testIdentify(void)
{
	Base *a = new A();
	Base *b = new B();
	Base *c = new C();
	
	A *d = new A;
	B *e = new B();
	C *f = new C();

	A g;
	B h;
	C i;
	
	std::cout << "Send A" << std::endl; 
	identify(a);
	identify(d);
	identify(&g);

	identify(*a);
	identify(*d);
	identify(g);
	std::cout << "---------" << std::endl;
	
	std::cout << "Send B" << std::endl; 
	identify(b);
	identify(e);
	identify(&h);

	identify(*b);
	identify(*e);
	identify(h);
	std::cout << "---------" << std::endl;
	
	std::cout << "Send C" << std::endl; 
	identify(c);
	identify(f);
	identify(&i);
	
	identify(*c);
	identify(*f);
	identify(i);

	delete a;
	delete b;
	delete c;
	delete d;
	delete e;
	delete f;
}