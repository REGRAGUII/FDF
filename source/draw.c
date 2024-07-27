/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: youssef <youssef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:17:26 by yregragu          #+#    #+#             */
/*   Updated: 2024/07/27 19:21:08 by youssef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}


float rad(float deg)
{
	return(deg * PI / 180);
}




void draw_map(t_data *fdf)
{
    int x;
    int y;
	float x1;
	float y1;
    int color;
	float angle;
	int z;

	x = 0;
	y = 0;
	angle = rad(30);
    while (y < fdf->map->ordinate)
    {
        x = 0;
        while (x < fdf->map->abscissa)
        {
			z = fdf->map->matrix[y][x][0];
			printf("z :  %d\n", fdf->map->matrix[y][x][0]);
			color = fdf->map->matrix[y][x][1];
			if(color == -1)
				color = 0xFFFFFF;
			// printf("color is  %d \n",color);
			// mlx_pixel_put(fdf->mlx, fdf->win, x , y, color);
			x1 = x;
			y1 = y;
			// x1 = x * (cos(angle) + sin(angle)) - y * (sin(angle)  ;
			// y1 = x1 * sin(angle)+ y1 * sin(angle*2) + z * sin(angle);
			x1 = (x - y) * cos(angle);
			y1 = (x + y) * sin(angle) - z;
			x1 += 450;
			y1 += 100;
			printf("x : %f || y : %f\n", x1, y1);
			my_mlx_pixel_put(fdf, x1 * 2, y1 * 2, color);
            // mlx_pixel_put(fdf->mlx, fdf->win, x1 * 2, y1 * 2, color);
			x++;
        }
        y++;
    }
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
