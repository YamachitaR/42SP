/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 03:11:57 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/09/08 02:05:07 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

void Animal_OrthodoxCanonicalForm(void) 
{
	std::cout << "===|Animal: Orthodox Canonical Form!|===" << std::endl;	
	
	Animal a;
	Animal b( a );
	Animal c;
	
	c = b;

	std::cout << "type a: " << a.getType() << std::endl;
	std::cout << "type b: " << b.getType() << std::endl;
	std::cout << "type c: " << c.getType() << std::endl;
	
	std::cout << "Make sound: a" << std::endl;
	a.makeSound();
	std::cout << "Make sound: b" << std::endl;
	b.makeSound();
	std::cout << "Make sound:c" << std::endl;
	c.makeSound();

}

void Dog_OrthodoxCanonicalForm(void) 
{
	std::cout << "===|Dog: Orthodox Canonical Form!|===" << std::endl;	
	
	Dog a;
	Dog b( a );
	Dog c;
	
	c = b;

	std::cout << "type a: " << a.getType() << std::endl;
	std::cout << "type b: " << b.getType() << std::endl;
	std::cout << "type c: " << c.getType() << std::endl;

	std::cout << "Make sound: a" << std::endl;
	a.makeSound();
	std::cout << "Make sound: b" << std::endl;
	b.makeSound();
	std::cout << "Make sound:c" << std::endl;
	c.makeSound();
}

void Cat_OrthodoxCanonicalForm(void) 
{
	std::cout << "===|Cat: Orthodox Canonical Form!|===" << std::endl;	
	
	Cat a;
	Cat b( a );
	Cat c;
	
	c = b;

	std::cout << "type a: " << a.getType() << std::endl;
	std::cout << "type b: " << b.getType() << std::endl;
	std::cout << "type c: " << c.getType() << std::endl;

	std::cout << "Make sound: a" << std::endl;
	a.makeSound();
	std::cout << "Make sound: b" << std::endl;
	b.makeSound();
	std::cout << "Make sound:c" << std::endl;
	c.makeSound();
}

void PDF(void)
{
	std::cout << "===|Test: PDF42!|===" << std::endl;

	Animal *meta = new Animal();
	Animal *i = new Dog();
	Animal *j = new Cat();
	
	std::cout << "Anima? " << meta->getType() << std::endl;
	std::cout << "Dog? " << j->getType() << std::endl;
	std::cout << "Cat?" <<i->getType() << std::endl;
	
	std::cout << "Sound Animal" << std::endl;
	meta->makeSound();
	std::cout << "Sound Dog" << std::endl;
	i->makeSound();
	std::cout << "Sound Cat" << std::endl;
	j->makeSound();
	
	delete meta;
	delete i;
	delete j;
}

void Wrong(void)
{
	std::cout << "===|Test: Wrong!|===" << std::endl;
	
	WrongAnimal *meow = new WrongCat();
	Animal *cat = new Cat();

	std::cout << "Sound WrongCat" << std::endl;
	meow->makeSound();
	std::cout << "Sound Cat" << std::endl;
	cat->makeSound();

	delete meow;
	delete cat;
}

int main(void)
{
	Animal_OrthodoxCanonicalForm();
	std::cout << "===| END |===" << std::endl << std::endl;
	
	Dog_OrthodoxCanonicalForm();
	std::cout << "===| END |===" << std::endl << std::endl;
	
	Cat_OrthodoxCanonicalForm();
	std::cout << "===| END |===" << std::endl << std::endl;

	PDF();
	std::cout << "===| END |===" << std::endl << std::endl;
	
	Wrong( );
	std::cout << "===| END |===" << std::endl << std::endl;
	
	return (0);
}