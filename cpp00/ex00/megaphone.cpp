/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 22:54:07 by ryoshio-          #+#    #+#             */
/*   Updated: 2023/04/15 02:02:41 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(int argc, char **argv)
{
	int i;
	int j;

	if (argc < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 1;
		while(argv[i])
		{
			j = 0;
			while(argv[i][j])
			{
				if(argv[i][j] >= 'a' && argv[i][j] <= 'z') 
					std::cout << (char)(argv[i][j] - 32);
				else 
					std::cout << argv[i][j];
				j++;
			}
			i ++;
		}
		std::cout << std::endl;
	}
	return (0);
}