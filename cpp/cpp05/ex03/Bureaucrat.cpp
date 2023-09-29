/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 23:43:02 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/09/28 00:05:30 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("Bureaucrat"), _grade(2)
{
	std::cout << "Bureaucrat: Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string str, int grade): _name(str), _grade(grade)
{
	std::cout << "Bureaucrat: Constructor with parameter called" << std::endl;

	if(grade < 1)
		throw GradeTooHighException();
	if(grade > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy): _name(copy.getName())
{
	std::cout << "Bureaucrat: Copy constructor called" << std::endl;
	*this = copy;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Bureaucrat: Destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	std::cout << "Bureaucrat: Copy assignment operator" << std::endl;

	if (this != &rhs)
	{
		this->_grade = rhs._grade;
	}
	return (*this);
}

std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}
		
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too hight\n");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low\n");
}

void Bureaucrat::increment (void)
{
	this->_grade --;
	if(this->_grade < 1)
		throw GradeTooHighException();
}

void Bureaucrat:: decrement (void)
{
	this->_grade ++;
	if(this->_grade > 150)
		throw GradeTooLowException();
}

void Bureaucrat::signForm(AForm &aform)
{
	try
	{
		aform.beSigned(*this);
		std::cout << this->_name << " signed " << aform.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout  << this->_name << "  could't signed " << aform.getName() << " because " << e.what() <<  std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	int code;
	try
    { 
		code = form.execute(*this);

		if(code == 1)
			std::cout << this->_name << " executed " << form.getName() << std::endl;
		else if(code == 2)
			std::cout  << this->_name << "  could't execute " << form.getName() << " because " << "robot failed." <<  std::endl;
		else if(code == 3)
			std::cout  << this->_name << "  could't execute " << form.getName() << " because " << "corrupted file." <<  std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->_name << " did not execute the " << form.getName() << " because " << e.what() <<std::endl;
    }
}


std::ostream &operator<<(std::ostream &o, Bureaucrat const &bureaucrat)
{
	o << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;
	return (o);
} 
