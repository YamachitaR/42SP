/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 04:51:47 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/09/27 23:41:10 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed;
		const int			_gradeSign;
		const int 			_gradeExecute;
		
	
	public:
		AForm(void);
		AForm(const std::string name, const int gradeSign, const int _gradeExecute);
		AForm(AForm const &copy);
		virtual ~AForm(void);

		std::string getName(void) const;

		int getGradeSign(void) const;

		int getGradeExecute(void) const;

		bool getSigned(void) const;
		void setSigned(bool s);
		
		AForm &operator=(AForm const &rhs);

		void beSigned(Bureaucrat &bureaucrat);

		void checkExecute(Bureaucrat const &bureaucrat) const;
		virtual int execute(Bureaucrat const &executor) const = 0; 

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

		
		class NotSignedException: public std::exception
		{
			public:
				const char *what() const throw(); 	
		};

		
};

std::ostream &operator<<(std::ostream &o, AForm const &aform);

#endif