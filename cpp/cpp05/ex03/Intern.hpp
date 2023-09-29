/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 00:57:03 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/09/29 19:03:14 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Intern_hpp
#define Intern_hpp

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

class Intern
{
	private:
		AForm *_shrubbery(const std::string target) const;
		AForm *_robotomy(const std::string target) const;
		AForm *_presidential(const std::string target) const;

	public:
		Intern(void);
		~Intern(void);

		AForm *makeForm(const std::string name, const std::string target) const;

		class InvalidFormException: public std::exception{
			public:
				const char *what() const throw(); 	
		};
};

#endif 