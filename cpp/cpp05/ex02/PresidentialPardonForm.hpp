/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 01:12:27 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/09/28 01:43:06 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PresidentialPardonForm_hpp
#define PresidentialPardonForm_hpp

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
	private: 
		std::string _target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm(void);

		PresidentialPardonForm &operator=(PresidentialPardonForm const &copy);

		int execute(Bureaucrat const & executor) const; 
};

#endif 