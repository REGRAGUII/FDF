/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:03:58 by yregragu          #+#    #+#             */
/*   Updated: 2024/07/30 00:49:28 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"



void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void	slope_less(int x, int y, int dx, int dy, t_data *data, int color)
{
	int p;
	int i;

	i = 0;
 	p = 2 * abs(dy) - abs(dx);
	// if (fdf->dim->x1 > 0 && fdf->dim->y1 > 0 && (fdf->dim->x1 <= WIDTH && fdf->dim->y1 <= HEIGHT ))
	// isometric(data, x, y, data->map->matrix[y][x][0]);
	// x = data->dim->x1;
	// y = data->dim->y1;
	my_mlx_pixel_put(data, x, y, color);
	// mlx_pixel_put(data->mlx, data->win, x, y, color);
	while (i < abs(dx))
 	{
		if (dx > 0)
  			x += 1;
		else
			x -= 1;
		if (p < 0)
			p = p + 2 * abs(dy);
		else
		{
			if(dy > 0)
				y += 1;
			else
				y -= 1;
			p = p + 2 * abs(dy) - 2 * abs(dx);
		}
		// if(y < data->map->ordinate)
		// {
		// 	isometric(data, x, y, data->map->matrix[y][x][0]);
		// 	x = data->dim->x1;
		// 	y = data->dim->y1;
		my_mlx_pixel_put(data, x, y, color);
		// mlx_pixel_put(data->mlx, data->win, x, y, color);
		i++;
	}
}
void	slope_big(int x, int y, int dx, int dy, t_data *data, int color)
{
 	int p;
 	int i;
	
 	i = 0;
 	p = 2 * dx - dy;
	
	// isometric(data, x, y, data->map->matrix[y][x][0]);
	// x = data->dim->x1;
	// y = data->dim->y1;
	// mlx_pixel_put(data->mlx, data->win, x, y, color);
	my_mlx_pixel_put(data, x, y, color);
	while (i < dy)
 	{
		y += 1;
		if (p < 0)
			p = p + 2 * dx;
		else
		{
			x += 1;
			p = p + 2 * dx - 2 * dy;
		}

			// isometric(data, x, y, data->map->matrix[y][x][0]);
			// x = data->dim->x1;
			// y = data->dim->y1;
			my_mlx_pixel_put(data, x, y, color);
		// mlx_pixel_put(data->mlx, data->win, x, y, color);
	
		i++;
 	}
}


void    bresenham(int x, int y, int next_x, int next_y, t_data *data, int color)
{
    int dx;
    int dy;

	// isometric(data, x, y, data->map->matrix[y][x][0]);
	// x = data->dim->x1;
	// y = data->dim->y1;
	// isometric(data, next_x, next_y, data->map->matrix[next_y][next_x][0]);
	// next_x = data->dim->x1;
	// next_y = data->dim->y1;
    dx = next_x - x;
    dy = next_y - y;
    if(dx > dy)
    	slope_big(x, y, dx, dy, data, color);
    else
        slope_less(x, y, dx, dy, data, color);
}