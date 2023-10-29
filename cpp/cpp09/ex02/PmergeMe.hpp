/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 07:13:01 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/29 18:16:53 by ryoshio-         ###   ########.fr       */
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
        
        template <typename T>
        void _sortPair(T &a);

        template <typename T>
        void _createChainPend(T &a, T &chain, T &pend);

        template <typename T>
        void _sortChain(T &chain, T &pend);
        
	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const &copy);
		~PmergeMe(void);

		PmergeMe &operator=(PmergeMe const &rhs);

        std::vector<int> sortVector(const char **argv); 
        std::deque<int> sortDeque(const char **argv);
};

int  jacobsthal(int n);
bool errorMessage(std::string str);
bool checkArgc(const int argc);
bool checkArgv(const int argc, const char **argv);
bool isIntegerPositive(std::string str);

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
    while(i < n){
        f(deq[i]);
        i++;
    }
}

template <typename T>
void printElement(T element) {
    std::cout << element << " ";
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
#endif