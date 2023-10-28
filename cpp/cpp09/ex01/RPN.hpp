/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 07:10:43 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/28 16:43:07 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>
#include <cctype>
#include <cstdlib>

class RPN {
	private:
		bool _isOperator(const std::string& token);
		double _operation(double nbr1, double nbr2, std::string const &token);

	
		
	public:
		RPN(void);
		~RPN(void);
		RPN(RPN const &copy);

		RPN& operator=(RPN const &rhs);
		double calculation(const std::string& str);
	
};

bool checkArgc(const int argc);
bool errorMessage(std::string str);

bool isInteger(std::string str);
bool isFloat(std::string str);

#endif