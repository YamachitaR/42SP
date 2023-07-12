/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 16:22:12 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/07/12 14:18:47 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Check.hpp"
#include "Replace.hpp" 

int main (int argc, char **argv)
{
	Check check(argc, argv);
	Replace replace(argv[1], argv[2], argv[3]);
	return (0);
}