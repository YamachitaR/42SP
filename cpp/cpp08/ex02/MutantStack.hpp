/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:48:26 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/15 17:57:22 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MutantStack_hpp
#define MutantStack_hpp

#include <iostream>
#include <stack>
#include <iterator>
#include <vector>
#include <list>


template <typename T>
class MutantStack: public std::stack<T> {
	
	public: 		
		MutantStack(void):std::stack<T>(){
			std::cout << "MutantStack: Default constructor called" << std::endl;
		}
		
		MutantStack(MutantStack const &copy):std::stack<T>(copy){
			std::cout << "MutantStack: Copy constructor called" << std::endl;	
		}
		
		~MutantStack (void){
			std::cout << "MutantStack:  Destructor called" << std::endl;
		}

		MutantStack &operator=(MutantStack const &rhs){	
			std::cout << "MutantStack: Copy assignment operator" << std::endl;

			if (this != &rhs){
				std::stack<T>::operator=(rhs);
			}
			
			return (*this);
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;
		iterator  begin(void){
			return(this->c.begin());
		}
		
		iterator  end(void){
			return(this->c.end());
		}

		typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
		reverse_iterator  rbegin(void){
			return(this->c.rbegin());
		}
		
		reverse_iterator  rend(void){
			return(this->c.rend());
		}

};

#endif