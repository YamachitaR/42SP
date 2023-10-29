/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 07:13:01 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/29 04:05:05 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <cstring>
#include <deque>
#include <vector>
#include <algorithm>
#include <sys/time.h>
#include <iomanip>

class PmergeMe
{
    private:
    
        std::vector<int> _indexJacobsthal(size_t n);
        
	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const &copy);
		~PmergeMe(void);

		PmergeMe &operator=(PmergeMe const &rhs);

        void sortVector(void); //fazer o tratamento dentro 
        void sortDeque(void);

};


int  jacobsthal(int n);
bool errorMessage(std::string str);

template <typename T>
void swap(T &a, T &b)
{
    T tmp;
    
    tmp = a;
    a = b;
    b = tmp;
}


template <typename T>
void iter(T *array,  size_t n,  void (*f)(T) )
{
	size_t i;
	
	if(!array || !f)
		return;
	
	i = 0;
	while(i < n)
	{
		f(array[i]);
		i ++;
	}
}

template <typename T>
void iter(const std::deque<T>& deq,  size_t n, void (*f)(T)) {

    size_t i = 0;
    while(i < n) {
        f(deq[i]);
        i++;
    }
}


template <typename T>
void printElement(T element) {
    std::cout << element << " ";
}

template <typename T>
void sortPair(T &a) {
    size_t i;
    
    i = 1;
    while(i < a.size()){
        if(a[i - 1] > a[i])
            swap(a[i -1], a[i]);
        i+=2;
    }
}

template <typename T>
void createChainPend(T &a, T &chain, T &pend){
    size_t i = 1;
    
    while(i < a.size()){
        chain.push_back(a[i-1]);
        pend.push_back(a[i]);
        i += 2;
    } 
    if(a.size() % 2 ==1)
        pend.push_back(a[i -  1]);
}

template <typename T>
bool isSort(T &a){
    size_t i = 1;
    while(i < a.size()) {
        if(a[i-1] > a[i])
            return(false);
        i++;
    }
    return(true);
}

template <typename T>
void sortChain(T &chain, T &pend){
    size_t i = 1;
    while(!isSort(chain)) {
        if(i == chain.size())
            i = 1;
        if(chain[i-1] > chain[i])
        {
           swap(chain[i-1], chain[i]);   
           swap(pend[i-1], pend[i]); 
        }      
        i++;
    }
}




#endif