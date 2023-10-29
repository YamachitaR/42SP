/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 07:13:18 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/29 18:46:35 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, const char **argv) {
    clock_t start;
    double timeVec;
    double timeDeq;
    std::vector<int> vec;
    std::deque<int> deq;
    
    PmergeMe a;
    
    if(!checkArgc(argc))
        return(1);

    if(!checkArgv(argc, argv))
        return(1);
    
    start = clock();
    vec = a.sortVector(argv);
    timeVec = double(clock() - start) / CLOCKS_PER_SEC * 1000;
    
    start = clock();
    deq = a.sortDeque(argv);
    timeDeq = double(clock() - start) / CLOCKS_PER_SEC * 1000;
    
    std::cout << "Before: ";
    iter(argv + 1, argc - 1, printElement);
    std::cout << std::endl;
     
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector<int>: " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque<int>: " << timeDeq << " us" << std::endl;
    
    return 0;
}


