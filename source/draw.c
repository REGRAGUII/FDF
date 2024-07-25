/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <youssef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:17:26 by yregragu          #+#    #+#             */
/*   Updated: 2024/07/25 21:40:18 by youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void draw_map(t_data *fdf)
{
    int x;
    int y;
    int color;

	x = 0;
	y = 0;
	
    while (y < fdf->map->ordinate)
    {
        x = 0;
        while (x < fdf->map->abscissa)
        {
			color = fdf->map->matrix[y][x][1];
			if(color == -1)
				color = 0xFFFFFF;
			printf("altitude %d\n", fdf->map->matrix[y][x][0]);
			// printf("color is  %d \n",color);
            my_mlx_pixel_put(fdf, x * 6, y * 6, color);
            x++;
        }
        y++;
    }
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}