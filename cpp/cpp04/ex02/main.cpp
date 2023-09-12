/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 03:11:57 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/09/08 02:18:19 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

void Brain_OrthodoxCanonicalForm(void) 
{
	std::cout << "===|Brain: Orthodox Canonical Form!|===" << std::endl;	
	
	Brain a("I am hungry!");
	Brain b( a );
	Brain c;
	
	c = b;

	std::cout << "think a: " << std::endl;
	a.sayIdeas();

	std::cout << "think b: " << std::endl;
	b.sayIdeas();

	std::cout << "think c: " << std::endl;
	c.sayIdeas();

}

void Cat_OrthodoxCanonicalForm(void) 
{
	std::cout << "===|Cat: Orthodox Canonical Form!|===" << std::endl;	
	
	Cat a;
	a.getBrain()->setSameIdeas("lasagna");
	
	Cat b( a );
	Cat c;
	c = b;

	std::cout << "type a: " << a.getType() << std::endl;
	a.getBrain()->sayIdeas();
	
	std::cout << "type b: " << b.getType() << std::endl;
	b.getBrain()->sayIdeas();
	
	std::cout << "type c: " << c.getType() << std::endl;
	c.getBrain()->sayIdeas();
}

void Dog_OrthodoxCanonicalForm(void) 
{
	std::cout << "===|Cat: Orthodox Canonical Form!|===" << std::endl;	
	
	Dog a;
	a.getBrain()->setSameIdeas("bone");
	
	Dog b( a );
	Dog c;
	c = b;

	std::cout << "type a: " << a.getType() << std::endl;
	a.getBrain()->sayIdeas();
	
	std::cout << "type b: " << b.getType() << std::endl;
	b.getBrain()->sayIdeas();
	
	std::cout << "type c: " << c.getType() << std::endl;
	c.getBrain()->sayIdeas();
}

void Array(void)
{
	std::cout << "===|Array: |===" << std::endl;	
	
	int i;
	AAnimal *animal[100];

	i = 0;
	while(i < 100)
	{
		std::cout << "Create Animal:" << i + 1 << std::endl; 
		if(i % 2 == 0)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
		i ++;
	}
	
	std::cout << "================================" << std::endl;
	
	i = 0;
	while(i < 100)
	{
		std::cout << "Delete Animal:" << i + 1 << std::endl; 
		delete animal[i];
		i ++;
	}

}

void Dog_testCopy(void)
{
	std::cout << "===|Dog:Test Copy |===" << std::endl;
	
	Dog *obj = new Dog();
	obj->getBrain()->setSameIdeas("cat");
	
	Dog *copyObj1 = new Dog;
	*copyObj1 = *obj;

	Dog copyObj2;
	copyObj2 = * obj;

	Dog copyObj3(*obj);

	std::cout << "=> Before " << std::endl;
	std::cout << "=> Obj:" << obj->getBrain()->getIdea(5)  << std::endl ;
	std::cout << "=> copyObj1:" << copyObj1->getBrain()->getIdea(5) << std::endl;
	std::cout << "=> copyObj2:" << copyObj2.getBrain()->getIdea(5) << std::endl;
	std::cout << "=> copyObj3:" << copyObj3.getBrain()->getIdea(5) << std::endl;

	copyObj1->getBrain()->setSameIdeas("vegeterian");
	copyObj2.getBrain()->setSameIdeas("bone");
	copyObj3.getBrain()->setSameIdeas("pork");

	std::cout << "=> After " << std::endl;
	std::cout << "=> Obj:" << obj->getBrain()->getIdea(5)  << std::endl ;
	std::cout << "=> copyObj1:" << copyObj1->getBrain()->getIdea(5) << std::endl;
	std::cout << "=> copyObj2:" << copyObj2.getBrain()->getIdea(5) << std::endl;
	std::cout << "=> copyObj3:" << copyObj3.getBrain()->getIdea(5) << std::endl;

	delete obj;
	delete copyObj1;
}

void Cat_testCopy(void)
{
	std::cout << "===|Cat:Test Copy |===" << std::endl;
	
	Cat *obj = new Cat();
	obj->getBrain()->setSameIdeas("fisk");
	
	Cat *copyObj1 = new Cat;
	*copyObj1 = *obj;

	Cat copyObj2;
	copyObj2 = * obj;

	Cat copyObj3(*obj);
	
	std::cout << "=> Before " << std::endl;
	std::cout << "=> Obj:" << obj->getBrain()->getIdea(5)  << std::endl ;
	std::cout << "=> copyObj1:" << copyObj1->getBrain()->getIdea(5) << std::endl;
	std::cout << "=> copyObj2:" << copyObj2.getBrain()->getIdea(5) << std::endl;
	std::cout << "=> copyObj3:" << copyObj3.getBrain()->getIdea(5) << std::endl;

	copyObj1->getBrain()->setSameIdeas("vegeterian");
	copyObj2.getBrain()->setSameIdeas("bone");
	copyObj3.getBrain()->setSameIdeas("pork");

	std::cout << "=> After " << std::endl;
	std::cout << "=> Obj:" << obj->getBrain()->getIdea(5)  << std::endl ;
	std::cout << "=> copyObj1:" << copyObj1->getBrain()->getIdea(5) << std::endl;
	std::cout << "=> copyObj2:" << copyObj2.getBrain()->getIdea(5) << std::endl;
	std::cout << "=> copyObj3:" << copyObj3.getBrain()->getIdea(5) << std::endl;

	delete obj;
	delete copyObj1;
}

void compilationError(void)
{
	std::cout << "===|makeSound: Test abstract class  |===" << std::endl;
	WrongAnimal animal;
	animal.setType("ok");

	//AAnimal compilationError;
	//compilationError.setType("ko");
}

int main(void)
{
	Brain_OrthodoxCanonicalForm();
	std::cout << "===| END |===" << std::endl << std::endl;
	
	Cat_OrthodoxCanonicalForm(); 
	std::cout << "===| END |===" << std::endl << std::endl;
	
	Dog_OrthodoxCanonicalForm(); 
	std::cout << "===| END |===" << std::endl << std::endl;

	Array();
	std::cout << "===| END |===" << std::endl << std::endl;
	
	Dog_testCopy();
	std::cout << "===| END |===" << std::endl << std::endl;

	Cat_testCopy();
	std::cout << "===| END |===" << std::endl << std::endl;

	compilationError();

	
	return (0);
}
