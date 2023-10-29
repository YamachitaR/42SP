/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 07:13:01 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/29 06:08:35 by ryoshio-         ###   ########.fr       */
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

        void sortVector(void); //fazer o tratamento dentro 
        void sortDeque(void);
};

int  jacobsthal(int n);
bool errorMessage(std::string str);

template <typename T>
void swap(T &a, T &b);

template <typename T>
void iter(T *array,  size_t n,  void (*f)(T));

template <typename T>
void iter(const std::deque<T>& deq,  size_t n, void (*f)(T));

template <typename T>
void printElement(T element);

template <typename T>
bool isSort(T &a);


#endif