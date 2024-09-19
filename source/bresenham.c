/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 13:03:58 by yregragu          #+#    #+#             */
/*   Updated: 2024/08/02 12:55:33 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	bres_helper(int x0, int y0, t_data *fdf)
{
	fdf->bres->dx = abs(fdf->dim->x1 - x0);
	fdf->bres->dy = abs(fdf->dim->y1 - y0);
	fdf->bres->sx = -1;
	fdf->bres->sy = -1;
	if (x0 < fdf->dim->x1)
		fdf->bres->sx = 1;
	if (y0 < fdf->dim->y1)
		fdf->bres->sy = 1;
	fdf->bres->err = fdf->bres->dx - fdf->bres->dy;
}

void	bresenham(int x0, int y0, t_data *fdf, int color)
{
	bres_helper(x0, y0, fdf);
	while (1)
	{
		if (x0 > 0 && y0 > 0 && x0 <= WIDTH && y0 <= HEIGHT)
			my_mlx_pixel_put(fdf, x0, y0, color);
		if (x0 == fdf->dim->x1 && y0 == fdf->dim->y1)
			break ;
		fdf->bres->e2 = fdf->bres->err * 2;
		if (fdf->bres->e2 > -fdf->bres->dy)
		{
			fdf->bres->err -= fdf->bres->dy;
			x0 += fdf->bres->sx;
		}
		if (fdf->bres->e2 < fdf->bres->dx)
		{
			fdf->bres->err += fdf->bres->dx;
			y0 += fdf->bres->sy;
		}
	}
}
