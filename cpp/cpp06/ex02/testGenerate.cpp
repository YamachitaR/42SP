/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testGenerate.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 22:11:32 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/03 22:35:27 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.hpp"

void testGenerate(void)
{
	int i = 0;

	while(i < 10)
	{
		Base *a;
		a = generate();
		identify(a);
		delete a;
		i++;
	}	
}