/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:51:19 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/03 22:21:18 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.hpp"

int main(void)
{
	std::cout << "===|Test Identify|===" << std::endl;
	testIdentify();
	
	std::cout << "===|Test Generate|===" << std::endl;
	testGenerate();
	return(0);
}