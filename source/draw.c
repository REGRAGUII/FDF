/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yregragu <yregragu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 17:17:26 by yregragu          #+#    #+#             */
/*   Updated: 2024/07/30 12:59:33 by yregragu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"



// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->size_line + x * (data->bpp / 8));
// 	*(unsigned int*)dst = color;
// }




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
	int		angle;
	float	space;
	float	space0;
	int		tmp;

	space = (HEIGHT / fdf->map->ordinate) * 0.3;
	space0 = (WIDTH / fdf->map->abscissa) *0.3;

	if (space > space0)
		fdf->space = space;
	else
		fdf->space = space0;
	if(fdf->space < 1 )
		fdf->space = 2;
	else if (fdf->map->altitude_max >= 50 || fdf->map->altitude_min <= -59)
		fdf->space =  10;
	fdf->dim->x1 = x;
	fdf->dim->y1 = y;
	
	fdf->dim->x1 *= fdf->space;
	fdf->dim->y1 *= fdf->space;
	tmp = fdf->dim->x1;
	// fdf->dim->x1 = (tmp - fdf->dim->y1) * cos(0.523599);
	// fdf->dim->y1 = (tmp + fdf->dim->y1) * sin(0.523599) - z;
	rotate_z(fdf->dim, fdf->dim->x1, -fdf->dim->y1, 45);
	rotate_x(fdf->dim, -fdf->dim->y1, -z * fdf->space , 30);
	printf("space : %d\n cnsty : %d\n", fdf->space, fdf->cnsty);
	fdf->cnstx = (WIDTH / 2) - fdf->dim->x1 ;
	fdf->cnsty = (HEIGHT / 2) - fdf->dim->y1 ;
	printf("after cnstx : %d\n cnsty : %d\n", fdf->cnstx, fdf->cnsty);
	// fdf->dim->x1 = 0;
	// fdf->dim->y1 = 0;
	 
}
void	isometric(t_data *fdf, int x, int y, int z)
{
	int angle;
	float space;
	float space0;
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
	// fdf->dim->x1 = (tmp - fdf->dim->y1) * cos(0.523599);
	// fdf->dim->y1 = (tmp + fdf->dim->y1) * sin(0.523599) - z * scale ;
	rotate_z(fdf->dim, fdf->dim->x1, -fdf->dim->y1, 45);
	rotate_x(fdf->dim, -fdf->dim->y1, -z * fdf->space , 30);
	fdf->dim->x1 += fdf->cnstx;
	fdf->dim->y1 += fdf->cnsty;
	 
	// else
	// {
		// fdf->dim->x1 += (WIDTH / 2) - (fdf->map->abscissa * fdf->space / 2);
		// fdf->dim->y1 += (HEIGHT / 2) - (fdf->map->ordinate * fdf->space / 2);
	// }

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
			// x1 = x;
			// y1 = y;
			temx = x + 1;
			temy = y + 1;
			// temx = (temx * cos(rad(45)) - temy * sin(rad(45)));
			// temy  = (temx * sin(rad(45)) + temy * cos(rad(45)));
			// temy = (temy * sin(rad(30)) + z * cos(rad(30)));
			
			if((x + 1) < fdf->map->abscissa)
			{
				isometric(fdf,x,y ,z);
				temx = fdf->dim->x1;
				temy = fdf->dim->y1;
				isometric(fdf,x + 1,y,fdf->map->matrix[y][x + 1][0]);
				printf("from x : %d, y : %d  to x : %d , y %d \n\n",temx, temy, fdf->dim->x1, fdf->dim->y1);
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
			// mlx_pixel_put(fdf->mlx , fdf->win, x , y, color);
			// fdf->dim->x1 += 10  ;
			// fdf->dim->y1 += 10;
			// printf("x : %f || y : %f\n", x1, y1);
			
			// isometric(fdf, x, y, z);
			// my_mlx_pixel_put(fdf, fdf->dim->x1, fdf->dim->y1, color);
			// if (x == 2 )
            
			// mlx_pixel_put(fdf->mlx, fdf->win, fdf->dim->x1, fdf->dim->y1, color);
			// printf("x1 %f\n", fdf->dim->x1 );
			// printf("y1 %f\n", fdf->dim->y1);
			x++;
        }
        y++;
    }
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
}
