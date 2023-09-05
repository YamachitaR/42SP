/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 22:01:21 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/08/04 21:22:04 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


void Animal_OrthodoxCanonicalForm(void) 
{
	std::cout << "===|Animal: Orthodox Canonical Form!|===" << std::endl;	
	
	Animal a("Ricardo");
	Animal b( a );
	Animal c;
	
	c = b;

	std::cout << "type a: " << a.getType() << std::endl;
	std::cout << "type b: " << b.getType() << std::endl;
	std::cout << "type c: " << c.getType() << std::endl;
}

void Dog_OrthodoxCanonicalForm(void) 
{
	std::cout << "===|Dog: Orthodox Canonical Form!|===" << std::endl;	
	
	Dog a("Ricardo");
	Dog b( a );
	Dog c;
	
	c = b;

	std::cout << "type a: " << a.getType() << std::endl;
	std::cout << "type b: " << b.getType() << std::endl;
	std::cout << "type c: " << c.getType() << std::endl;
}


void Cat_OrthodoxCanonicalForm(void) 
{
	std::cout << "===|Cat: Orthodox Canonical Form!|===" << std::endl;	
	
	Cat a("Ricardo");
	Cat b( a );
	//Cat c;
	
	//c = b;

	//std::cout << "type a: " << a.getType() << std::endl;
	//std::cout << "type b: " << b.getType() << std::endl;
	//std::cout << "type c: " << c.getType() << std::endl;
}


int main(void)
{
	//Animal_OrthodoxCanonicalForm();
	//Dog_OrthodoxCanonicalForm();
	//Cat_OrthodoxCanonicalForm();
	
	//Animal *a = new Animal();
	Animal *b = new Dog();
	
	//a->makeSound();
	//b->makeSound();
	
	//delete a;
	delete b;


	
	return (0);
}