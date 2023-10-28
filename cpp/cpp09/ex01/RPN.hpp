/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 07:10:43 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/28 07:46:29 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>


class RPN {
	private:
	
		
	public:
		RPN(void);
		RPN(std::string input);
		~RPN(void);
		RPN(RPN const &copy);

		RPN& operator=(RPN const &rhs);

		void	rpn();
	
};

bool checkArgc(const int argc);

bool errorMessage(std::string str);
#endif