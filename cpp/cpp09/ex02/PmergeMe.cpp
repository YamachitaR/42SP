/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 07:12:55 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/29 19:26:50 by ryoshio-         ###   ########.fr       */
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

std::vector<int> PmergeMe::sortVector(const char **argv){ 
    std::vector<int> v;
    std::vector<int> vchain;
    std::vector<int> vpend;
    std::vector<int> index;
    int n, i, j, value;

    i = 1;
    while(argv[i]){
        v.push_back(atoi(argv[i]));
        i++;
    }
    
    if(isSort(v))
        return (v);
     
    _sortPair(v);
    
    if(isSort(v))
        return (v);
    
    _createChainPend(v, vchain, vpend);
    _sortChain(vchain, vpend);
    
    n = vpend.size();
    index = _indexJacobsthal(n);
   
    i = 0;
    while(i < n){
        value = vpend[index[i] - 1];
        j = 0;
        if(value > vchain.back())
        {
            vchain.push_back(value);
            i++;
            continue;
        }
        while(vchain[j] < value && j < (int)vchain.size())
            j++;
        vchain.insert(vchain.begin() + j, value);
        i ++;
    }

    return (vchain);
} 

std::deque<int> PmergeMe::sortDeque(const char **argv){
    std::deque<int> d;
    std::deque<int> dchain;
    std::deque<int> dpend;
    std::vector<int> index;
    int n, i, j, value;

    i = 1;
    while(argv[i]){
        d.push_back(atoi(argv[i]));
        i++;
    }
    
    if(isSort(d))
        return (d);
   
    _sortPair(d);

    if(isSort(d))
        return (d);
    
    _createChainPend(d, dchain, dpend);
    _sortChain(dchain, dpend);

    n = dpend.size();
    index = _indexJacobsthal(n);
    i = 0;
    while(i < n){
        value = dpend[index[i] - 1];
        j = 0;
        
        if(value > dchain.back())
        {
            dchain.push_back(value);
            i++;
            continue;
        }
        if(value < dchain.front())
        {
            dchain.push_front(value);
            i++;
            continue;
        }
        while(dchain[j] < value && j < (int) dchain.size())
            j++;
        dchain.insert(dchain.begin() + j, value);
        i ++;
    }
    return (dchain);
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

bool checkArgc(const int argc){
	if(argc < 2)
		return (errorMessage("invalid number of arguments! \nExample: ./PmergeMe \"1 2 3\" "));
	return (true);
}

bool checkArgv(const int argc, const char **argv){
    int  i;

    i = 1;
    while(i < argc){
        if(!isIntegerPositive(argv[i]))
            return (errorMessage("Invalid argument"));
        i ++;
    }
	return (true);
}

bool isIntegerPositive(std::string str){
	size_t i;

	i = 0;
	
	if(str.empty())
		return(false);
		
	if(str[i] == '+'){
		i ++;
		if(!std::isdigit(str[i]))
			return (false);
		i ++;
	}
		
	while (i <  str.length()){
		if(!std::isdigit(str[i]))
			return (false);
		i ++;
	}
	return (true);
}
