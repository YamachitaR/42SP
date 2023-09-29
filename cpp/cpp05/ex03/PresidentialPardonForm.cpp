/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 01:12:21 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/09/29 17:55:39 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void):AForm("Presidential", 25, 5), _target("Presidential")
{
	std::cout << "PresidentialPardonForm: Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):AForm(target, 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm: Constructor with parameter called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy):AForm()
{
	std::cout << "PresidentialPardonForm: Copy constructor called" << std::endl;
	*this =  copy;	
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "PresidentialPardonForm: Destructor called" << std::endl;
}


PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &copy)
{
	std::cout << "PresidentialPardonForm: Copy assignment operator" << std::endl;
	if (this != &copy)
	{
		this->_target = copy._target;
	}
	return (*this);
}

int PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	this->checkExecute(executor);
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
	return (1);
}