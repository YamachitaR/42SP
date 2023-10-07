/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 22:06:07 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/05 20:05:49 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	int intArray[] = {1, 2, 3, 4,5 ,6, 7, 8, 9};
	float floatArray[] = {1.1f, 2.6, 3.7, 4.5, 5.6, 6, 7, 8, 9};
	std::string stringArray[] = {"dog", "cat", "bird"};

	print("================================");
	iter(intArray, 9, print);
	
	print("================================");
	iter(floatArray, 9, print);

	print("================================");
	iter(stringArray, 3, print);
	return(0);
}