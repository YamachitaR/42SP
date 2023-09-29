/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 04:51:47 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/09/20 23:42:00 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Form_HPP
#define Form_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int 			_gradeExecute;
	
	public:
		Form(void);
		Form(const std::string name, const int gradeSign, const int _gradeExecute);
		Form(Form const &copy);
		~Form(void);

		std::string getName(void) const;

		int getGradeSign(void) const;

		int getGradeExecute(void) const;

		bool getSigned(void) const;
		void setSigned(bool s);
		
		Form &operator=(Form const &rhs);

		void beSigned(Bureaucrat &bureaucrat); 

		class GradeTooHighException: public std::exception
		{
			public:
				const char *what() const throw(); 	
		}; 

		class GradeTooLowException: public std::exception
		{
			public:
				const char *what() const throw(); 	
		}; 
};

std::ostream &operator<<(std::ostream &o, Form const &form);

#endif