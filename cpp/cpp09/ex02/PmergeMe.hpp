/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 07:13:01 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/29 00:36:07 by ryoshio-         ###   ########.fr       */
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


#endif