/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 20:21:00 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/06 03:41:00 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef Array_HPP
# define Array_HPP

#include <iostream>
#include <exception>
# include <cstdlib>
#include <ctime>

template <typename T>
class Array 
{
	private:
		unsigned int _n;
		T*			_elements;
	
	public:
		Array(void)
		{
			this->_n = 0;
			this->_elements = NULL;
			std::cout << "Array: Default constructor called" << std::endl;
		}
		
		Array(unsigned int n)
		{
			this->_n = n;
			if(n > 0)
				this->_elements = new T[n];
			else 
				this->_elements = NULL;
			std::cout << "Array: Constructor with parameter called" << std::endl;
		}

		Array(Array const &copy)
		{
			this->_n = copy._n;
			if(this->_n > 0)
				this->_elements = new T[copy._n];
			else
				this->_elements = NULL;
			*this = copy;
			std::cout << "Array: Copy constructor called" << std::endl;
		}
		
		~Array(void)
		{
			delete [] this->_elements;
			std::cout << "Array: Destructor called" << std::endl;
		}

		Array &operator=(Array const &rhs)
		{
			unsigned int i;
			std::cout << "Array: Copy assignment operator" << std::endl;
			if(this != &rhs)
			{
				this->_n = rhs._n;
				delete[] this->_elements;
				if(this->_n > 0)
					this->_elements = new T[rhs._n];
				else
					this->_elements = NULL;
				i = 0;
				while(i < this->_n)
				{
					this->_elements[i] = rhs._elements[i];
					i ++;
				}
			}
			return(*this);
		}

		T &operator[](unsigned int n)
		{
			if(n < this->_n)
				return(this->_elements[n]);
			else
				throw IndexException();
		}

		unsigned int size(void) const
		{
			return (this->_n);
		}

		class IndexException: public std::exception
		{
			public: 
				const char *what() const throw()
				{
					return ("Index out of range!");
				} 
		};

};


#endif
