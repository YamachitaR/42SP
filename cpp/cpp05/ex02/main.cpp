/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 23:43:11 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/09/28 02:44:07 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

#include <iostream>
#include <string>
#include <iomanip> 
#include <sstream>

void shrubberycreationform (void)
{
	std::cout << "===|test ShrubberyCreationForm |===" << std::endl;

	std::cout << "[=>]About sign 145, exec 137" << std::endl;
	
	int i = 135;
	while(i < 147)
	{
		std::cout << "=>Grade: " << i <<std::endl;
		try
		{
			std::string s;
			std::stringstream buffer;
	
			buffer << "file_" << i;
			s = buffer.str();
			
			ShrubberyCreationForm	a(s);
			Bureaucrat				b("Ricardo", i);
			
			b.signForm(a);
			b.executeForm(a);
			
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		i ++;
		std::cout  << "---" << std::endl;
	}

	std::cout << "[=>]About not beSigned" << std::endl;
	try	{
		ShrubberyCreationForm	a("not");
		Bureaucrat				b("Signed", 1);
		
		b.executeForm(a);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void robotomyrequestform(void)
{
	std::cout << "===|test RobotomyRequestForm |===" << std::endl;

	std::cout << "[=>]About sign 72, exec 45" << std::endl;
	
	int i = 40;
	while(i < 75)
	{
		std::cout << "=>Grade: " << i <<std::endl;
		try
		{
			std::string s;
			std::stringstream buffer;
	
			buffer << "Robot_" << i;
			s = buffer.str();
			
			RobotomyRequestForm	a(s);
			Bureaucrat			b("Ricardo", i);
			
			b.signForm(a);
			b.executeForm(a);
			
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		i ++;

		std::cout  << "---" << std::endl;
	}

	std::cout << "[=>]About not beSigned" << std::endl;
	try
	{
		RobotomyRequestForm	a("not");
		Bureaucrat				b("Signed", 1);
			
		b.executeForm(a);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void presidentialpardonform(void)
{
	std::cout << "===|test PresidentialPardonForm |===" << std::endl;

	std::cout << "[=>]About sign 25, exec 5" << std::endl;
	
	int i = 0;
	while(i < 30)
	{
		std::cout << "=>Grade: " << i <<std::endl;
		try
		{
			std::string s;
			std::stringstream buffer;
	
			buffer << "Robot_" << i;
			s = buffer.str();
			
			PresidentialPardonForm	a(s);
			Bureaucrat				b("Ricardo", i);
			
			b.signForm(a);
			b.executeForm(a);
			
		}
		catch(std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
		i ++;

		std::cout  << "---" << std::endl;
	}

	std::cout << "[=>]About not beSigned" << std::endl;
	try
	{
		PresidentialPardonForm	a("not");
		Bureaucrat				b("Signed", 1);
			
		b.executeForm(a);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main(void)
{
	shrubberycreationform ();
	std::cout << "|====End===|" << std::endl;

	robotomyrequestform();
	std::cout << "|====End===|" << std::endl;
	
	presidentialpardonform();
	std::cout << "|====End===|" << std::endl;
	
	return (0);
}