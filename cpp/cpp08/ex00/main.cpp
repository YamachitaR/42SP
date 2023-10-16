/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 00:02:00 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/13 02:14:41 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main(void)
{
	std::vector<int> v;
	std::vector<int>::iterator iter;
	int i;
	
	i = 0;
	while(i < 50)
	{
		v.push_back(i);
		i ++;
	}

	i = 0;
	while(i < 50)
	{
		iter = easyfind(v, i);
		std::cout <<"value:" << i <<", index:" << *iter << std::endl;
		i++;
	}
	
	try{
		iter = easyfind(v, 50);
	}catch(std::exception &e){
		std::cout << e.what() << std::endl;
	}
	
	return (0);
}
