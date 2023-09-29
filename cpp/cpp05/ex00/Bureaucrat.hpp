/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 23:43:06 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/09/19 03:51:50 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Bureaucrat_HPP
#define Bureaucrat_HPP

#include <iostream>
#include <exception>


class Bureaucrat
{
	private:
		 const std::string	_name;
		 int				_grade;
		
	public:
		Bureaucrat(void);
		Bureaucrat (const Bureaucrat &copy);
		Bureaucrat(std::string str, int grade);
		~Bureaucrat(void);
		
		Bureaucrat &operator= (Bureaucrat const &rhs);

		std::string getName(void) const;
		int			getGrade(void) const;

		void increment (void);
		void decrement (void);
		
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

std::ostream &operator<<(std::ostream &o, Bureaucrat const &bureaucrat);



#endif