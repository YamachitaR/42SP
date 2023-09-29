/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:42:02 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/09/29 17:54:54 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void):AForm("Robot", 72, 45), _target("Robot")
{
	std::cout << "RobotomyRequestForm: Default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):AForm(target, 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm: Constructor with parameter called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy):AForm()
{
	std::cout << "RobotomyRequestForm: Copy constructor called" << std::endl;
	*this =  copy;	
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "RobotomyRequestForm: Destructor called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &copy)
{
	std::cout << "RobotomyRequestForm: Copy assignment operator" << std::endl;
	if (this != &copy)
	{
		this->_target = copy._target;
	}
	return (*this);
}

int RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	this->checkExecute(executor);
	std::srand(std::time(0));
	std::cout << "Drilling noises... ";
	if(rand() % 2)
	{
		std::cout <<  this->_target <<" has been robotomized successfully " << std::endl;
		return (1);
	}	
	else 
	{
		std::cout <<  this->_target <<" fail to be robotized" << std::endl;
		return (2);
	}
}