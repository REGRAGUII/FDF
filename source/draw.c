/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:17:26 by yregragu          #+#    #+#             */
/*   Updated: 2024/07/30 14:07:15 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


void	iso_center(t_data *fdf, int x, int y, int z)
{
	float	space;
	float	space0;
	int		tmp;

	space = (HEIGHT / fdf->map->ordinate) * 0.3;
	space0 = (WIDTH / fdf->map->abscissa) *0.3;
	if (space > space0)
		fdf->space = space;
	else
		fdf->space = space0;
	if (fdf->map->altitude_max >= 50 || fdf->map->altitude_min <= -59)
		fdf->space =  6;
	else if(fdf->space < 1 )
		fdf->space = 2;
	fdf->dim->x1 = x;
	fdf->dim->y1 = y;
	
	fdf->dim->x1 *= fdf->space;
	fdf->dim->y1 *= fdf->space;
	tmp = fdf->dim->x1;
	rotate_z(fdf->dim, fdf->dim->x1, -fdf->dim->y1, 45);
	rotate_x(fdf->dim, -fdf->dim->y1, -z * fdf->space , 30);
	fdf->cnstx = (WIDTH / 2) - fdf->dim->x1 ;
	fdf->cnsty = (HEIGHT / 2) - fdf->dim->y1 ;
}
void	isometric(t_data *fdf, int x, int y, int z)
{
	int tmp;
	int scale;
	
	if (fdf->map->altitude_max > HEIGHT)
		scale = HEIGHT / 2;
	else 
		scale = 1;
	fdf->dim->x1 = x;
	fdf->dim->y1 = y;
	fdf->dim->x1 *= fdf->space;
	fdf->dim->y1 *= fdf->space;
	tmp = fdf->dim->x1;
	rotate_z(fdf->dim, fdf->dim->x1, -fdf->dim->y1, 45);
	rotate_x(fdf->dim, -fdf->dim->y1, -z * fdf->space , 30);
	fdf->dim->x1 += fdf->cnstx;
	fdf->dim->y1 += fdf->cnsty;
}

void draw_map(t_data *fdf)
{
    int x;
    int y;
    int color;
	int	z;
	int	center;
	int	temx;
	int	temy;

	temy = 0;
	temx = 0;
	center = 0;
	x = 0;
	y = 0;
	iso_center(fdf, fdf->map->abscissa / 2, fdf->map->ordinate / 2, fdf->map->matrix[fdf->map->ordinate / 2][fdf->map->abscissa / 2][0]);	
    while (y < fdf->map->ordinate)
    {
        x = 0;
        while (x < fdf->map->abscissa)
        {
			z = fdf->map->matrix[y][x][0];
			color = fdf->map->matrix[y][x][1];
			if(color == -1)
				color = 0xFFFFFF;
			temx = x + 1;
			temy = y + 1;
			if((x + 1) < fdf->map->abscissa)
			{
				isometric(fdf,x,y ,z);
				temx = fdf->dim->x1;
				temy = fdf->dim->y1;
				isometric(fdf,x + 1,y,fdf->map->matrix[y][x + 1][0]);
				bresenham(temx,temy, fdf->dim->x1 , fdf->dim->y1,fdf, color);
			}
			if((y + 1) < fdf->map->ordinate)
			{
				isometric(fdf,x,y,z);
				temx = fdf->dim->x1;
				temy = fdf->dim->y1;
				isometric(fdf,x,y + 1,fdf->map->matrix[y + 1][x][0]);
					bresenham(temx, temy, fdf->dim->x1, fdf->dim->y1, fdf, color);
			}
			x++;
        }
        y++;
    }
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
