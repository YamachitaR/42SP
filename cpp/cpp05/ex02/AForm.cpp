/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 04:51:42 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/09/28 00:14:49 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void):_name("AForm"), _signed(false), _gradeSign(120), _gradeExecute(90)
{
	std::cout << "AForm: Default constructor called" << std::endl;
}

AForm::AForm(const std::string name, const int gradeSign,const int _gradeExecute):_name(name), _signed(false), _gradeSign(gradeSign), _gradeExecute(_gradeExecute)
{
	std::cout << "AForm: Constructor with parameter called" << std::endl;
	
	if(this->_gradeSign < 1 || this->_gradeExecute < 1)
		throw GradeTooHighException();
	if(this->_gradeSign > 150 || this->_gradeExecute > 150)
		throw GradeTooLowException();
}
	
AForm::AForm(AForm const &copy):_name(copy._name),  _signed(copy._signed), _gradeSign(copy._gradeSign), _gradeExecute(copy._gradeExecute)
{
	std::cout << "AForm: Copy constructor called" << std::endl;
	*this = copy;
}

AForm::~AForm(void)
{
	std::cout << "AForm: Destructor called" << std::endl;
}

AForm &AForm::operator=(AForm const &rhs)
{
	std::cout << "AForm: Copy assignment operator" << std::endl;

	if (this != &rhs)
	{
		this->_signed = rhs._signed;
	}
	return (*this);
}

std::string AForm::getName(void) const
{
	return (this->_name);
}

int AForm::getGradeSign(void) const
{
	return (this->_gradeSign);
}

int AForm::getGradeExecute(void) const
{
	return (this->_gradeExecute);
}

bool AForm::getSigned(void) const
{
	return (this->_signed);
}

void AForm::setSigned(bool s) 
{
	this->_signed = s;
}

void AForm::beSigned(Bureaucrat &bureaucrat)
{
	if(bureaucrat.getGrade() <= this->getGradeSign())
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

void  AForm::checkExecute(Bureaucrat const &bureaucrat) const
{
	if(bureaucrat.getGrade() > this->_gradeExecute)
		throw AForm::GradeTooLowException();
	if(!this->_signed)
		throw AForm::NotSignedException();
}



const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too hight");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}


const char *AForm::NotSignedException::what() const throw()
{
	return ("Is not signed.");
}

std::ostream &operator<<(std::ostream &o, AForm const &aform)
{
	if(aform.getSigned())
		o << aform.getName() << "is signed, grade sign " << aform.getGradeSign() << ", grade execute " << aform.getGradeExecute() <<"." << std::endl;
	else
		o << aform.getName() << "is not signed, grade sign " << aform.getGradeSign() << ", grade execute " << aform.getGradeExecute() <<"." << std::endl;
	return (o);
} 