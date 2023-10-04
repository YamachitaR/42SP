/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 14:26:05 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/03 01:19:16 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ScalarConverter.hpp"

char		ScalarConverter::_char = 0;
int			ScalarConverter::_int = 0;
double		ScalarConverter::_double = 0;
float		ScalarConverter::_float = 0;

ScalarConverter::ScalarConverter(void){
	std::cout << "ScalarConverter: Default constructor called" << std::endl;
}


ScalarConverter::ScalarConverter(ScalarConverter const &copy)
{
	std::cout << "ScalarConverter: Copy constructor called" << std::endl;
	_char = copy._char;
	_int = copy._int;
	_float = copy._float;
	_double = copy._double;
	*this = copy;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << "ScalarConverter: Destructor called" << std::endl;
}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs)
{
	std::cout << "ScalarConverter: Copy assignment operator" << std::endl;

	if (this != &rhs)
	{
		_char = rhs._char;
		_int = rhs._int;
		_float = rhs._float;
		_double = rhs._double;
	}
	return (*this);
}

void ScalarConverter::convert(std::string str)
{
	std::string code;

	code =  _checkType(str);
	
	if( code == "char")
	{
		_charTo(str[0]);
	}else if(code =="int")
	{
		int i = atoi(str.c_str());
		_intTo(i);
	}else if(code =="float")
	{
		float i = static_cast<float>(atof(str.c_str()));
		_floatTo(i);
	}else if(code =="double")
	{
		 double i = atof(str.c_str());
		_doubleTo(i);
		
	}
	_print(code, std::atoll(str.c_str()));
}



std::string ScalarConverter::_checkType(const std::string &str)
{
	size_t  i;
	
	if(str.length() == 1)
	{
		if(str[0] >= '0' && str[0] <= '9' )
			return ("int");
		return ("char");
	}
	if(str =="-inff" || str =="+inff" || str == "nanf" || str == "inff")
		return ("float");
	if(str =="-inf" || str =="+inf" || str == "nan" || str == "inf")
		return ("double");
	i = 0;
	if(str[0] == '+' || str[0] == '-')
		i++;
	while(i < str.length())
	{
		if(str[i] < '0' || str[i] > '9' )
			break;
		i ++;
	}
	if(str[i] == '\0')
		return ("int");
	if(str[i] == 'f' && str[i +1] == '\0')
		return ("float");
	if(str[i]=='.')
		i++;
	else
		return("strange");
	while(i < str.length())
	{
		if(str[i] < '0' || str[i] > '9' )
			break;
		i ++;
	}
	if(str[i]== '\0' )
		return ("double");
	if(str[i] == 'f' && str[i +1] == '\0')
		return ("float");
	return ("strange");	 
}

void ScalarConverter::_charTo(char c)
{
	_char = static_cast<char>(c);
	_int = static_cast<int>(c);
	_float = static_cast<double>(c);
	_double  = static_cast<float>(c);
}

void ScalarConverter::_intTo(int n)
{
	_char = static_cast<char>(n);
	_int = static_cast<int>(n);
	_float = static_cast<float>(n);
	 _double  = static_cast<double>(n);
}

void ScalarConverter::_floatTo(float n)
{
	_char = static_cast<char>(n);
	_int = static_cast<int>(n);
	_float = static_cast<float>(n);
	_double  = static_cast<double>(n);
}

void ScalarConverter::_doubleTo(double n)
{
	_char = static_cast<char>(n);
	_int = static_cast<int>(n);
	_float = static_cast<float>(n);
	_double  = static_cast<double>(n);
}

void ScalarConverter::_print(std::string code, long long int nbr)
{
	std::cout << std::fixed << std::setprecision(1);
	if(code == "strange")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
		return;
	}

	if( nbr < 0 || nbr > 127 || std::isinf(_float) || std::isnan(_float))
		std::cout << "char: impossible" << std::endl;
	else if (_char > 32 && _char < 127)
		std::cout << "char: " << _char << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	if( nbr >=  INT_MIN && nbr <=  INT_MAX)
	{
		if(!std::isinf(_float) && !std::isnan(_float))
			std::cout << "int: " << _int << std::endl;
		else
			std::cout << "int: impossible" << std::endl;

		std::cout << "float: " << _float << "f" << std::endl;
		std::cout << "double: " << _double << std::endl;
		
	}
	else
	{
		std::cout << "int: impossible" << std::endl;
		if(code == "int")	
		{
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
		}else{
			std::cout << "float: " << _float << "f" << std::endl;
			std::cout << "double: " << _double << std::endl;
		}
	}
}