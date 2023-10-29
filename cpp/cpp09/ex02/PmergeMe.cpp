/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 07:12:55 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/29 05:27:09 by ryoshio-         ###   ########.fr       */
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
    std::vector<int> vchain;
    std::vector<int> vpend;
    std::vector<int> index;
    int n, i, j, value;

    i = 3000;
    while( i > 0){
        
        v.push_back(i);
        i--;
    }
    
    iter(v.data(), v.size(), printElement<int>);
    std::cout << std::endl;
    sortPair(v);
    
    
 

   
    
    createChainPend(v, vchain, vpend);
    

    sortChain(vchain, vpend);
    


    n = vpend.size();
    index = _indexJacobsthal(n);
    
    i = 0;
    while(i < n){
        value = vpend[index[i] - 1];
        j = 0;
        while(vchain[j] < value && vchain[j])
            j++;
        vchain.insert(vchain.begin() + j, value);
        i ++;
    }
    
    std::cout <<"|" <<std::endl;
     iter(vchain.data(), vchain.size(), printElement<int>);
      std::cout <<"|" <<std::endl;
} 


void PmergeMe::sortDeque(void){ // tem que fazer tramento aqui dentro 
    std::deque<int> d;
    std::deque<int> dchain;
    std::deque<int> dpend;
    
    d.push_back(5);
    d.push_back(4);
    d.push_back(3);
    d.push_back(2);
    d.push_back(1);
    
    sortPair(d);

    createChainPend(d, dchain, dpend);

    iter(d, d.size(), printElement<int>);

     std::cout << std::endl;
     iter(dchain, dchain.size(), printElement<int>);
    std::cout << std::endl;
     iter(dpend, dpend.size(), printElement<int>);

    sortChain(dchain, dpend);

    std::cout << std::endl;
     iter(dchain, dchain.size(), printElement<int>);
    std::cout << std::endl;
     iter(dpend, dpend.size(), printElement<int>);

  
} 



std::vector<int> PmergeMe::_indexJacobsthal(size_t n){
    std::vector<int> index;
    int i = 0;
    int jaco1;
    int jaco2;
    
    while( index.size() < n){
        jaco1 = jacobsthal(i);
        jaco2 = jacobsthal(i + 1);
        
        while(jaco2  > jaco1){
            if( jaco2 <= (int) n)
                index.push_back(jaco2);
                
            jaco2 --;
        }
        i ++;
    }
    return(index);
}



int jacobsthal(int n) {
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