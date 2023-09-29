/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 23:43:11 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/09/29 19:11:08 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

void robotomy (void)
{
	Intern b;
	Bureaucrat c("Bureaucrat", 1);
	AForm *a;
	
	a = b.makeForm("robotomy request", "Robot");
	c.signForm(*a);
	a->execute(c);
	
	delete a;
}

void presidential (void)
{
	Intern b;
	Bureaucrat c("Bureaucrat", 1);
	AForm *a;
	
	a = b.makeForm("presidential pardon", "Lion");
	c.signForm(*a);
	a->execute(c);
	
	delete a;
}

void shrubbery (void)
{
	Intern b;
	Bureaucrat c("Bureaucrat", 1);
	AForm *a;
	
	a = b.makeForm("shrubbery creation", "Tree");
	c.signForm(*a);
	a->execute(c);
	
	delete a;
}

void error_name(void)
{
	Intern b;
	AForm *a;
	
	try{
		a = b.makeForm("not exist", "Tree");
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

}


int main(void)
{
	std::cout << "|====Robotomy===|" << std::endl;
	robotomy  ();
	std::cout << "|====End===|" << std::endl;
	
	std::cout << "|====Presidential===|" << std::endl;
	presidential();
	std::cout << "|====End===|" << std::endl;

	std::cout << "|====Shrubbery===|" << std::endl;
	shrubbery();
	std::cout << "|====End===|" << std::endl;

	std::cout << "|====Name not exist===|" << std::endl;
	error_name();
	std::cout << "|====End===|" << std::endl;
	
	return (0);
}