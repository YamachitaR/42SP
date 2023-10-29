/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 07:12:55 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/29 00:36:31 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void){ 
    std::cout << "PmergeMe: Default constructor called" << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const & copy)
{
    std::cout << "PmergeMe: Copy constructor called" << std::endl;
	*this = copy;
}

PmergeMe::~PmergeMe(void){ 
    std::cout << "PmergeMe: Destructor called" << std::endl;
}


PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
    std::cout << "PmergeMe : Copy assignment operator" << std::endl;
	if ( this != &rhs )
	{
	}
	return *this;
}

void PmergeMe::sortVector(void){ // tem que fazer tramento aqui dentro 
    std::vector<int> v;

    v.push_back(5);
    v.push_back(4);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    
    iter(v.data(), v.size(), printElement<int>);
    std::cout << std::endl;
    sortPair(v);
     
    iter(v.data(), v.size(), printElement<int>);
    std::cout << std::endl;
} 


void PmergeMe::sortDeque(void){ // tem que fazer tramento aqui dentro 
    std::deque<int> d;

    d.push_back(5);
    d.push_back(4);
    d.push_back(3);
    d.push_back(2);
    d.push_back(1);
    
    sortPair(d);

    
} 




int  jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}


bool errorMessage(std::string str){
	std::cout << "Error: " << str << std::endl;
	return(false);
}