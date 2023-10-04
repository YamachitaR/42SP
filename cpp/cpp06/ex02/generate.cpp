/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:55:03 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/10/03 22:27:04 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib.hpp"

Base * generate(void)
{
	int random = std::rand() % 3;

	if(random == 0)
		return (new A);
	if(random == 1)
		return (new B);
	return (new C);
}