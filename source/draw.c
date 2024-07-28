/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:17:26 by yregragu          #+#    #+#             */
/*   Updated: 2024/07/28 23:52:05 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_line + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}




// void ft_cst(t_data *fdf)
// {
// 	int space;
// 	int space0;

	
// 	space = (HEIGHT / fdf->map->ordinate ) * 0.4;
// 	space0 = (WIDTH / fdf->map->abscissa ) * 0.4;
// 	if (space > space0)
// 		fdf->space = space;
// 	else
// 		fdf->space= space0;
// }
void	iso_center(t_data *fdf, int x, int y, int z)
{
	int angle;
	int space;
	int space0;

	space = (HEIGHT / fdf->map->ordinate) * 0.4;
	space0 = (WIDTH / fdf->map->abscissa) * 0.4;

	if (space > space0)
		fdf->space = space;
	else
		fdf->space = space0;
	if(fdf->space < 1 || fdf->map->altitude_max - fdf->map->altitude_min >= 20)
		fdf->space = 2;
	// if (fdf->map->altitude_max >= 60 || fdf->map->altitude_min <= -59)
		// fdf->space =  2;
	fdf->dim->x1 = x;
	fdf->dim->y1 = y;
	rotate_z(fdf->dim, fdf->dim->x1, -fdf->dim->y1, 45);
	rotate_x(fdf->dim, -fdf->dim->y1, -z , 30);
	fdf->dim->y1 *= fdf->space;
	fdf->dim->x1 *= fdf->space;
	fdf->cnstx = (WIDTH / 2) - fdf->dim->x1;
	fdf->cnsty = (HEIGHT / 2) - fdf->dim->y1;
	
}
void	isometric(t_data *fdf, int x, int y, int z)
{
	int angle;
	int space;
	int space0;

	
	fdf->dim->x1 = x;
	fdf->dim->y1 = y;
	
	rotate_z(fdf->dim, fdf->dim->x1, -fdf->dim->y1, 45);
	rotate_x(fdf->dim, -fdf->dim->y1, -z , 30);
	// else
	// {
		// fdf->dim->x1 += (WIDTH / 2) - (fdf->map->abscissa * fdf->space / 2);
		// fdf->dim->y1 += (HEIGHT / 2) - (fdf->map->ordinate * fdf->space / 2);
	// }
	fdf->dim->y1 *= fdf->space;
	fdf->dim->x1 *= fdf->space;
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

	center = 0;
	x = 0;
	y = 0;
	// ft_cst(fdf);
	// printf("%d\n", fdf->space);
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
			// printf("color is  %d \n",color);
			// mlx_pixel_put(fdf->mlx, fdf->win, x , y, color);
			isometric(fdf, x, y, z);
			// x1 = x;
			// y1 = y;
	
			// fdf->dim->x1 += 10  ;
			// fdf->dim->y1 += 10;
			// printf("x : %f || y : %f\n", x1, y1);
			if (fdf->dim->x1 > 0 && fdf->dim->y1 > 0 && (fdf->dim->x1 <= WIDTH && fdf->dim->y1 <= HEIGHT ))
				my_mlx_pixel_put(fdf, fdf->dim->x1, fdf->dim->y1, color);
			
            // mlx_pixel_put(fdf->mlx, fdf->win, fdf->dim->x1, fdf->dim->y1, color);
			// printf("x1 %f\n", fdf->dim->x1 );
			// printf("y1 %f\n", fdf->dim->y1);
			x++;
        }
        y++;
    }
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
