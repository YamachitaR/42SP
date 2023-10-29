/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 07:13:18 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/29 18:11:01 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, const char **argv) {
    clock_t start;
    clock_t timeVec;
    clock_t timeDeq;
    std::vector<int> vec;
    std::deque<int> deq;
    
    PmergeMe a;
    
    if(!checkArgc(argc))
        return(1);

    if(!checkArgv(argc, argv))
        return(1);
    
    start = clock();
    vec = a.sortVector(argv);
    timeVec = clock() - start;
    
    start = clock();
    deq = a.sortDeque(argv);
    timeDeq = clock() - start;
    
    iter(deq, 3 ,printElement);
    
    std::cout << timeVec << timeDeq << std::endl; 
    return 0;
}


