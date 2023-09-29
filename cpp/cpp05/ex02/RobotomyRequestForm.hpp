/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 22:42:07 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/09/27 23:41:30 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RobotomyRequestForm_hpp
#define RobotomyRequestForm_hpp

# include "AForm.hpp"
# include <cstdlib>
#include <ctime>

class RobotomyRequestForm: public AForm
{
	private: 
		std::string _target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm(void);

		RobotomyRequestForm &operator=(RobotomyRequestForm const &copy);

		int execute(Bureaucrat const & executor) const; 
};

#endif 