/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 22:06:28 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/05 20:07:41 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef iter_HPP
# define iter_HPP

#include <iostream>

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
void print(T a)
{
	std::cout << a << std::endl;
}

#endif