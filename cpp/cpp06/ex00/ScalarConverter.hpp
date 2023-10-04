/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:26:09 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/03 15:46:01 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ScalarConverter_HPP
#define ScalarConverter_HPP

#include <cmath>
#include <iostream>
#include <cstdlib> 
#include <climits>
#include <iomanip>

class ScalarConverter
{
	private:
		static char _char;
		static int _int;
		static float _float;
		static double _double;

		static std::string _checkType(const std::string &str);
		static void _charTo(char c);
		static void _intTo(int n);
		static void _floatTo(float n);
		static void _doubleTo(double n);
		
		static void _print(std::string code, long long int nbr);
	
		ScalarConverter(void);
		ScalarConverter (const ScalarConverter &copy);
		~ScalarConverter(void);
		ScalarConverter &operator= (ScalarConverter const &rhs);
		
	public:
		static void convert(std::string str); 
};

#endif