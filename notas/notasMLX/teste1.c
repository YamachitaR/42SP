/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 03:16:08 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/02/14 04:28:29 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minilibx-linux/mlx.h"

int main (void)
{
	void *mlx_ptr;
	void *win_ptr;
	
	mlx_ptr = mlx_init(); //inicializa mlx
    
    // cria a janela, 
    // primeiro parametro ponteiro da inicalização do mlx
    // segundo e terceiro respecivamente largura e altura
    // ultimo parametro é o nome da aba
	win_ptr =mlx_new_window(mlx_ptr, 900, 500, "mlx 42");
	
    //para manter a janela aberto
	mlx_loop(mlx_ptr);


    return (0);
}