/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 07:12:55 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/29 06:51:17 by ryoshio-         ###   ########.fr       */
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

template <typename T>
void PmergeMe::_sortPair(T &a) {
    size_t i;
    
    i = 1;
    while(i < a.size()){
        if(a[i - 1] > a[i])
            swap(a[i -1], a[i]);
        i+=2;
    }
}

template <typename T>
void PmergeMe::_createChainPend(T &a, T &chain, T &pend){
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
void PmergeMe::_sortChain(T &chain, T &pend){
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

void PmergeMe::sortVector(void){ // tem que fazer tramento aqui dentro 
    std::vector<int> v;
    std::vector<int> vchain;
    std::vector<int> vpend;
    std::vector<int> index;
    int n, i, j, value;

    i = 5;
    while( i > 0){
        
        v.push_back(i);
        i--;
    }
    
    iter(v.data(), v.size(), printElement<int>);
    std::cout << std::endl;
    _sortPair(v);
    _createChainPend(v, vchain, vpend);
    _sortChain(vchain, vpend);

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
     iter(vpend.data(), vpend.size(), printElement<int>);
    std::cout << std::endl;
       std::cout << std::endl;
    iter(index.data(), index.size(), printElement<int>);
   
} 


void PmergeMe::sortDeque(void){ // tem que fazer tramento aqui dentro 

    std::deque<int> d;
    std::deque<int> dchain;
    std::deque<int> dpend;
     std::vector<int> index;
    int n, i, j, value;

    

    d.push_back(5);
    d.push_back(4);
    d.push_back(3);
    d.push_back(2);
    d.push_back(1);
    
    _sortPair(d);
    _createChainPend(d, dchain, dpend);
    _sortChain(dchain, dpend);

iter(d, d.size(), printElement<int>);
    



    n = dpend.size();
    index = _indexJacobsthal(n);
    i = 0;
    while(i < n){
        value = dpend[index[i] - 1];
        j = 0;
        while(dchain[j] < value && dchain[j])
            j++;
        dchain.insert(dchain.begin() + j, value);
        i ++;
    }


    
    std::cout << std::endl;
    iter(dchain, dchain.size(), printElement<int>);
   std::cout << std::endl;
    iter(dpend, dpend.size(), printElement<int>);
     std::cout << std::endl;
    iter(index.data(), index.size(), printElement<int>);

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
bool isSort(T &a){
    size_t i = 1;
    while(i < a.size()) {
        if(a[i-1] > a[i])
            return(false);
        i++;
    }
    return(true);
}