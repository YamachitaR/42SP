/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 07:12:55 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/28 23:03:15 by ryoshio-         ###   ########.fr       */
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
    std::vector<int> vector = {1, 2, 3, 4, 5};
    
    int i;
    
    // forma o par 
    i = 0;
    while(i < vector.size() - 1){
        if(vector.size() % 2 == 1  && i >= vector.size() - 2)
            break;
        
        
    }
    

    
} 



int  jacobsthal(int n)
{
	if (n == 0)
		return (0);
	if (n == 1)
		return (1);
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}
