/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 22:42:09 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/03/09 05:09:27 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include <stdio.h>
#include <stdlib.h>
#include "minilibx-linux/mlx.h"

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode, t_vars *vars)
{
	//mlx_destroy_window(vars->mlx, vars->win);
    if (keycode == 65307) // esse numero é ESC
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free (vars->mlx);
		free (vars);
		exit (0);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "Hello world!");
    mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}

/*

Para rodar basta make arquivo = teste5.c

Este teste serve para demonstra como faz para fechar o programa 

Que faz essa magia é o mlx_hook

2 significa ao clicar( 	KeyPress), para ver outra opções clic na tabela x11events https://harm-smits.github.io/42docs/libs/minilibx/events.html
1L<<0 significa KeyPressMask (acho que depois de clicar)
close seria a função mensionando la em cima, 
quem faz fecha mesmo é mlx_destroy_window
Variavel keycode descofio que seja variavel global 
esse numero 65307 significa "esc"

*/