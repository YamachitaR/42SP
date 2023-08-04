/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryoshio- <ryoshio-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 20:15:16 by ryoshio-          #+#    #+#             */
/*   Updated: 2022/02/15 20:28:13 by ryoshio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include "minilibx-linux/mlx.h"

typedef struct    s_data {
    void    *img;
    char    *addr;
    int        bits_per_pixel;
    int        line_length;
    int        endian;
}                t_data;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int    main(void)
{
    void    *mlx;
    void    *mlx_win;
    t_data    img;
    int n;
    int a;

    mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 750, 500, "Da um liga na diagonales");
    img.img = mlx_new_image(mlx, 750, 500);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
                                &img.endian);
    n = 0;
    a = 750;
    while (a >0 && n < 500)
    {
        my_mlx_pixel_put(&img, a, n, 0x00FF0000);
        a++;
        n++;
    }
        mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
    mlx_loop(mlx);
}