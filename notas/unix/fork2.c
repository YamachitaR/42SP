/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 02:25:43 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/04/12 03:17:33 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int main(void)
{
	fork();
	fork();
	
	printf("Quantas vezes eu vou aparecer?\n");
	return(0);
}

/*
Parece que só  é possivel numero para de fork
Analisar com calma

fork |printf
1    | 2
2	 | 4
3    | da erro
4    |7


*/