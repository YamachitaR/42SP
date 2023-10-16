/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 19:02:58 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/15 19:53:40 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"


void canonical(void){
	MutantStack<int> dish;
	
	dish.push(9);
	std::cout << "dish: "  << dish.top() << std::endl;
	
	MutantStack<int> copyConstructor(dish);
	std::cout << "copyConstructor: " << copyConstructor.top() << std::endl;
	
	MutantStack<int> copyOperator;
	copyOperator = dish;
	std::cout << "copyOperator: " << copyOperator.top() << std::endl;
}


void pdf(void){
	MutantStack<int> mstack;
	
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	
	++it;
	--it;
	
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);
	std::cout<< "size: " << s.size() << "=" << mstack.size() << std::endl;
	std::cout<< "top: " << s.top() << "=" << mstack.top() << std::endl;
	mstack.push(3);
	s.push(3);
	std::cout<< "top: " << s.top() << "=" << mstack.top() << std::endl;
	
	while(!mstack.empty()){
		std::cout<< "top: " << s.top() << "=" << mstack.top() << std::endl;
		s.pop();
		mstack.pop();
	}
	if(!s.empty())
		std::cout << "they are not similar" << std::endl;
}

void comparison(void){
	MutantStack <int> ms;
	std::list<int> lst;

	ms.push(2);
	lst.push_back(2);
	
	ms.push(5);
	lst.push_back(5);

	ms.push(9);
	lst.push_back(9);

	std::cout << "===> Iterator " << std::endl;
	MutantStack<int>::iterator ms_it = ms.begin();
	MutantStack<int>::iterator ms_ite = ms.end();

	std::list<int>::iterator lst_it = lst.begin();
	std::list<int>::iterator lst_ite = lst.end();

	++ms_it;
	--ms_it;
	
	++lst_it;
	--lst_it;
	
	while (ms_it != ms_ite)
	{
		std::cout << *ms_it << "=" << *lst_it << std::endl;
		++ms_it;
		++lst_it;
	}
	if(lst_it != lst_ite)
		std::cout << "they are not similar" << std::endl;

	std::cout << "===>Reverse Iterator " << std::endl;
	MutantStack<int>::reverse_iterator msr_it = ms.rbegin();
	MutantStack<int>::reverse_iterator msr_ite = ms.rend();
	std::list<int>::reverse_iterator lstr_it = lst.rbegin();
	std::list<int>::reverse_iterator lstr_ite = lst.rend();
	while (msr_it != msr_ite)
	{
		std::cout << *msr_it << "=" << *lstr_it << std::endl;
		++msr_it;
		++lstr_it;
	}
	if(lstr_it != lstr_ite)
		std::cout << "they are not similar" << std::endl;	
}


int main(void)
{
	std::cout << "====|Canonical|====" << std::endl;
	canonical();
	std::cout << "====|End|====" << std::endl;

	std::cout << "====|PDF|====" << std::endl;
	pdf();
	std::cout << "====|End|====" << std::endl;

	std::cout << "====|MutantStack VS List|====" << std::endl;
	comparison();
	std::cout << "====|End|====" << std::endl;
	
	return(0);
}