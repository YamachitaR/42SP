/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 23:43:11 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/09/21 00:09:08 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Bureaucrat.hpp"

void form(void)
{
	std::cout << "===|test_Form|===" << std::endl;

	Form a("Politic", 71, 3) ;
	Form b( a );
	Form c;
	
	c = b;

	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;
}

void form_gradeSign(void)
{
	int i;
	
	std::cout << "===|Test: Form gradeSign|===" << std::endl;
	
	i = -10;
	while(i < 160)
	{
		std::cout << "=>Grade: " << i <<std::endl;
		try
		{
			Form a("Politic", i, 1);
		}
		catch(std::exception &e)
		{
			std::cout << e.what();
		}
		i ++;

		std::cout << "---" << std::endl;
	}	
}

void form_gradeExecute(void)
{
	int i;
	
	std::cout << "===|Test: Form gradeExecute|===" << std::endl;
	
	i = -10;
	while(i < 160)
	{
		std::cout << "=>Grade: " << i <<std::endl;
		try
		{
			Form a("Politic", 1, i);
		}
		catch(std::exception &e)
		{
			std::cout << e.what();
		}
		i ++;

		std::cout << "---" << std::endl;
	}	
}

void form_get_set(void)
{
	std::cout << "===|Form: get and set|===" << std::endl;

	Form a("Ricardo", 12, 25);

	std::cout << "getName:" << a.getName() << std::endl;
	
	std::cout << "getGradeSign:" << a.getGradeSign() << std::endl;
	
	std::cout << "getGradeExecute:" << a.getGradeExecute() << std::endl;
	
	std::cout << "getSigned:" << a.getSigned() << std::endl;
	a.setSigned(1);
	std::cout << "After setSigned:" << a.getSigned() << std::endl;
}

void test_signForm(void)
{
	std::cout << "===|test signForm|===" << std::endl;
	
	try
	{
		Bureaucrat a("Ricardo", 15);
		Form b("tax", 14, 10);
		std::cout << "=> ko " << std::endl;
		a.signForm (b);
	}catch(std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << "----------" << std::endl;
	try
	{
		Bureaucrat a("Ricardo", 15);
		Form b("tax", 15, 10);
		std::cout << "=> ok " << std::endl;
		a.signForm (b);
	}catch(std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << "----------" << std::endl;
	try
	{
		Bureaucrat a("Ricardo", 15);
		Form b("tax", 16, 10);
		std::cout << "=> ok " << std::endl;
		a.signForm (b);
	}catch(std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << "----------" << std::endl;
}

void test_beSigned(void)
{
	std::cout << "===|test beSigned|===" << std::endl;
	
	try
	{
		Bureaucrat a("Ricardo", 9);
		Form b("tax", 10, 10);
		std::cout << "=> ok " << std::endl;
		b.beSigned (a);
	}catch(std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << "----------" << std::endl;
	try
	{
		Bureaucrat a("Ricardo", 10);
		Form b("tax", 10, 10);
		std::cout << "=> ok " << std::endl;
		b.beSigned (a);
	}catch(std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << "----------" << std::endl;
	try
	{
		Bureaucrat a("Ricardo", 11);
		Form b("tax", 10, 10);
		std::cout << "=> ko " << std::endl;
		b.beSigned (a);
	}catch(std::exception &e)
	{
		std::cout << e.what();
	}
	std::cout << "----------" << std::endl;
}

int main(void)
{
	form( );
	std::cout << "|====End===|" << std::endl;

	form_gradeSign();
	std::cout << "|====End===|" << std::endl;

	form_gradeExecute();
	std::cout << "|====End===|" << std::endl;

	form_get_set();
	std::cout << "|====End===|" << std::endl;

	test_signForm();
	std::cout << "|====End===|" << std::endl;

	test_beSigned();
	std::cout << "|====End===|" << std::endl;
	return (0);
}